#include <iostream>
using namespace std;

struct test {
  int i;
};

int main() {
  // Puntero es una variable que en vez de almacenar un valor, almacena
  // la direccion de memoria en donde se encuentra un valor
  // Los punteros siempre apuntan a un tipo de dato, por ejemplo puntero a entero
  // puntero a flotante, etc
  int* p;
  int i = 0;
  p = &i;
  // Ahora, p esta apuntando a la variable i. Para acceder al valor que apunta p
  // se debe hacer uso de `*`
  cout << "valor apuntado por p = " << *p << "\n";
  
  *p = *p + 2;
  cout << "i = " << i << "\n";
  // como p apunta a i, entonces si modificamos lo que apunta p, tambien veremos eso
  // en la variable i

  // tambien podemos hacer punteros a struct
  test* t;
  test var;
  t =  &var;
  // para acceder a los campos del struct se puede hacer de dos formas
  (*t).i = 0;
  // pero tambien utilizando la flecha
  t->i = 2;

  // si van al codigo 5-arrays.cpp, veran que la variable del arreglo es una direccion
  // de memoria por lo que podemos igualar esa variable a un punto
  int arr[10];
  int* p_arr;
  for(p_arr = arr; p_arr < arr + 10; p_arr++) {
    *p_arr = 1;
  }
  
  for(p_arr = arr; p_arr < arr + 10; p_arr++) {
    cout << "*p_arr (arr[i]) = " << *p_arr << "\n";
  }
  return 0;
}
