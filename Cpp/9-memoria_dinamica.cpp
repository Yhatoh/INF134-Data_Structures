#include <iostream>
using namespace std;

int* ret_array(int t) {
  int* arr = new int[t];
  for(int i = 0; i < t; i++) {
    arr[i] = i;
  }
  return arr;
}

void borrar_array(int* arr) {
  delete[] arr;
}

int main() {
  // para hace uso de la memoria del heap, se utiliza new
  // se puede pedir memoria para un tipo de dato y cuantos espacios necesitamos
  int n = 10;
  // el new siempre retorna un arreglo
  int* arr = new int[n];
  // la memoria no se elimina sola, por lo tanto existe el delete
  // este nos permite liberar la memoria
  delete[] arr;

  // ahora que tenemos la memoria dinamica, poder tener funciones que retornen
  // arreglos
  int* ret = ret_array(n);
  for(int i = 0; i < n; i++) {
    cout << "ret[" << i << "] = " << ret[i] << "\n";
  }
  borrar_array(ret);
  return 0;
}
