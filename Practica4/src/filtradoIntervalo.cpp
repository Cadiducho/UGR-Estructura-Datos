#include <iostream>
#include <fstream>

#include "../include/Cronologia.hpp"

using namespace std;

int main(int argc, char const **argv) {

    if (argc != 2){
        cout << "./filtradoIntervalo <archivo>" << endl;
        return 0;
    }

    ifstream f(argv[1]);
    if (!f){
        cout << " No se encuentra el archivo" << argv[1] << endl;
        return 0;
    }

    Cronologia crono;
    f >> crono;

    int y1, y2;
    cout << "Inserta el primer año del intervalo: ";
    cin >> y1;
    cout << "Inserta el segundo año del intervalo: ";
    cin >> y2;

    Fecha date1(y1);
    Fecha date2(y2);
    Cronologia::const_iterator it_inicio = crono.searchEvento(date1);
    Cronologia::const_iterator it_final = crono.searchEvento(date2);
    Cronologia nueva;
    while (it_inicio != it_final) {
        nueva.addSuceso((*it_inicio).second);
        it_inicio++;
    }

    cout << "Se ha filtrado entre los años " << y1 << " y " << y2 << endl;
    cout << "Cronología filtrada: " << endl;
    cout << nueva;
    return 0;
}