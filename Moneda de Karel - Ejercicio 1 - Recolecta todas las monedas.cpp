// Ejercicio: Recolecta todas las monedas
// Este codigo es para ser ejecutado en: https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
using namespace std;

// Definición de la fila (1 = moneda/zumbador, 0 = vacío)
vector<int> fila = {1, 0, 1, 1, 0, 1, 0, 0};

// Posición inicial de Karel
int posicion = 0;

// Mochila de Karel para almacenar monedas recolectadas
int mochila = 0;

// Función para mostrar el estado de la fila
void imprimirFila() {
    for (int i = 0; i < fila.size(); i++) {
        if (i == posicion) {
            cout << "[K] ";
        } else if (fila[i] == 1) {
            cout << "M ";
        } else {
            cout << ". ";
        }
    }
    cout << endl;
}

// Función para que Karel recolecte monedas en la fila
void recolectarMonedas() {
    while (posicion < fila.size()) {
        // Verificar si hay moneda en la posición actual
        if (fila[posicion] == 1) {
            fila[posicion] = 0; // Recoger la moneda
            mochila++;          // Guardar en la mochila
            cout << "Karel recogió una moneda en la posición " << posicion << "." << endl;
        }
        // Avanzar a la siguiente posición
        posicion++;
        imprimirFila();
    }
}

// Función para que Karel regrese al inicio y deposite las monedas
void depositarMonedas() {
    while (posicion > 0) {
        posicion--; // Retroceder
        imprimirFila();
    }
    // Depositar todas las monedas en la primera casilla
    cout << "Karel depositó " << mochila << " monedas en la posición " << posicion << "." << endl;
    fila[posicion] += mochila;
    mochila = 0; // Vaciar mochila
}

// Función principal
int main() {
    cout << "Estado inicial de la fila:" << endl;
    imprimirFila();

    cout << "\nKarel comienza a recolectar monedas..." << endl;
    recolectarMonedas();

    cout << "\nKarel regresa al inicio para depositar las monedas..." << endl;
    depositarMonedas();

    cout << "\nEstado final de la fila:" << endl;
    imprimirFila();

    return 0;
}
