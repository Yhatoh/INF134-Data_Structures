class Texto {
  private:
    char lineas[1000][1000];
    int cant_lineas;
  public:
    // te entrega la cantidad de lineas del texto
    int get_cant_lineas();
    // te entrega la linea `i` del texto
    char* get_linea(int i);
    // te entrega el caracter `j` de la linea `i` del texto
    char* get_char_linea(int i, int j);
};

// Dado el TDA presentado, escriba una funcion `comparar` que reciba dos variables de tipo texto,
// que retorna un arreglo de enteros donde en la posicion `i` se almacena la cantidad de caracteres 
// distintos de la linea `i` entre los dos textos.

int* comparar(Texto t1, Texto t2) {
  // su codigo
}
