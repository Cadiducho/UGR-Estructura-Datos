#include <iostream>

#include "../include/pila_max_cola.hpp"
#include "../include/pila_max_vd.hpp"

using namespace std;

int main() {
    cout << "Pila max hecha con Colas: " << endl;
    Pila_max_cola pc;

    for (int i = 10; i >= 0; i--) {
        pc.poner(i);
    }
    while (!pc.vacia()) {
        elemento x = pc.tope();
        cout << x << endl;
        pc.quitar();
    }

    cout << "Pila max hecha con Vector Dinamico: " << endl;
    Pila_max_vd vd;

    for (int i = 20; i >= 10; i--) {
        vd.poner(i);
    }
    while (!vd.vacia()) {
        elemento x = vd.tope();
        cout << x <<endl;
        vd.quitar();
    }
    return 0;
}