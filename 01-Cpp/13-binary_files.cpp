#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // los archivos binarios son distintos a los archivos de texto,
  // puesto lo que se almacena es la informacion en binario. No es tan facil
  // de leer esos archivos al ojo humano

  // los archivos binarios usan el mismo tipo de variable que los otros archivos
  // pero cambia la forma de escribir y leer
  fstream file;
  file.open("binario.dat", ios::binary | ios::out);

  // si quiero escribir un entero en el archivo, debo indicarle la direccion de memoria
  // y el tamano de la cosa que quiero escribir
  int x = 3;

  file.write((char*) &x, sizeof(int));

  // de esta forma escribi un entero en binario, luego si es que escribo otra cosa
  // ira pegada al entero

  float y = 2;
  file.write((char*) &y, sizeof(float));

  file.close();

  // Ahora, para leer del archivo binario, primero se debe abrir en modo lectura
  file.open("binario.dat", ios::binary | ios::in);

  int x2;
  float y2;

  // leer es la misma que escribir, pero utilizando es read
  file.read((char*) &x2, sizeof(int));
  file.read((char*) &y2, sizeof(float));

  file.close();


  cout << x2 << " " << y2 << "\n";
  return 0;
}
