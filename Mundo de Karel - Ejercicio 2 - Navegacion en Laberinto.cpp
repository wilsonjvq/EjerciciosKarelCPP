// Ejercicio: Navegacion en Laberinto
// Este codigo es para ser ejecutado en: https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Laberinto simulado (0 = espacio libre, 1 = pared)
vector<vector<int>> laberinto = {
    {0, 1, 0, 0},
    {0, 1, 0, 1},
    {0, 0, 0, 0},
    {0, 1, 1, 0}
};

// Posición de Karel (inicia en la esquina superior izquierda)
int posX = 0, posY = 0;

// Conjunto para registrar posiciones visitadas
set<pair<int, int>> visitadas;

// Funciones para los movimientos de Karel
bool puede_moverse(int x, int y) {
    return x >= 0 && y >= 0 && x < laberinto.size() && y < laberinto[0].size() && laberinto[x][y] == 0;
}

bool esta_en_salida() {
    return posX == laberinto.size() - 1 && posY == laberinto[0].size() - 1;
}

// Movimiento principal de Karel
bool resolver_labirinto(int x, int y) {
    // Si Karel está en la salida
    if (esta_en_salida()) {
        cout << "¡Karel ha encontrado la salida en la posición: (" << x << ", " << y << ")!" << endl;
        return true;
    }

    // Marcar la posición actual como visitada
    visitadas.insert({x, y});
    cout << "Posicion de Karel: (" << x << ", " << y << ")" << endl;

    // Intentar moverse en las cuatro direcciones: abajo, derecha, arriba, izquierda
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nuevoX = x + dx[i];
        int nuevoY = y + dy[i];

        if (puede_moverse(nuevoX, nuevoY) && visitadas.find({nuevoX, nuevoY}) == visitadas.end()) {
            // Moverse a la nueva posición
            posX = nuevoX;
            posY = nuevoY;
            if (resolver_labirinto(nuevoX, nuevoY)) {
                return true;
            }
        }
    }

    // Retroceder si no hay más movimientos posibles
    cout << "Retrocediendo desde: (" << x << ", " << y << ")" << endl;
    return false;
}

int main() {
    // Resolver el laberinto comenzando desde la posición inicial
    if (!resolver_labirinto(0, 0)) {
        cout << "No se encontró una solución al laberinto." << endl;
    }
    return 0;
}