#include "Cronologia.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

  if (argc!=2) {
      cout << "Dime el nombre del fichero con la cronologia" << endl;
      return 0;
   }

   ifstream f(argv[1]);
   if (!f) {
    cout << "No puedo abrir el fichero " << argv[1] << endl;
    return 0;
   }

   Cronologia mi_cronologia;
   f >> mi_cronologia; //Cargamos en memoria la cronología.

   cout << "Cronologia cargada" << endl;
   cout << mi_cronologia;

   int year;
   cout << "Inserta un año a consultar" << endl;
   cin >> year;

   int buscado = mi_cronologia.buscarAnio(year);
   if (buscado == -1) {
     cout << "Año no encontrado" << endl;
   } else {
     cout << "Año encontrado en la posición " << buscado << endl;
   }

}
