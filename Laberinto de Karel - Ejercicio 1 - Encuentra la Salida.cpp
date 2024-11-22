// Ejercicio: Encuentra la Salida
// Este codigo es para ser ejecutado en: https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
using namespace std;

// Definición del laberinto (1 = pared, 0 = camino libre)
vector<vector<int>> laberinto = {
    {1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1}};

// Posición inicial y orientación de Karel
int x = 1, y = 1; // Entrada del laberinto
int direccion = 0; // 0: derecha, 1: abajo, 2: izquierda, 3: arriba

// Coordenadas de la salida
int salidaX = 4, salidaY = 4;

// Función para mostrar el estado del laberinto
void imprimirLaberinto() {
    for (int i = 0; i < laberinto.size(); i++) {
        for (int j = 0; j < laberinto[i].size(); j++) {
            if (i == x && j == y) {
                cout << "[K] ";
            } else if (laberinto[i][j] == 1) {
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
    return laberinto[nx][ny] == 0;
}

// Función para verificar si la derecha está despejada
bool rightIsClear() {
    int nx = x, ny = y;
    if (direccion == 0) nx++;
    else if (direccion == 1) ny--;
    else if (direccion == 2) nx--;
    else if (direccion == 3) ny++;
    return laberinto[nx][ny] == 0;
}

// Función para girar a la derecha
void turnRight() {
    direccion = (direccion + 1) % 4;
}

// Función para girar a la izquierda
void turnLeft() {
    direccion = (direccion + 3) % 4;
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

// Función principal para encontrar la salida
void encontrarSalida() {
    cout << "Laberinto inicial:" << endl;
    imprimirLaberinto();

    while (!(x == salidaX && y == salidaY)) {
        if (rightIsClear()) {
            turnRight();
            move();
        } else if (frontIsClear()) {
            move();
        } else {
            turnLeft();
        }
        imprimirLaberinto();
    }
    cout << "¡Karel ha encontrado la salida!" << endl;
}

int main() {
    encontrarSalida();
    return 0;
}
