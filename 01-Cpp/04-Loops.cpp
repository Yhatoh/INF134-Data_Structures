#include <iostream>
using namespace std;

int main() {
  // Existen diferentes tipos de loops
  
  // While, que significa mientras la condicion sea verdadera, se realizara el 
  // codigo que se encuentra entre las llaves
  int x = 15;
  int count = 0;
  while(x > 0) {
    x -= 2;
    count++;
  }
  cout << count << "\n";
  // Este codigo calcula cuantas veces puedo restar 2 en x

  // Do-while, es casi lo mismo que el while, pero realiza el codigo dentro de 
  // las llaves al menos 1 vez
  int x2 = 0;
  int count2 = 0;
  do {
    x -= 2;
    count++;
  } while(x > 0);
  cout << count << "\n";
  // Este codigo calcula lo mismo que el codigo anterior, pero al usar un
  // do-while, si es que `x == 0`, entonces count valdrá 1 de todas formas
  
  // For, es un ciclo que itera, entonces este a diferencia de los otros dos
  // anteriores, se compone de 3 partes: asignacion inicial, condicion e incremento
  for(int i = 0; i < 10; i++) {
    cout << i << "\n";
  }
  // Este codigo mostrara por pantalla todos lo numeros entre 0 y 9. 
  // Recordar que el orden siempre es:
  //   1. Asignacion inicial
  //   2. Verifica si la condicion es verdadera
  //   3. Si condicion verdadera realiza lo que esta adentro
  //   4. Incrementa el valor y velve al paso 2.
  return 0;
}
