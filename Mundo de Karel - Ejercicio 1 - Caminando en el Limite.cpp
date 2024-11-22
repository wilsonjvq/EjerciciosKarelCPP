// Ejercicio: Caminando en el Limite
// Este codigo es para ser ejecutado en: https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
using namespace std;

// Simulamos las acciones de Karel
class Karel {
public:
    int x, y; // Posicion de Karel
    bool frenteClaro() { // Verificamos si Karel puede mover hacia adelante
        // Si Karel esta en el limite de la cuadrícula
        if (x == 5 && y == 0) { // Límite inferior
            return false; 
        }
        if (x == 0 && y == 5) { // Límite superior
            return false;
        }
        return true;
    }

    void mover() { // Karel se mueve hacia adelante
        if (y < 5 && x == 0) {
            y++; // Mueve hacia arriba
        }
        else if (x < 5 && y == 5) {
            x++; // Mueve hacia la derecha
        }
        else if (x == 5 && y > 0) {
            y--; // Mueve hacia abajo
        }
        else if (x > 0 && y == 0) {
            x--; // Mueve hacia la izquierda
        }
    }

    void girarIzquierda() { // Gira 90 grados a la izquierda
        // Cambia la direccion de Karel
    }

    void mostrarPosicion() {
        cout << "Posicion de Karel: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Karel karel;
    karel.x = 0; // Posicion inicial en la esquina inferior izquierda
    karel.y = 0;

    // Bucle para mover a Karel alrededor del borde de la cuadrícula 5x5
    while (karel.x < 5 || karel.y < 5) {
        karel.mostrarPosicion(); // Muestra la posicion de Karel
        karel.mover(); // Karel avanza
        if (karel.x == 5 || karel.y == 5) {
            break; // Rompe el ciclo si Karel ha recorrido todo el borde
        }
    }

    cout << "Karel ha recorrido el borde de la cuadrícula 5x5." << endl;
    return 0;
}
