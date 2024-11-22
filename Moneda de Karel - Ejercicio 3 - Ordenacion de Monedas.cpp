// Ejercicio: Ordenación de Monedas
// Este codigo es para ser ejecutado en: https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
using namespace std;

// Definición de la fila (1 = moneda/zumbador, 0 = vacío)
vector<int> fila = {0, 1, 1, 0, 0, 1, 1, 0};

// Posición inicial de Karel
int posicion = 0;

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

// Función para ordenar las monedas
void ordenarMonedas() {
    int monedasRecolectadas = 0; // Contador para monedas recogidas

    // Primera pasada: recoger todas las monedas
    while (posicion < fila.size()) {
        if (fila[posicion] == 1) {
            // Recoger moneda
            monedasRecolectadas++;
            fila[posicion] = 0;
            cout << "Karel recoge una moneda en la posición " << posicion << "." << endl;
        }
        // Avanzar a la siguiente posición
        posicion++;
        imprimirFila();
    }

    cout << "\nKarel ha recolectado todas las monedas: " << monedasRecolectadas << "." << endl;

    // Segunda pasada: colocar las monedas en posiciones correctas
    posicion = 0;
    while (monedasRecolectadas > 0 && posicion < fila.size()) {
        if (fila[posicion] == 0) {
            // Colocar moneda
            fila[posicion] = 1;
            monedasRecolectadas--;
            cout << "Karel coloca una moneda en la posición " << posicion << "." << endl;
        }
        // Avanzar a la siguiente posición
        posicion++;
        imprimirFila();
    }
}

// Función principal
int main() {
    cout << "Estado inicial de la fila:" << endl;
    imprimirFila();

    cout << "\nKarel comienza a ordenar las monedas..." << endl;
    ordenarMonedas();

    cout << "\nEstado final de la fila ordenada:" << endl;
    imprimirFila();

    return 0;
}
