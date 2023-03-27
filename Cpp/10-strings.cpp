#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
  // existen dos formas de utilizar strings en C++
  //   1. arreglos de char
  //   2. string

  // los arreglos de char cuando almacenan un string
  // se agrega al final un `\0`, esto debido que es la forma de C++
  // para saber donde termina el string
  char fecha[11] = "1999-02-12";
  cout << fecha << "\n";

  // los arreglos de char pueden tener mayor del string que puede almacenar
  char arr[123];
  // esta funcion permite copiar un arreglo de char a otro
  // igualar directamente no se pueden hacer, porque son punteros
  strcpy(arr, fecha);
  cout << arr << "\n";

  // aqui se observara que el largo del string no corresponde al largo del arreglo
  cout << "largo del string " << strlen(arr) << "\n";

  // concatena el string de fecha en el arr
  strcat(arr, fecha);
  cout << arr << "\n";

  // para poder comprar dos string en arreglos de char, se debe hacer uso de 
  // strcmp
  if(strcmp(arr, fecha) == 0) {
    cout << "Son iguales\n";
  } else { 
    cout << "No son iguales\n";
  }

  char* ch = strchr(arr, '-');
  cout << *ch << "\n";

  // string es un objeto de C++ que permite manejar con mayor flexibilidad los 
  // strings
  string s = "hola soy un string";

  // de esta forma podemos juntar dos strings
  cout << s + s << "\n";
  // de esta forma podemos saber el largo de un string
  cout << s.length() << "\n";

  if(s.empty()) {
    cout << "s es un string vacio\n";
  } else {
    cout << "s no es un string vacio\n";
  }

  // asi podemos acceder/modificar un caracter de un string
  s[2] = '2';
  cout << s << "\n";

  string s2 = "hola soy otro string";
  if(s2 == s) {
    cout << "Son iguales\n";
  } else {
    cout << "No son iguales\n";
  }

  // gracias a string podemos buscar no solo caracteres sino que tambien
  // otro string dentro
  // si no se encuentra el caracter o el string retorna el maximo largo de un string 
  cout << "Posicion donde se encuentra una s " << s.find('s') << "\n";
  cout << "Posicion donde comienza `soy` en el string s " << s.find("soy") << "\n";
  return 0;
}
