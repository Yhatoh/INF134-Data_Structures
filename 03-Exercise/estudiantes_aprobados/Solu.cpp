struct Estudiante {
  char rut[11];
  int c1;
  int c2;
  int c3;
};

// Enunciado
// Escriba una funcion llamada `aprobados` que reciba el nombre de un archivo binario
// que contiene un entero `n`, luego le siguen `n` structs `Estudiante`. Su función debe 
// retornar un arreglo de `Estudiante`, que contenga a todos los estudiantes que aprobaron
// el curso. Para saber si estudiante aprobo su promedio de los certamenes debe ser mayor o igual
// a 54.45

// primer detalle importante agregar el parametro que indique el tamaño del arreglo
Estudiante* aprobados(string nombre_archivo, int &t) {
  fstream file;
  // se abre el archivo en modo lectura y en modo binario
  file.open(nombre_arch, ios::in | ios::binary);

  // se lee el entero `n` descrito
  int n;
  file.read((char*)&n, sizeof(int));

  // se pide memoria para almacenar `n` `Estudiante`
  Estudiante *arr = new Estudiante[n];
  // se lee los `n` `Estudiantes`
  file.read((char*)arr, sizeof(Estudiante) * n);

  // recordar cerrar el archivo
  file.close();

  // creo un arreglo del tamanio maximo posible
  Estudiante *res = new Estudiante[n];

  // creo una variable count, para guardar los estuidantes de mantera contigua
  int count = 0;
  for(int i = 0; i < n; i++) {
    int num = arr[i].c1 + arr[i].c2 + arr[i].c3;
    float promedio = num / 3.0;
    if(promedio >= 54.45) {
      res[count] = arr[i];
      count++;
    }
  }
  
  // modificop el valor de t
  t = count;
  // creo un arreglo mas chico para almacenar la respuesta real
  Estudiante *ret = new Estudiante[count];
  for(int i = 0; i < count; i++) {
    ret[i] = res[i];
  }

  // se elimina la memoria dinamica pedida y que no es util
  delete[] arr;
  delete[] res;

  return ret;

}
