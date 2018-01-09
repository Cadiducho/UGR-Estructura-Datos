#ifndef _FECHA_HISTORICA_H_
#define _FECHA_HISTORICA_H_

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Fecha_Historica {

private:
  int anio;
  int numeventos;
  int reservados;
  string *str;
  void resize(int r);

public:
  Fecha_Historica();


/**
  * @brief Constructor de la clase
  * @param a año del evento a construir
  * @param s vector de string con el evento o eventos de ese año
  * @param n número de eventos que contienen el vector s que se pasa como parámetro
  * @return Crea el evento con año a y n eventos asociados
  * @pre a debe ser mayor o igual que 0 y menos o igual que 9999, n debe ser un número positivo
  * igual al número de eventos contenidos en el vector de string s
  */
  Fecha_Historica(int a, string *s, int n);

/**
  * @brief Constructor de copias de la clase
  * @param e objeto de la clase que se quiere copiar
  * @return Crea el evento con los datos de e
  */
  Fecha_Historica(const Fecha_Historica& e);

  ~Fecha_Historica(){
    cerr << "ELIMINANDO " << anio << "/" << reservados << "/" << numeventos << endl;
     anio=0;
     reservados=0;
     numeventos=0;
     delete[] str;
  }

  int getAnio ();
  void aniadirevento(string& event);


/**
  * @brief Búsqueda de eventos en una Fecha_Historica dada una palabra clave s
  * @param s string con la palabra a buscar
  * @param matches nueva Fecha_Historica donde se introducen únicamente los eventos de this que contienen el string s
  * @return Devuelve true o false indicando si hay o no algún match de la cadena clave s en los eventos de this
  */
  bool buscarEventos(string s, Fecha_Historica &matches);

  friend ostream& operator<< (ostream& os, const Fecha_Historica& e);
  friend istream& operator>> (istream& is, Fecha_Historica& e);

};

#endif
