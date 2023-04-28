/* Enunciado
 * 
 * Se tiene un string con puros simbolois `(` y `)`, se dice que el string esta balanceado
 * si es todo abre parentesis tiene su respectio cierra parentesis y viceversa.
 *
 * Ejemplos buenos
 *   ((())()) este string esta balanceado puesto que todo abre parentesis tiene su cierra parentesis
 *   ()()()() este igual
 * Ejemplos malos
 *   ()), este string no esta balanceado puesto que el segundo cierra parentesis no tiene con quien cerrarse
 *   ((), este string no esta balanceado puesto que el primer abre parentesis no tiene su respectivo cierra parentesis
 *   )(, pueden deducir porque esta malo
 *
 * Solucion:
 *   ¡Pilas! 
 *   Si se ve bien los strings, se junta el ultimo abre parentesis con el primer cierra parentesis que se encuentre.
 *   Por lo tanto, por cada abre parentesis que veamos lo agregaremos a la pila. Si vemos un cierra parentesis haremos el siguiente
 *   checkeo:
 *     - Si en la pila no hay nada, entonces esta malo porque no hay un abre parentesis con quien cerrarse
 *     - Si la pila no esta vacia, entonces sacamos el abre parentesis que esta en el tope, puesto que lo cerrarremos con ese cierra parentesis
 *   Si terminamos de revisar el string y quedan cosas en la pila, significa que faltaron parentesis por revisar. Si esta vacia, ganamos
 */
bool check(String s) {
  // Creamos una variable tipo pila
  tPila pila;
  // recorreremos el string desde la posicion 0 hasta el final
  for(int i = 0; i < s.length(); i++) {
    // Si es un abre parentesis realizamos push
    if(s[i] == '(') pila.push('(');
    // Si es un cierra parentesis
    else {
      // Si hay cosas en la pila, sacamos el ultimo abre parentesis
      if(pila.size() > 0) pila.pop();
      // Si no hay nada retornamos falso
      else return false;
    }
  }
  // Si al terminar el for la pila no esta vacia, entonces retornamos falso
  if(pila.size() > 0) return false;
  // Si esta vacia retornamos verdadero
  else return true;
}
