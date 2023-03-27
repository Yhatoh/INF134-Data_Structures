#include <iostream>
using namespace std;

// las funciones en C++ funcionan de la siguiente forma:
//   primero hay que escribir el elemento a retornar
//   el nombre de la funcion
//   sus parametros
// los parametros de esta forma son una copia de los parametros que les pasaron
// por lo tanto si los modificamos dentro de la funcion no se vera afectado
// en el main
int hace_algo(int a, float b) {
  a++; 
  a = a + 2;
  if(a > b) {
    return a;
  }

  return b;
}

// si es que queremos modificar una variable dentro de una funcion
// tenemos 2 formas:
//   1. por punteros
//   2. por referencia
void swap_punteros(int* a, int* b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void swap_referencias(int &a, int &b) {
  int aux = a;
  a = b;
  b = aux;
}

// los arreglos se puede pasar por punteros
// para pasar correctamente por parametro, se debe incluir el tamanio del arreglo
void array_con_zeros(int *arr, int n) {
  for(int i = 0; i < n; i++) {
    arr[i] = 0;
  }
}

// NO SE PUEDEN RETONAR ARREGLOS DE ESTA FORMA
// para eso necesitamos memorai dinamica
// si intentan usar esta funcion, altamente probable que se caiga
int* ret_array() {
  int arr[10];
  for(int i = 0; i < 10; i++) {
    arr[i] = 0;
  }
  return arr;
}

int main() {
  int x = 2;
  float y = 2.3;
  int ret = hace_algo(x, y);
  cout << "hace_algo(2, 2.3) " << ret << "\n";
  cout << "x = " << x << "\n";
  cout << "y = " << y << "\n";

  int var1 = 5;
  int var2 = 10;
  swap_punteros(&var1, &var2);
  swap_referencias(var1, var2);

  int arr[10];
  array_con_zeros(arr, 10);
  for(int i = 0; i < 10; i++) {
    cout << "arr[i] = " << arr[i] << "\n";
  }
  return 0;
}
