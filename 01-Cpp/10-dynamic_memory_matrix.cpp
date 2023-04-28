#include <iostream>
using namespace std;

// Para devolver una `matriz` se tiene que retornar 
// int**, esto debido a que al un arreglo se puede almacenar en
// int*, entonces para almacenar una `matriz` que corresponde a un puntero
// de donde cada posicion es un puntero a un arreglo. Por lo que, el tipo de 
// retorno debe ser int**.
//
// Para realizar esto, primero deberemos pedir memoria para almacenar un arreglo
// de punteros. Luego deberemos ir por cada puntero para pedir memoria para el 
// respectivo arreglo.
int** ret_matriz(int f, int c) {
  // int** almacena una direccin de memoria de int*
  // entonces se debe hacer new de int*
  int** m = new int*[f];
  for(int i = 0; i < f; i++) {
    // m[i] corresponde a un int*, entonces hay que pedir memoria para enteros
    m[i] = new int[c];
  }

  // Rellenemos la matriz con valores para probar
  for(int i = 0; i < f; i++) {
    for(int j = 0; j < c; j++) {
      // se almacena en la posicion j del arreglo i de la matriza i * j
      m[i][j] = i * j;
    }
  }

  return m;
}


// Hagamos una funcion que libere la memoria, como no podemos hacer
// delete[] m, porque perderiamos todos los punteros
//
// Deberemos liberar por partes, primero hacer delete por los punteros de 0..f
// y luego el puntero m
void free_matriz(int** m, int f) {
  for(int i = 0; i < f; i++) {
    delete[] m[i];
  }
  delete[] m;
}

int main() {
  int f = 3;
  int c = 6;
  int** ret = ret_matriz(f, c); 
  for(int i = 0; i < f; i++) {
    for(int j = 0; j < c; j++) {
      cout << ret[i][j] << " ";
    }
    cout << "\n";
  }

  free_matriz(ret, f);
  return 0;
}
