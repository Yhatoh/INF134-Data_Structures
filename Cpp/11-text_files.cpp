#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // archivo de entraga (lectura)
  ifstream fin;
  // archivo de salida (escritura)
  ofstream fout;
  // archivo tanto entrada como salida
  fstream file;

  // ambas formas son equivalentes, puesto que `fin` es un archivo solo de lectura
  // y `file` no se sabe, entonces al usar `ios::in` se sabe que `file` es de lectura
  fin.open("archivo.txt");
  fin.close();
  file.open("archivo.txt", ios::in);
  file.close();

  file.open("archivo.txt", ios::in);
  // si el archivo de lectura no se pudo abrir porque no existe o alguna otra razon
  // file.is_open() retornara falso
  if(!file.is_open()) {
    cout << "Error al abrir el archivo\n";
    exit(1);
  } else {
    cout << "El archivo se abrio correctamente\n";
  }
  
  // para leer del archivo, primero se debe saber que esta escrito, sino no hay forma de leer
  // el archivo
  // por ejemplo digamos que en archivo.txt esta escrito `2 hola 3`
  // nosotros podemos leerlo de la siguiente forma
  int x;
  file >> x;
  cout << x << "\n";
  
  string s;
  file >> s;
  cout << s << "\n";

  file >> x;
  cout << x << "\n";

  file.close();

  // ahora abramos un archivo para escribir en el
  file.open("escribir.txt", ios::in);
  // si el archivo no existe C++ crea un archivo vacio
  // si el archivo existe C++ borra todo el contenido del archivo
  
  // para escribir en el archivo es igual que usar `cout`, pero dentro del archivo
  file << "x = " << x << "\n";
  file << "s = " << s << "\n";

  file.close();


  // DATO FREAK
  // si el `cout` es para imprimir por consola
  // el `cin` es para leer por consola
  
  int x2;
  cin >> x2; // de esta forma leeremos un entero

  string s2;
  cin >> s2;

  cout << x2 << " " << s2 << "\n";
  // la lectura tanto en ambos casos ignora los espacios y saltos de linea
  // cuando por ejemplo queremos leer una variable de entero, busca el primer elemento
  // que no sea un espacio y lo intenta almacenar en la variable
  return 0;
}
