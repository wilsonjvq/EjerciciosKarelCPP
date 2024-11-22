// Ejercicio: Encuentra la Puerta
// Este codigo es para ser ejecutado en: https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
using namespace std;

// Definición del mundo de Karel (1 = pared, 0 = camino libre)
vector<vector<int>> mundo = {
    {1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1}};

// Posición inicial y orientación de Karel
int x = 2, y = 0; // Entrada frente a la pared
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
    if (direccion == 0) ny++;
    else if (direccion == 1) nx++;
    else if (direccion == 2) ny--;
    else if (direccion == 3) nx--;
    return mundo[nx][ny] == 0;
}

// Función para avanzar
void move() {
    if (frontIsClear()) {
        if (direccion == 0) y++;
        else if (direccion == 1) x++;
        else if (direccion == 2) y--;
        else if (direccion == 3) x--;
    }
}

// Función principal para encontrar y cruzar la puerta
void encontrarPuerta() {
    cout << "Estado inicial del mundo:" << endl;
    imprimirMundo();

    // Avanza hasta encontrar la puerta
    while (!frontIsClear()) {
        y++; // Mueve a Karel a lo largo de la pared
        imprimirMundo();
    }

    // Cruza la puerta
    move();
    imprimirMundo();

    cout << "¡Karel ha cruzado la puerta!" << endl;
}

int main() {
    encontrarPuerta();
    return 0;
}
