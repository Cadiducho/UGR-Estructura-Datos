#include <iostream>
#include "AVL.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
  AVL<int> avl;
  AVL<int> avl2;
  AVL<int>::iterator it;
  AVL<int> unionavl;
  AVL<int> interseccion;
  int e;

  cout << "INSERCIÓN DE DATOS" << endl;

  cout << "Introduce un entero para AVL 1 (<0 para terminar) ";
  cin >> e;
  while(e>=0){
    avl.insertar(e);
    for(it = avl.begin(); it != avl.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl.Esquema();

    cout << "Introduce un entero AVL 1 (<0 para terminar) ";
    cin >> e;
  }

  cout << "Introduce un entero para AVL 2 (<0 para terminar) ";
  cin >> e;
  while(e>=0){
    avl2.insertar(e);
    for(it = avl2.begin(); it != avl2.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl2.Esquema();

    cout << "Introduce un entero AVL 2 (<0 para terminar) ";
    cin >> e;
  }

//  const int N = 50;
//  const float max = 100.0;
//  srand(time(NULL));
//  for(int i=0; i<N; i++)
//    avl.insertar((int) (max*rand()/RAND_MAX));
//
//
//  for(it = avl.begin(); it!=avl.end(); ++it)
//    cout << *it << " ";
//  cout << endl;
//
//  avl.Esquema();
/*
  cout << "BÚSQUEDA DE DATOS" << endl;
  cout << "Introduce un entero (< 0 para terminar) ";
  cin >> e;
  while(e>=0){
    cout << e << (avl.existe(e)? " SÍ" : " NO") << " está en el AVL" << endl;
    cout << "Introduce un entero (< 0 para terminar) ";
    cin >> e;
  }

  avl.Esquema();
  cout << "BORRADO DE DATOS" << endl;
  cout << "Introduce un entero (< 0 para terminar) ";
  cin >> e;
  while(e>=0){
    avl.borrar(e);
    for(it = avl.begin(); it!=avl.end(); ++it)
      cout << *it << " ";
    cout << endl;
    avl.Esquema();

    cout << "Introduce un entero (< 0 para terminar) ";
    cin >> e;
}*/

  for (it = avl.begin(); it != avl.end(); ++it) {
    if (!unionavl.existe(*it))
      unionavl.insertar(*it);
  }
  for (it = avl2.begin(); it != avl2.end(); ++it) {
    if (!unionavl.existe(*it))
      unionavl.insertar(*it);
  }
  cout << "Esquema de la union" << endl;
  unionavl.Esquema();

  for (it = avl.begin(); it != avl.end(); ++it) {
    if (avl2.existe(*it))
      interseccion.insertar(*it);
  }
  cout << "Esquema de la interseccion" << endl;
  interseccion.Esquema();

  return 0;
}
