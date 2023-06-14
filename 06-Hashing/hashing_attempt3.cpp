#include <iostream>
#include <math.h>

using namespace std;

#define M 16666
#define VACIA "%"
#define LIBERADA "$"

typedef string tipoClave;

struct tipoInfo {
    string nombre_de_juego; 
};

tipoInfo VALORINVALIDO;

struct ranura {
    tipoClave clave;
    tipoInfo info;
};

ranura HT[M];

/*int h(tipoClave k) {
    int sum = 0;
    for(int i = 0; i < k.length(); i++) {
        sum += (k[i] * k[i]) / 3;
    }
    return sum % M;
}*/

int h(tipoClave k) {
    int sum = 0;
    for(int i = 0; i < k.length(); i++) {
        sum = (k[i] + sum * 1000) % M;
    }
    return sum % M;
}

int p(tipoClave k, int i) {
    return 7 * i * i + 3 * i + 11;
}

int hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
    int inicio, i;
    int pos = inicio = h(k);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != LIBERADA && HT[pos].clave != k; i++) {
        cout << k << " tuvo colision F\n";
        pos = (inicio + p(k, i)) % M;  // próxima ranura en la secuencia
    }
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
                 << "info: " << HT[i].info.nombre_de_juego << "\n";
        }
    }
}

int main() {
    VALORINVALIDO.nombre_de_juego = "";
    init(HT);
    tipoClave k = "Juanito El Gamer 777";
    tipoInfo i;
    i.nombre_de_juego = "roblox";
    hashInsert(HT, k, i);
    k = "MrYhatoh";
    i.nombre_de_juego = "Super Mario Sunshine";
    hashInsert(HT, k, i);
    k = "SniperXD";
    i.nombre_de_juego = "Col ov Duiti";
    hashInsert(HT, k, i);
    k = "ASDHAKSDHLA";
    i.nombre_de_juego = "lol";
    hashInsert(HT, k, i);
    k = "SnipXDer";
    i.nombre_de_juego = "Col ov Duiti 2";
    hashInsert(HT, k, i);
    printValorNoVacio(HT);
    return 0;
}