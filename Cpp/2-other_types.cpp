#include <iostream>
using namespace std;

int main() {
  // Tipo de dato caracter, este corresponde a un caracter, ej. 'A', 'B', '(', etc.
  // Este tipo de datos se almacena como un entero segun el codigo ASCII
  // Si quieres revisar los valores de cada caracter en ASCII, revisar: https://elcodigoascii.com.ar
  char a = 'a';
  cout << "a = " << a << "\n";

  char A = 'A';
  cout << "A = " << A << "\n";

  // Al trabajar con el codigo ASCII, podemos realizar los siguiente trucos
  int ascii_A = A;
  cout << "ascii_A = " << ascii_A << "\n";
  // Deberiamos ver en pantalla 65
  
  // El valor ASCII de `a` es 97, si es que le sumo 1 da 98. El 98 corresponde a
  // `b` en ASCII, por lo que ahora si imprimimos la variable deberiamos ver una `b`
  a++;
  cout << "a = " << a << "\n";

  // El tipo de dato booleano, corresponde a verdadero y falso, para C++ cualquier numero
  // que no sea 0, es verdadero
  bool falso = false;
  cout << "falso = " << falso << "\n";
  // De hecho, deberiamos ver un 0 en pantalla
  bool verdadero = true;
  cout << "verdadero = " << verdadero << "\n";
  // Ahora deberiamos ver un 1 en pantalla
  bool intento = 123;
  cout << "intento = " << intento << "\n";
  // Como se dijo arriba, deberiamos ver un 1 en pantalla. Dado que todo numero no 0
  // es verdadero
  return 0;
}
