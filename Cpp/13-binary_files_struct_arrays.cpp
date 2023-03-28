#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct persona {
  int edad;
  float vida;
};

int main() {
  fstream file;
  file.open("struct.dat", ios::out | ios::binary);

  // Uno pensaria que para guardar un struct en un archivo binario, deberia
  // ir campo por campo y luego para leer debemos leer campo por campo
  //
  // Pero, no! podemos guardarlo directamente debido a que como guardamos binarios
  // y la memoria en los struct es contigua, podemos hacerlo directamente
  //
  // OJO!: la otra forma tambien esta bien, pero la otra es as rapida

  persona p;
  p.edad = 12;
  p.vida = 32.23;

  // Escribimos de la misma forma, pero sizeof del struct correspondiente
  file.write((char*)&p, sizeof(persona));

  file.close();

  file.open("struct.dat", ios::in | ios::binary);

  persona p2;
  file.read((char*)&p2, sizeof(persona));

  cout << p.edad << " " << p.vida << "\n";
  file.close();

  // Esto mismo podemos hacerlo con los arreglos, pero con una pequena diferencia
  // en el sizeof se entrega el espacio en bytes de 1 cosa, pero un arreglo almacena
  // n cosas, entonces se debe multiplicar el sizeof por n

  int n = 3;
  persona* arr = new persona[n];

  file.open("array.dat", ios::out | ios::binary);

  // se va a rellenar todo a mano, porque sino es poco customizable
  arr[0].edad = 12;
  arr[0].vida = 12.123;

  arr[1].edad = 10;
  arr[1].vida = 15.123;

  arr[2].edad = 1212;
  arr[2].vida = 0.12312;

  // primero se debe guardar la cantidad de cosas a guardar, porque sino
  // en otro programa al menos que siempre sepamos que es un arreglo de tamanio
  // 3, no podemos adivinar cuantas cosas estan escritas
  file.write((char*)&n, sizeof(int));
  // ahora guardamos el arreglo
  file.write((char*)arr, sizeof(persona) * n);

  delete[] arr;
  file.close();

  // Ahora intentemos leerlo
  file.open("array.dat", ios::in | ios::binary);

  int n2;
  // primero leemos la cantidad de elementos en el arreglo
  file.read((char*)&n2, sizeof(int));

  persona* arr2 = new persona[n2];
  file.read((char*)arr2, sizeof(persona) * n2);
  
  cout << n2 << "\n";
  // veamos si leyo bien
  for(int i = 0; i < n2; i++) {
    cout << arr2[i].edad << " " << arr2[i].vida << "\n";
  }
  
  delete[] arr2;
  file.close();

  return 0;
}
