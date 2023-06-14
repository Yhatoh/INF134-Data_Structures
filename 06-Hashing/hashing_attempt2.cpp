#include <iostream>

using namespace std;

#define M 16666
#define VACIA " "
#define LIBERADA "$"

typedef string tipoClave;

struct tipoInfo {
    string clave_privada;
};

tipoInfo VALORINVALIDO;

struct ranura {
    tipoClave clave;
    tipoInfo info;
};

ranura HT[M];

void init(ranura HT[]) {
    for(int i = 0; i < M; i++) {
        HT[i].clave = VACIA;
    }
}

/*int h(tipoClave k) {
    int sum = 0;
    for(int i = 0; i < k.length(); i++) {
        sum += (int) k[i];
    }
    return sum % M;
}*/

int h(tipoClave k) {
    int sum = 0;
    int pow_11 = 1;
    for(int i = 0; i < k.length(); i++) {
        sum = (((int) (k[i] * pow_11)) % M + sum + M) % M;
        pow_11 *= 11;
    }
    return sum % M;
}

int p(tipoClave k, int i) {
    return 7 * i * i + 17 * i + 47;
}

int hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
    int inicio, i;
    int pos = inicio = h(k);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++) {
        cout << k << " hizo colision\n";
        pos = (inicio + p(k, i)) % M; // próxima ranura en la secuencia
    }
    if (HT[pos].clave == k)
        return 0; // inserción no exitosa: clave repetida
    else {
        HT[pos].clave = k;
        HT[pos].info = I;
        return 1; // inserción exitosa
    }
}

tipoInfo hashSearch(ranura HT[], tipoClave k) {
    int inicio, i;
    int pos = inicio = h(k);
    for (i = 1; HT[pos].clave != VACIA && HT[pos].clave != k; i++)
        pos = (inicio + p(k, i)) % M; // próxima ranura en la secuencia

    if (HT[pos].clave == k)
        return HT[pos].info; // registro encontrado, búsqueda exitosa
    else
        return VALORINVALIDO; // Ejercicio: solucionar esto!
}

void printValorNoVacio(ranura HT[]) {
    for(int i = 0; i < M; i++) {
        if(HT[i].clave != VACIA && HT[i].clave != LIBERADA) {
            cout << "clave: " << HT[i].clave << " " 
                 << "info: " << HT[i].info.clave_privada << "\n";
        }
    }
}

int main() {
    VALORINVALIDO.clave_privada = " ";
    init(HT);
    tipoClave k = "embajador";
    tipoInfo i;
    i.clave_privada = "B0mb4 Nu21345";
    hashInsert(HT, k, i);
    k = "asdlijasd";
    i;
    i.clave_privada = "discretasXD";
    hashInsert(HT, k, i);
    k = "Grande el prestigio";
    i;
    i.clave_privada = "prestigioposting";
    hashInsert(HT, k, i);
    k = "jadoremba";
    i;
    i.clave_privada = "Viva la paz";
    hashInsert(HT, k, i);

    cout << hashSearch(HT, "embajador").clave_privada << "\n";
    cout << hashSearch(HT, "asdlijasd").clave_privada << "\n";
    cout << hashSearch(HT, "Grande el prestigio").clave_privada << "\n";
    
    cout << "Diccionario\n";
    printValorNoVacio(HT);
    return 0;
}