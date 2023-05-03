/* Enunciado
 * 
 * Se tiene una fila de personas con un carrito de compras. Las personas quieren pagas sus compras
 * cada persona tiene un tiempo `t` para ser atendidos por un cajero. Existen tres cajeros. 
 * ¿Quieres saber cuanto es el tiempo mínimo para que todas las personas puedan pagar sus compras?
 *
 * Ejemplo:
 *   p1 se demora 3 segundos
 *   p2 se demora 5 segundos
 *   p3 se demora 4 segundos
 *   p4 se demora 2 segundos
 *   p5 se demora 2 segundos
 *   p6 se demora 1 segundos
 *   
 *   La respuesta sería: 6 segundos el tiempo en atender todos
 *
 * Solución:
 *   Como los tres cajeros están libres, mandaremos a las tres primeras personas en la fila a cada 
 *   cajero. Luego, la siguiente persona será el que tenga el cajero con menor tiempo acumulado.
 *
 *   Por ejemplo:
 *     C1 = p1
 *     C2 = p2
 *     C3 = p3
 *
 *     Luego, como p1 es menor que todos entonces p4 lo mandamos al cajero C1
 *
 *     Dando,
 *     C1 = p1 + p4
 *     C2 = p2
 *     C3 = p3
 *
 *     Luego, p5 lo mandamos al cajero C3
 *
 *     Dando,
 *     C1 = p1 + p4
 *     C2 = p2
 *     C3 = p3 + p5
 *
 *     Finalmente, p6 podría ser enviado tanto al cajero C1 como C2
 *
 *     Dando
 *     C1 = p1 + p4
 *     C2 = p2 + p6
 *     C3 = p3 + p5
 *
 *     Por lo tanto el tiempo mínimo es la suma máxima
 */

int tiempo_minimo(Queue personas) {
  // estado inicial de los cajeros
  int C1 = 0;
  int C2 = 0;
  int C3 = 0;

  while(personas.size() > 0) {
    if(C1 < C2 && C1 < C3) {
      C1 += personas.front();
    } else if(C2 < C1 && C2 < C3) {
      C2 += personas.front();
    } else {
      C3 += personas.front();
    }
    personas.dequeue();
  }
  return max(C1, max(C2, C3));
}
