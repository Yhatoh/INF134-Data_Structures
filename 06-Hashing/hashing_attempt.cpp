#include <iostream>
#include <math.h>

using namespace std;

#define M 100
#define VACIA -1
#define LIBERADA -2
#define R 2

typedef int tipoClave;

struct tipoInfo {
    int v; 
};

tipoInfo VALORINVALIDO;

struct ranura {
    tipoClave clave;
    tipoInfo info;
};

ranura HT[M];

int log_10(int num) {
	int cont = 0;
	while(num >= 10) {
		num /= 10;
		cont++;
	}
	return cont;
}

int h(int k) {
	int cuadrado = k * k;
	int largo = log_10(cuadrado) + 1;

	if(largo <= R) {
		return cuadrado;
	}

	int cuantos_borrar = ceil((largo - R) / 2.0);
	for(int i = 0; i < cuantos_borrar; i++) {
		cuadrado /= 10;
	}

	return cuadrado % 100;
}

int p(tipoClave k, int i) {
	return 47*i*i + 73*i + 79;
}

int hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
    int inicio, i;
    int pos = inicio = h(k);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++)
        pos = (inicio + p(k, i)) % M;  // próxima ranura en la secuencia
    if (HT[pos].clave == k)
        return 0;  // inserción no exitosa: clave repetida
    else {
        HT[pos].clave = k;
        HT[pos].info = I;
        return 1;  // inserción exitosa
    }
}

tipoInfo hashSearch(ranura HT[], tipoClave k) {
    int inicio, i;
    int pos = inicio = h(k);

    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++)
        pos = (inicio + p(k, i)) % M;  // próxima ranura en la secuencia
    
    if (HT[pos].clave == k)
        return HT[pos].info;   // registro encontrado, búsqueda exitosa
    else
        return VALORINVALIDO;  // Ejercicio: solucionar esto!
}

void init(ranura HT[]) {
	for(int i = 0; i < M; i++) {
		HT[i].clave = VACIA;
	}
}

void printValorNoVacio(ranura HT[]) {
	for(int i = 0; i < M; i++) {
		if(HT[i].clave != VACIA && HT[i].clave != LIBERADA) {
			cout << "clave: " << HT[i].clave << " " 
				 << "info: " << HT[i].info.v << "\n";
		}
	}
}

int main() {
	VALORINVALIDO.v = -1;
	init(HT);
	tipoClave clave = 4567;
	tipoInfo info;
	info.v = 245003;
	hashInsert(HT, clave, info);
	tipoClave clave2 = 1273;
	tipoInfo info2;
	info2.v = 21938746;
	hashInsert(HT, clave2, info2);
	tipoClave clave3 = 9871;
	tipoInfo info3;
	info3.v = 9287364;
	hashInsert(HT, clave3, info3);
	tipoClave clave4 = 1000;
	tipoInfo info4;
	info4.v = 1;
	hashInsert(HT, clave4, info4);
	tipoClave clave5 = 100;
	tipoInfo info5;
	info5.v = 2;
	hashInsert(HT, clave5, info5);
	printValorNoVacio(HT);
	cout << hashSearch(HT, 9871).v << "\n";

	return 0;
}