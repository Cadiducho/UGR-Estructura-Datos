#ifndef VECTOR_DINAMICO_H
#define VECTOR_DINAMICO_H

#include <cassert>
/**
 *  @brief T.D.A. Vector_Dinamico
 *
 * Una instancia @e v del tipo de datos abstracto @c Vector_Dinamico sobre el
 * tipo @c float es un array 1-dimensional de un determinado tamaño @e n, que
 * puede crecer y decrecer a petición del usuario. Lo podemos representar como
 *
 *  {v[0],v[1],...,v[n-1]}
 *
 * donde  v[i] es el valor almacenado en la posición  i del vector
 *
 * La eficiencia en espacio es @e O(n).
 *
 *
 */
template <class T>
class Vector_Dinamico {
private:
    /**
       * @page repVector_Dinamico Rep del TDA Vector_Dinamico
       *
       * @section invVector_Dinamico Invariante de la representación
       *
       * Un objeto válido @e v del TDA Vector_Dinamico debe cumplir
       * - @c v.nelementos>= 0
       * - @c v.datos apunta a una zona de memoria con capacidad para albergar
       *   @c nelementos valores de tipo @c float
       *
       * @section faVector_Dinamico  Función de abstracción
       *
       * Un objeto válido @e rep del TDA Vector_Dinamico representa al vector de
       * tamaño @e n
       *
       * {v.datos[0],v.datos[1],...,v.datos[v.nelementos-1]}
       *
    */
    T * datos; /**< Apunta a los elementos del vector */
    int nelementos; /**< Indica el número de elementos en @c datos */
public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     * @param n indica el número de componentes inicial reservados
     *          para el vector
     */
    Vector_Dinamico(int n=0);
    Vector_Dinamico(const Vector_Dinamico& original);
    // ------------------ Destructor ------------------
    ~Vector_Dinamico();

    // --------------- Otras funciones ---------------
    /**
     * @brief Número de componentes del vector
     * @return Devuelve el número de componentes que puede almacenar en este
     * instante el vector
     */
    int size() const;

    /**
     * @brief Agrega un elemento T al vector
     * @param value Un elemento de tipo T. value != NULL
     */
    void add(T value);

    /**
     * @brief Elimina el ultimo elemento del vector dinámico
     */
    void delete_last();

    /**
     * @brief Acceso a un elemento
     * @param i la posición del vector donde está el componente. 0<=i<size()
     * @return La referencia al elemento. Por tanto, se puede usar para almacenar
     *     un valor en esa posición.
     */
    T& operator[] (int i);
    /**
     * @brief Acceso a un elemento de un vector constante
     * @param i la posición del vector donde está el componente. 0<=i<size()
     * @return La referencia al elemento. Se supone que el vector no se puede
        modificar y por tanto es acceso de sólo lectura
     */
    const T& operator[] (int i) const;
    /**
     * @brief Redimensión del vector
     * @param n El nuevo tamaño del vector. n>=0
     * @post Los valores almacenados antes de la redimensión no se pierden
     *  (excepto los que se salen del nuevo rango de índices)
     */
    void resize(int n);
    Vector_Dinamico& operator= (const Vector_Dinamico& original);
};


template <class T>
Vector_Dinamico<T>::Vector_Dinamico(int n) {
    assert(n>=0);
    if (n>0)
        datos= new T[n];
    nelementos= n;
}

template <class T>
Vector_Dinamico<T>::Vector_Dinamico(const Vector_Dinamico& original) {
    nelementos= original.nelementos;
    if (nelementos>0) {
        datos= new T[nelementos];
        for (int i=0; i<nelementos;++i)
            datos[i]= original.datos[i];
    }
    else datos=0;
}
template <class T>
Vector_Dinamico<T>::~Vector_Dinamico() {
    if (nelementos>0) delete[] datos;
}

template <class T>
int Vector_Dinamico<T>::size() const {
    return nelementos;
}

template <class T>
T& Vector_Dinamico<T>::operator[] (int i) {
    assert (0<=i && i<nelementos);
    return datos[i];
}

template <class T>
const T& Vector_Dinamico<T>::operator[] (int i) const {
    assert (0<=i && i<nelementos);
    return datos[i];
}

template <class T>
void Vector_Dinamico<T>::resize(int n) {
    assert (n>=0);
    if (n!=nelementos) {
        if (n!=0) {
            T * nuevos_datos;
            nuevos_datos= new T[n];
            if (nelementos>0) {
                int minimo;
                minimo= nelementos<n?nelementos:n;
                for (int i= 0; i<minimo;++i)
                    nuevos_datos[i]= datos[i];
                delete[] datos;
            }
            nelementos= n;
            datos= nuevos_datos;
        }
        else {
            if (nelementos>0)
                delete[] datos;
            datos= 0;
            nelementos= 0;
        }
    }
}

template <class T>
void Vector_Dinamico<T>::add(T value) {
    resize(nelementos+1);
    datos[nelementos-1] = value;
}

template <class T>
void Vector_Dinamico<T>::delete_last() {
    resize(nelementos-1);
}

template <class T>
Vector_Dinamico<T>& Vector_Dinamico<T>::operator= (const Vector_Dinamico<T>& original) {
    if (this!= &original) {
        if (nelementos>0) delete[] datos;
        nelementos= original.nelementos;
        datos= new T[nelementos];
        for (int i=0; i<nelementos;++i)
            datos[i]= original.datos[i];
    }
    return *this;
}

#endif
