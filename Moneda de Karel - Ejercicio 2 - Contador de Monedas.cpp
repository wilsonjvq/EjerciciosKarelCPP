// Ejercicio: Contador de Monedas
// Este codigo es para ser ejecutado en: https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
using namespace std;

// Definición de la fila (1 = moneda/zumbador, 0 = vacío)
vector<int> fila = {1, 0, 1, 1, 0, 1, 0, 1};

// Posición inicial de Karel
int posicion = 0;

// Contador de monedas recolectadas
int contador = 0;

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

// Función para contar monedas en la fila
void contarMonedas() {
    while (posicion < fila.size()) {
        // Verificar si hay moneda en la posición actual
        if (fila[posicion] == 1) {
            contador++; // Incrementar el contador
            cout << "Karel encontró una moneda en la posición " << posicion << "." << endl;
        }
        // Avanzar a la siguiente posición
        posicion++;
        imprimirFila();
    }
}

// Función para colocar monedas en una columna al final de la fila
void colocarMonedas() {
    posicion--; // Mover a la última posición
    imprimirFila();
    cout << "Karel coloca " << contador << " monedas en la última posición de la fila." << endl;

    // Colocar monedas en una columna visual
    for (int i = 0; i < contador; i++) {
        cout << "[K]" << string(fila.size() - 1, ' ') << " M" << endl;
    }
}

// Función principal
int main() {
    cout << "Estado inicial de la fila:" << endl;
    imprimirFila();

    cout << "\nKarel comienza a contar monedas..." << endl;
    contarMonedas();

    cout << "\nKarel coloca las monedas contadas en una columna al final de la fila..." << endl;
    colocarMonedas();

    return 0;
}
