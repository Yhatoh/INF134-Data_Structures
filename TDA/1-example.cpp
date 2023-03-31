#include <iostream>
#include <string>
using namespace std;

// Gracias a la palabra class, nosotros podemos crear un tipo de dato abstracto
// la idea es que puedan representar a traves de un conjunto de datos y operaciones
// una cosa sea de la vida real o algo inventado
// La idea es que este encapsule el comportamiento y solo se piense en que esta
// hecho y no el como esta hecho
class Personaje {
  // Estos son los campos privados, solo la clase puede acceder directamente
  // los programadores no
  private:
    string name;
    int vida;
    float danio;
    int posicion;
    bool esta_vivo; 
  // Estos son los elementos publicos, todos pueden acceder a estos
  public:
    // Estos corresponden a los contructores
    //   * Primero tenemos el contructor vacio, significa que no recibe parametros
    //     al momento que declaramos una variable
    //   * Segundo tenemos otro constructo que recibe un string como parametro
    //     al momento de declarar la variable
    // Un TDA puede tener diferentes constructores con tal que tenga distintos
    // parametros basta
    // El constructor la idea es setear los campos de manera default
    Personaje();
    Personaje(string name_);
    // Este es el destructor, este llama al momento que una variable vaya a morir
    // esto nos va a ser util cuando usemo memoria dinamica
    ~Personaje();

    // Ahora vamos a declarar ciertas operaciones que podria tener el personaje
    int hacer_danio();
    void recibir_danio(int danio_);
    void hablar(int op);
    void avanzar();
    void retroceder();

    // Como los campos estan en el privado, si es que queremos que el usuario 
    // acceda los campos, deben ser a traves de operaciones, esto se atravese de 
    // algo que se conoce como getters
    // Lo mismo si es que nosotros queremos modificar los campos, esto se atraves 
    // de operaciones que se llaman setters
    //
    // Para este caso particular no quiero que el usuario modifique los campos, 
    // por lo que no crearemos setters;
    string get_name();
    int get_vida();
    float get_danio();
    int get_posicion();
    bool get_esta_vivo();
};

// Vamos a hacer que el constructor vacio, ponga solo los vamores default
Personaje::Personaje() {
  name = "default";
  vida = 10;
  danio = 5.123;
  posicion = 0;
  esta_vivo = true;
}

// Como este constructor tiene un parametro, corresponde al nombre del personaje
Personaje::Personaje(string name_) {
  name = name_;
  vida = 10;
  danio = 5.123;
  posicion = 0;
  esta_vivo = true;
}
  
// esta es una funcion que no hace nada
Personaje::~Personaje() {}

int Personaje::hacer_danio() {
  // si en algun punto alquien quisiera llegar a cambiar el como hacer danio, 
  // solo debe cambiar esta funcion, en el main jamás veremos el cambio
  // return danio * posicion;
  return danio * vida;
}

// si el danio lo deja con vida negativa o zero, entonces el personaje muere
void Personaje::recibir_danio(int danio_) {
  vida -= danio_;
  if(vida <= 0) {
    esta_vivo = false;
    vida = 0;
  }
}

// Dire tres opciones el valor de `op`
void Personaje::hablar(int op) {
  if(op == 1) {
    cout << name << ": " << " Hola!\n";
  } else if(op == 2) {
    cout << name << ": " << " Muerte\n";
  } else {
    cout << name << ": " << " ...\n";
  }
}

void Personaje::avanzar() {
  posicion++;
}

void Personaje::retroceder() {
  posicion--;
  if(posicion <= 0) {
    posicion = 0;
  }
}

string Personaje::get_name() { return name; }
int Personaje::get_vida() { return vida; }
float Personaje::get_danio() { return danio; }
int Personaje::get_posicion() { return posicion; }
bool Personaje::get_esta_vivo() { return esta_vivo; }
  
int main() {
  // Declaro una variable usando el constructor vacio
  Personaje p;
  cout << p.get_name() << "\n";
  // Ahora declaro otra variable usando el constructo que recibe el string
  Personaje p2("Thor El PepeitosDestructor");

  // Ahora podemos usar las operaciones de nuestros personaje
  cout << p.hacer_danio() << "\n";

  p.avanzar(); p.avanzar(); p.avanzar();
  cout << p.get_posicion() << "\n";
  p.retroceder(); p.retroceder();
  p.retroceder(); p.retroceder();
  cout << p.get_posicion() << "\n";
  // Cada campo de la clase es `unico` de cada variable, entonces
  // al verse modificado p, no afecto a p2
  cout << p2.get_posicion() << "\n";

  p2.recibir_danio(100);
  cout << p2.get_esta_vivo() << "\n";
  return 0;
}
