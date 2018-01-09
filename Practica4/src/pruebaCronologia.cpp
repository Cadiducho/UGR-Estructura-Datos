#include <iostream>
#include <fstream>

#include "../include/Cronologia.hpp"

using namespace std;

int main(int argc, char** argv){

    if (argc != 2){
        cout << "./pruebaCronologia <archivo>" << endl;
        return 0;
    }

    ifstream f(argv[1]);
    if (!f){
        cout << " No se encuentra el archivo" << argv[1] << endl;
        return 0;
    }

    Cronologia crono;
    f >> crono;
    int year;
    cout << "Introduce un año a consultar: ";
    cin >> year;

    Fecha date(year);
    if (crono.hasFecha(date)) {
        EventoHistorico eventos = crono.getEventos(year);

        EventoHistorico::const_iterator it;
        cout << year << ": " << endl;
        for (it = eventos.begin(); it != eventos.end(); ++it) {
            cout << " ===> " << (*it);
            cout << endl;
        }
    } else {
        cout << "No tengo nada de esa fecha" << endl;
    }
    return 0;
}