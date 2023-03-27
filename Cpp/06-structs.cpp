#include <iostream>
using namespace std;

// Un struct puede tener diversos campos, de diferentes tipos.
// La idea de utilizar struct es poder representar tipos de datos que consistan
// varios parametros
// Importante decir que los campos de un struct tambien se encuentran en memoria 
// contigua
struct arma {
  int danio;
  char sigla;
  float durabilidad;
};

int main() {
  // ahora puedo declarar variables del tipo del struct
  arma var;
  // para acceder a los campos de la variable, se utiliza el `.`
  var.danio = 2;
  var.sigla = 'A';
  var.durabilidad = 23.23;
  cout << "var.danio = " << var.danio << "\n";
  cout << "var.sigla = " << var.sigla << "\n";
  cout << "var.durabilidad = " << var.durabilidad << "\n";

  // cabe destacar que el struct solo define el compartamiento de una variable
  // nosotros podemos tener varias variables del mismo struct hasta podemos 
  // tener un arreglo de struct
  arma armas[10];
  for(int i = 0; i < 10; i++) {
    armas[i].danio = i;
    armas[i].sigla = 'A' + i;
    armas[i].durabilidad = i / 10;
  }

  for(int i = 0; i < 10; i++) { 
    cout << "armas[i].danio = " << armas[i].danio << "\n";
    cout << "armas[i].sigla = " << armas[i].sigla << "\n";
    cout << "armas[i].durabilidad = " << armas[i].durabilidad << "\n";
  }

  // Ahora, solo para demostrar que la memoria es contigua dentro de un struct,
  // imprimamos las direcciones de memoria correspondientes
  for(int i = 0; i < 10; i++) { 
    cout << "  &armas[i].danio = " << &armas[i].danio << "\n";
    // esto de aqui se debe realizar, porque como sabra mas adelante un puntero
    // a char es un string para C++, entonces para ver la direccion de memoria debemos 
    // castearlo a void
    cout << "&armas[i].sigla = " << (void*) &armas[i].sigla << "\n";
    cout << "&armas[i].durabilidad = " << &armas[i].durabilidad << "\n";
  }
  return 0;
}
