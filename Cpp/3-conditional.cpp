#include <iostream>
using namespace std;

int main() {
  // En este condicional, se prueba que dos numeros sean iguales
  int x = 3;
  int y = 2;
  if(x == y) {
    cout << "Son iguales\n";
  }

  // Se puede escribir lo mismo, pero agregandole un `else` para indicar el caso contrario
  if(x == y) {
    cout << "Son iguales\n";
  } else {
    cout << "No son iguales\n";
  }

  // Si se quiere probar varias opciones, se puede seguir anidando `if` y `else`
  // Se verifica que x sea mayor a y
  if(x > y) {
    cout << "x es mayor que y\n";
  // Si no es mayor, entonces se verifica que sea menor
  } else if(x < y) {
    cout << "x es menor que y\n";
  // Si tampoco es mayor, entonces significa que son iguales
  } else {
    cout << "son iguales\n";
  }
  return 0;
}
