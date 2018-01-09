#ifndef PILA_MAX_COLA_H
#define PILA_MAX_COLA_H

#include <iostream>
#include "cola.hpp"
#include "elemento.hpp"

using namespace std;

class Pila_max_cola {

private:
    /**
      * @brief Rep de pila_max
      *
      * Guardamos los datos en una cola de tipo elemento
      * En este caso no hay invariante de la representación ya que
      * todo descansa en la clase cola
      *
      */
    Cola<elemento> datos;

public:

    /**
     * @brief Indica si la pila está vacia
     * @return Un valor booleano, true si la pila esta vacia, false si contiene
     * al menos un elemento
     */
    bool vacia() const {
        return datos.vacia();
    }

    /**
     * @brief Añade un elemento al final de la cola
     * @param elem Elemento que se va a añadir.
     */
    void poner(int valor);

    /**
     * @brief Quita el elemento del frente de la cola
     */
    void quitar();

    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos() const {
        return datos.num_elementos();
    }

    /**
     * @brief Devuelve el ultimo elemento de la pila
     * @return Un elemento
     */
    elemento tope();

};

void Pila_max_cola::quitar() {
    Cola<elemento> aux;

    int size = num_elementos() - 1;

    //Actualizamos los datos añadiendo a un aux todos salvo el ultimo, quitando este
    for (int i = 0; i<size; i++) {
        aux.poner(datos.frente());
        datos.quitar();
    }

    datos = aux;

}

elemento Pila_max_cola::tope() {
    Cola<elemento> aux = datos;

    elemento el = aux.frente();

    while (!aux.vacia()) {
        el.n = aux.frente().n;
        el.max = aux.frente().max;
        aux.quitar();
    }

    return el;
}

void Pila_max_cola::poner(int valor) {
    elemento nuevo;
    nuevo.n = valor;

    if (vacia()) {
        nuevo.max = valor;
    } else {
        elemento anterior = tope();
        nuevo.max = (valor > anterior.max) ? valor : anterior.max;
    }
    datos.poner(nuevo);
}

#endif
