#ifndef PILA_MAX_VD_H
#define PILA_MAX_VD_H


#include <iostream>
#include "vector_dinamico.hpp"
#include "elemento.hpp"

using namespace std;

class Pila_max_vd {

private:
    /**
      * @brief Rep de pila_max
      *
      * Guardamos los datos en un vector_dinamico de tipo elemento
      * En este caso no hay invariante de la representación ya que
      * todo descansa en la clase vector_dinamico
      *
      */
    Vector_Dinamico<elemento> datos;

public:

    /**
     * @brief Indica si la pila está vacia
     * @return Un valor booleano, true si la pila esta vacia, false si contiene
     * al menos un elemento
     */
    bool vacia() const {
        return (datos.size() == 0);
    }

    /**
     * @brief Añade un elemento al final de la cola
     * @param elem Elemento que se va a añadir.
     */
    void poner(int valor);
    /**
     * @brief Quita el elemento del frente de la cola
     */

    void quitar() {
        datos.delete_last();
    };

    /**
     * @brief Devuelve el número de elementos de la cola
     */
    int num_elementos() const {
        return datos.size();
    }

    /**
     * @brief Devuelve el ultimo elemento de la pila
     * @return Un elemento
     */
    elemento tope();

};

elemento Pila_max_vd::tope() {
    if (num_elementos() > 0) {
        return datos[num_elementos() - 1];
    }
    elemento error;
    error.max = -1;
    error.n = -1;
    return error;
}

void Pila_max_vd::poner(int valor) {
    elemento nuevo;
    nuevo.n = valor;

    if (vacia()) {
        nuevo.max = valor;
    } else {
        elemento anterior = tope();
        nuevo.max = (valor > anterior.max) ? valor : anterior.max;
    }

    datos.add(nuevo);
}

#endif
