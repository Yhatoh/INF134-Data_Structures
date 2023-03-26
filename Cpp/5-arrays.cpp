#include <iostream>
using namespace std;

int main() {
  // Los arreglos corresponden a un conjunto de elementos que estan contiguos en memoria
  // Solo se puede almacenar un tipo de dato en cada arreglo
  // Yo puedo tener arreglos de enteros, flotantes, etc.
  // Ademas, los arrreglos tienen tamanio fijo hasta el final del programa
  // Si el arreglo tiene tamanio n, entonces las posiciones del arreglo son entre 0 y n - 1
  int arr[10];
  // De esta forma yo puedo almacenar cosas en los arreglos.
  arr[0] = 1;
  arr[1] = 3;
  arr[2] = 4;

  // De la misma forma, podemos obtener lo guardado en un arreglo
  int x = arr[1];
  cout << "x = " << x << "\n";
  cout << "arr[1] = " << arr[1] << "\n";

  // Si tu intentas acceder a una posicion que no es del arreglo, pueden suceder cosas no desadas
  //cout << arr[12] << "\n";

  // Tambien podemos hacer eso de los ciclos para recorrer mas comodamente los arreglos
  for(int i = 0; i < 10; i++) {
    arr[i] = i;
  }
  
  for(int i = 0; i < 10; i++) {
    cout << "arr[" << i << "] = " << arr[i] << "\n";
  }

  // Ahora, si ustedes intentan lo siguiente
  cout << arr << "\n";
  // No se va a imprimir el arreglo completo, sino que la direccion de memoria de donde esta 
  // almacenado el comiezno del arreglo
  
  // Para mostrar que en efecto es memoria contigua haremos uso del operador &, que nos entrega la direccion
  // de memoria de una variable
  // Dato curioso: &arr[0] == arr
  for(int i = 0; i < 10; i++) {
    cout << "&arr[" << i << "] = " << &arr[i] << "\n";
  }

  // Dado, que son enteros los saltos en la memoria seran de tamano 4 bytes, si nosotros ponemos otro tipo de dato
  // podriamos ver saltos mas grandes o mas pequeño
  long long int arr_long[10];
  for(int i = 0; i < 10; i++) {
    cout << "&arr_long[" << i << "] = " << &arr_long[i] << "\n";
  }
  // Aqui vamos a ver saltos de tamanio 8 bytes

  return 0;
}
