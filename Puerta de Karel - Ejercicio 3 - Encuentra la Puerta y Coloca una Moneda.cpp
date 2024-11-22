// Ejercicio: Encuentra la Puerta y Coloca una Moneda
// Este codigo es para ser ejecutado en: https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
using namespace std;

// Definición del mundo de Karel (1 = pared, 0 = espacio libre)
vector<vector<int>> mundo = {
    {1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}};

// Posición inicial de Karel
int x = 1, y = 0; // Karel comienza en la segunda fila, primera columna
int direccion = 0; // 0: derecha, 1: abajo, 2: izquierda, 3: arriba

// Función para mostrar el estado del mundo
void imprimirMundo() {
    for (int i = 0; i < mundo.size(); i++) {
        for (int j = 0; j < mundo[i].size(); j++) {
            if (i == x && j == y) {
                cout << "[K] ";
            } else if (mundo[i][j] == 1) {
                cout << "# ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Función para verificar si el frente está despejado
bool frontIsClear() {
    int nx = x, ny = y;
    if (direccion == 0) ny++; // Dirección derecha
    else if (direccion == 1) nx++; // Dirección abajo
    else if (direccion == 2) ny--; // Dirección izquierda
    else if (direccion == 3) nx--; // Dirección arriba
    return mundo[nx][ny] == 0;
}

// Función para mover a Karel
void move() {
    if (frontIsClear()) {
        if (direccion == 0) y++; // Mover a la derecha
        else if (direccion == 1) x++; // Mover abajo
        else if (direccion == 2) y--; // Mover a la izquierda
        else if (direccion == 3) x--; // Mover arriba
    }
}

// Función para colocar una moneda (zumbador)
void putBeeper() {
    cout << "Karel coloca una moneda en la casilla de entrada" << endl;
}

// Función principal para encontrar la puerta y colocar una moneda
void encontrarYColocarMoneda() {
    cout << "Estado inicial del mundo:" << endl;
    imprimirMundo();

    // Mover a Karel hasta encontrar la puerta (espacio libre)
    while (!frontIsClear()) {
        move(); // Mueve Karel hacia adelante
        imprimirMundo();
    }

    // Coloca una moneda en la posición de entrada antes de cruzar
    putBeeper();

    // Cruza la puerta
    move();
    cout << "Karel ha cruzado la puerta." << endl;
    imprimirMundo();
}

int main() {
    encontrarYColocarMoneda();
    return 0;
}
