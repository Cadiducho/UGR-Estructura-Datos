
#include <iostream>
#include <fstream>
#include "../include/Cronologia.hpp"

using namespace std;

int maximoSucesos(const Cronologia& c) {
    int max = 0;
    for (Cronologia::const_iterator p = c.begin(); p != c.end(); ++p) {
        int num_acontecimientos = 0;
        for (EventoHistorico::const_iterator it = p->second.begin(); it != p->second.end(); ++it) {
            num_acontecimientos++;
        }
        if (num_acontecimientos > max)
            max = num_acontecimientos;
    }
    return max;
}

pair<int,int> cantidadTotal(const Cronologia& c) {
    pair<int,int> res(0,0);

    for (Cronologia::const_iterator p = c.begin(); p != c.end(); ++p) {
        for (EventoHistorico::const_iterator it = p->second.begin(); it != p->second.end(); ++it) {
            res.second++;
        }
        res.first++;
    }

    return res;
}

int main(int argc, char ** argv) {
    if (argc != 2){
        cout << "./estadisticaEventos <archivo>" << endl;
        return 0;
    }

    ifstream f(argv[1]);
    if (!f){
        cout << " No se encuentra el archivo" << argv[1] << endl;
        return 0;
    }

    // Cargar cronología
    Cronologia c1;
    f >> c1;

    pair<int,int> totales = cantidadTotal(c1);
    int media = totales.second / totales.first;
    int max = maximoSucesos(c1);

    cout << "La cronologia tiene " << totales.first << " EventosHistoricos, los cuales tienen un total de " << totales.second << " sucesos" << endl;
    cout << "Los sucesos maximos en un año son " << max << " mientras que la media son " << media << ".\n";

    return 0;
}
