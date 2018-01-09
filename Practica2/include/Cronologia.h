#ifndef _CRONOLOGIA_H_
#define _CRONOLOGIA__H

#include <iostream>
#include <string>
#include "Fecha_Historica.h"

using namespace std;

class Cronologia {

private:
   int neventos;
   int reservados;
   Fecha_Historica *event;

   void resize(int r);
   void ordenar();

public:
  Cronologia();
  Cronologia(Fecha_Historica *eh, int n);
  Cronologia(const Cronologia& c);

  ~Cronologia() {
     neventos=0;
     reservados=0;
     delete[] event;
  }

  void aniadirEvento(Fecha_Historica& eh);
  int buscarAnio(int f);
  Cronologia buscarEventos(string s);

  friend ostream& operator<< (ostream& os, const Cronologia& c);
  friend istream& operator>> (istream& is, Cronologia& c);

};

#endif
