// Ejercicio: Patrullaje en Cuidad
// Este codigo es para ser ejecutado en: https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
using namespace std;

// Definición de la cuadrícula (0 = limpio, 1 = basura)
vector<vector<int>> ciudad = {
    {0, 1, 0, 0},
    {1, 0, 1, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 0}
};

// Posición inicial de Karel
int posX = ciudad.size() - 1; // Fila inferior izquierda
int posY = 0;                // Columna izquierda

// Función para imprimir el estado de la cuadrícula
void imprimir_ciudad() {
    for (int i = 0; i < ciudad.size(); i++) {
        for (int j = 0; j < ciudad[0].size(); j++) {
            cout << (ciudad[i][j] == 1 ? "B " : ". ");
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

// Función para patrullar y limpiar la ciudad
void patrullar_ciudad() {
    int filas = ciudad.size();
    int columnas = ciudad[0].size();
    bool hacia_derecha = true; // Dirección de patrullaje

    for (int fila = filas - 1; fila >= 0; fila--) {
        if (hacia_derecha) {
            // Patrullaje hacia la derecha
            for (int col = 0; col < columnas; col++) {
                posX = fila;
                posY = col;

                // Si hay basura, recogerla
                if (ciudad[posX][posY] == 1) {
                    ciudad[posX][posY] = 0;
                    cout << "Karel recogió basura en (" << posX << ", " << posY << ")" << endl;
                }
            }
        } else {
            // Patrullaje hacia la izquierda
            for (int col = columnas - 1; col >= 0; col--) {
                posX = fila;
                posY = col;

                // Si hay basura, recogerla
                if (ciudad[posX][posY] == 1) {
                    ciudad[posX][posY] = 0;
                    cout << "Karel recogió basura en (" << posX << ", " << posY << ")" << endl;
                }
            }
        }

        // Cambiar dirección para la siguiente fila
        hacia_derecha = !hacia_derecha;
    }
}

// Función principal
int main() {
    cout << "Estado inicial de la ciudad:" << endl;
    imprimir_ciudad();

    cout << "Karel comienza el patrullaje..." << endl;
    patrullar_ciudad();

    cout << "Estado final de la ciudad:" << endl;
    imprimir_ciudad();

    cout << "Karel ha regresado a su punto de inicio: (" << posX << ", " << posY << ")" << endl;

    return 0;
}