#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Imprime un conjunto de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: el conjunto con los elementos a imprimi
 * */
template <class T>
ostream & operator<<(ostream & s, const set<T> & c){

  typename set<T>::const_iterator i;

  for (i=c.begin(); i != c.end(); i++)
      s << (*i) << " ";

  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/
void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/
int generaEntero(int min, int max){
    int tam= max -min+1;
    return ((rand()%tam)+min);
}

set<int> intersection(set<int> a, set<int> b, set<int> c) {
    set<int> intersec;
    set<int>::const_iterator it;
    for (it = a.begin(); it != a.end(); it++) {
        if ((b.count(*it) > 0) && (c.count(*it) > 0)) {
            intersec.insert(*it);
        }
    }
    return intersec;
}

set<int> unionsimetrica(set<int> a, set<int> b, set<int> c) {
    set<int> unsimetrica(a);
    unsimetrica.insert(b.begin(), b.end());
    unsimetrica.insert(c.begin(), c.end());
    set<int>::const_iterator it;
    for (it = unsimetrica.begin(); it != unsimetrica.end(); it++) {
        if (((a.count(*it) > 0) && (b.count(*it) > 0) && (c.count(*it) <= 0)) //está en A y B pero no C
          || ((b.count(*it) > 0) && (c.count(*it) > 0) && (a.count(*it) <= 0)) //está en B y C pero no A
          || ((c.count(*it) > 0) && (a.count(*it) > 0) && (b.count(*it) <= 0))) { //está en C y A pero no B
            unsimetrica.erase(*it);
        }
    }
    return unsimetrica;
}

int main(){

  InicializarSemilla();

  set<int> a;
  set<int> b;
  set<int> c;
/*
  int vA[] = {1, 2, 4, 5, 8};
  int vB[] = {4, 5, 6, 9};
  int vC[] = {3, 4, 7, 8, 9};

  a.insert(vA, vA+5);
  b.insert(vB, vB+4);
  c.insert(vC, vC+5);*/

  for (int i=0;i<5;i++) {
    a.insert(generaEntero(1, 100));
    b.insert(generaEntero(1, 100));
    c.insert(generaEntero(1, 100));
  }

  cout << "Set a: " << a << endl;
  cout << "Set b: " << b << endl;
  cout << "Set c: " << c << endl;


  cout << "Set interseccion: " << intersection(a, b, c) << endl;

  cout << "Set union simetrica: " << unionsimetrica(a, b, c) << endl;
}
