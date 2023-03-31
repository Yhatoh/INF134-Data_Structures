#include <iostream>
using namespace std;

// Vamos a crear una clase Racional, que nos servira para ilustrar respecto al
// uso de los TDA y de como para el programador no deberia importar la implementacion
// solo que funcione
// 
// Descomentar las cosas un arreglo, para que vean que no tuve que modificar nada en el main
// solo en las funciones del TDA
class Racional {
  private:
    // int frac[2];
    int _den;
    int _num;
  public:
    Racional();
    Racional(int num, int den);
    // vamos a crear una funcion que sirva para hacer `=`
    void igual(Racional r);
    // hagamos la operacion multiplicar racionales
    // o sea que haga la operacion r1 * r2
    // r1 no se haga por parametro, puesto que cuando uno hace
    // r1.multiplicar(r2), los campos de r1 ya se encuentran desde la funcion
    Racional multiplicar(Racional r2);
    int get_num();
    int get_den();
    void print();
};

Racional::Racional() {}
Racional::Racional(int num, int den) {
  // frac[0] = num;
  // frac[1] = den;
  _num = num;
  _den = den;
}

void Racional::igual(Racional r) {
  // frac[0] = r.get_num();
  // frac[1] = r.get_den();
  _num = r.get_num();
  _den = r.get_den();
}

Racional Racional::multiplicar(Racional r2) {
  // Racional r3(frac[0] * r2.get_num(),
  //             frac[1] * r2.get_den());
  Racional r3(_num * r2.get_num(),
              _den * r2.get_den());
  return r3;
}

int Racional::get_num() { 
  // return frac[0];
  return _num; 
}
int Racional::get_den() {
  // return frac[1];
  return _den; 
}

void Racional::print() {
  cout << get_num() << " / " << get_den() << "\n";
}

int main() {
  Racional r1(2, 3);
  Racional r2(4, 5);
  Racional r3;
  // En este caso r1.multiplicar(r2)
  // _num seria igual a 2 y r2.get_num() seria igual a 4
  // _den seria igual a 3 y r2.get_den() seria igual a 5
  r3.igual(r1.multiplicar(r2));
  // En este caso r2.multiplicar(r1)
  // _num seria igual a 4 y r2.get_num() seria igual a 2
  // _den seria igual a 5 y r2.get_den() seria igual a 4
  r3.igual(r2.multiplicar(r1));
  r3.print();

  return 0;
}
