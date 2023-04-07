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

// nunca olvidar el tamanio del arreglo utilizando un parametro por referencia
int* comparar(Texto t1, Texto t2, int &t) {
  // se obtendra quien tiene la mas lineas y el que tiene las menos lineas
  int max_lineas = max(t1.get_cant_lineas(), t2.get_cant_lineas());
  int min_lineas = min(t1.get_cant_lineas(), t2.get_cant_lineas());

  // crearemos un arreglo de tamanio `max_lineas` puesto que esa es la mayor cantidad de lineas a comparar
  int* res = new int[max_lineas];
  t = max_lineas;

  // Ahora solo nos importa comparar las primeras 0 hasta min_lineas - 1. puesto que esas son las unicas lineas 
  // a comparar
  
  for(int i = 0; i < min_lineas; i++) {
    // obtenemos la linea `i` de ambos textos
    char* l_t1 = t1.get_linea(i);
    char* l_t2 = t2.get_linea(i);

    // se obtiene el largo mas grande y el largo mas chico
    int l_chica = min(strlen(l_t1), strlen(l_t2));
    int l_grande = max(strlen(l_t1), strlen(l_t2));

    // ahora recorreremos las posiciones entre 0 hasta l_chica - 1 y ver cuales son los caracteres distintos
    // se crea una variable para almacenar la cantidad de caracteres distintos
    int distintos = 0;
    for(int j = 0; j < l_chica; j++) {
      if(l_t1[j] != l_t2[j]) {
        distintos++;
      }
    }
    // se suma todos los caracteres que posee una linea por ser mas grande que la otra
    distintos += l_grande - l_chica;
    res[i] = distintos;
  }

  // Ahora se suma todos los caracteres de las lineas que tiene un texto y que no tiene el otro
  if(t1.get_cant_lineas() == max_lineas) {
    // la ultima linea comparada fue la linea en la posicion `min_lineas - 1`
    for(int i = min_lineas; i < max_lineas; i++) {
      // aqui la cantidad de caracteres distintos es el largo de la linea
      res[i] = strlen(t1.get_linea(i));
    }
  } else {
    for(int i = min_lineas; i < max_lineas; i++) {
      // aqui la cantidad de caracteres distintos es el largo de la linea
      res[i] = strlen(t2.get_linea(i));
    }
  }

  return res;
}
