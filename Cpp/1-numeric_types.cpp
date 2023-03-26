#include <iostream>
using namespace std;

int main() {
  // Tipo de dato entero, contiene solo números enteros entre
  // [-2^31, 2^31 - 1]
  int num = 123;
  // Tipo de dato entero, pero cubre una mayor cantidad de enteros
  // este tipo de dato cubre entre [-2^64, 2^64 - 1] 
  long long int num_grande = 10000000000;

  cout << "num = " << num << "\n";
  cout << "num_grande = " << num_grande << "\n";

  // Unsigned es una palabra que modifica el tipo numero a unicamente positivos
  // Para el caso de los `int`, el rango de numeros es ahora [0, 2^32 - 1]
  // Para el caso de los `long long`, el rango de numeros es ahora [0, 2^64- 1]
  unsigned long long int positivo = 123;
  // Si intentan guardar un numero negativo, C++ va a ignorar que es un numero negativo
  // y lo va guardar tal cual tiene los bits, provocando cosas que uno no esperaria
  unsigned long long int negativo_raro = -1;
  
  cout << "positivo = " << positivo << "\n";
  cout << "negativo_raro = " << negativo_raro << "\n";

  // Dato curioso, en este caso negativo raro va a ser equivalente al mayor entero
  // positivo representable que corresponde a 2^64 - 1

  // Tipo de dato flotante, corresponde a los decimales, o sea no necesariamente
  // enteros
  float con_coma = 232.231;
  // Pero tambien puede almacenar "enteros", solo que se guardan como X.0
  float entero = 2;
  // Por ejemplo, aqui estas guardando un 2, pero por detras es un 2.0
  cout << "con_coma = " << con_coma << "\n";
  cout << "entero = " << entero << "\n";
  
  // Si guardo en una variable de tipo entero una variable de tipo entero
  // este se trunca
  int truncado = con_coma;
  cout << "truncado = " << truncado << "\n";
  // Deberiamos ver por pantalla 232, no 232.231

  // Tipo de dato double, corresponde a los decimales, pero cubre un mayor rango
  double mas_rango = 12312.213123;
  cout << "mas_rango = " << mas_rango << "\n";

  return 0;
}
