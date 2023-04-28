#include <iostream>
#include "tLista.hpp"

using namespace std;

/* Enunciado
 *
 * Existe un Browser Chino llamado Adventurer Explorer, este navegador debe tener
 * las siguientes funcionalidades:
 *   - Recibir Link: debe recibir link y agregarlo al final del historial, se debe eliminar todo lo que este adelante
 *     en caso de que no este al final
 *   - Volver Atras: debe poder volver atras en el historial
 *   - Volver Adelante: debe volver hacia adelante en el historial
 *   - Moverse hasta una posicion `i`: debe moverse a la posición `i`del historial
 *     y borrar todo lo que este adelante de ese link
 *   - Mostrar link actual
 *
 * Para resolver esto, haremos uso del TDA de Listas y vamos a almacenar char* dentro de la lista
 *
 * Para el programa haremos el siguiente mapeo de opciones:
 *   - op == 1, es la opcion recibir link
 *   - op == 2, es la opcion de volver atras
 *   - op == 3, es la opcion de volver adelante
 *   - op == 4, es la opcion de moverse a una posicion particular
 *   - op == 5, es la opcion de mostrar el link
 *   - op == 6, es una opcion extra para terminar el programa
 *
 * ¿Qué lista usar? 
 *   Se debe usar lista basada en arreglos, esto se debe principalmente por la opcion numero 2 y 4
 *   la cual nos obliga a movernos a una opcion particular, en esta implementacion seria facil moverse
 *   porque acceso al `prev` de un eelemento tiene complejidad O(1). En cambio, ena lista enlazada tiene 
 *   complejidad O(n)
 *
 *  Este codigo esta implementado de tal forma que no tendremos que modificar NADA de la implementación de Lista
 *  para agregar los arreglos de char, PERO importante recalcar que la memoria se debe borrar en el main
 *  o sea tengan cuidado
 */
int main() {
  // Leemos la primera opcion por la consola
  int op;
  cin >> op;
  tLista list;
  while(op != 6) {
    if(op == 1) {
      // declaramos una variable de tipo char* para almacenar el link que se va a recibir
      char str[STRING_SIZE];
      cin >> str;

      // este pedazo de codigo nos sirve porque si agregamos algo al final y no estamos en la pos final
      // debemos borrar todo lo que este al frente
      int i = list.curr_pos();
      list.move_to_end();
      list.prev();
      while(list.curr_pos() > (unsigned int) i) {
        t_elem_list aux = list.erase();
        // eliminamos la memoria puesto que el erase no hace el trabajo por nosotros
        // esto es para no tener que modificar la implementacion del erase, puesto que es algo particular
        // del tipo del elemento
        delete[] aux;
        list.prev();
      }
      // se pide memoria para almacenar el string dentro de la Lista
      char* to_append = new char[STRING_SIZE];
      strcpy(to_append, str);
      // realizamos append
      list.append(to_append);
      // despues de hacer append, movemos el curr si es la lista no es de tamanio 1
      // esto porque el curr no se mueve con el append y nosotros siempre queremos ver el ultimo ingresado
      if(list.length() > 1) {
        list.next();
      }
    } else if(op == 2) {
      // gracias a que tenemos prev es directo
      list.prev();
    } else if(op == 3) {
      // debemos checkear si es que no estamos en el ultimo elemento, para no movernos al end
      if(list.curr_pos() < list.length() - 1) {
        list.next();
      }
    } else if(op == 4) {
      // recibimos la posicion que nos queremos mover
      int i;
      cin >> i;
      // nos movemos al final y hacemos prev para posicionarnos en el ultimo elemento
      list.move_to_end();
      list.prev();
      // eliminamos todo el historia que haya entre el ultimo elemento y la posicion que nos vamos a mover
      // todo esto por la descripcion del problema
      while(list.curr_pos() >  (unsigned int) i) {
        t_elem_list aux = list.erase();
        delete[] aux;
        list.prev();
      }
    } else if(op == 5) {
      // se obtiene el link actual en que uno esta
      cout << list.get_value() << "\n";
    }
    cin >> op;
  }

  // como no modificados el TDA para eliminar la memoria, tenemos que acordarnos de borrar todos los nodos que
  // queden con memoria flotando que requiera ser eliminada antes de llamar al destructor
  for(list.move_to_start();  (unsigned int) list.curr_pos() < list.length(); list.next()) {
    t_elem_list aux = list.get_value();
    delete[] aux;
  }
  return 0;
}
