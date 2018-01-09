#include <iostream>
#include <fstream>

#include "../include/Cronologia.hpp"

using namespace std;

int main(int argc, char const **argv) {

    if (argc != 2){
        cout << "./filtradoPalabraa <archivo>" << endl;
        return 0;
    }

    ifstream f(argv[1]);
    if (!f){
        cout << " No se encuentra el archivo" << argv[1] << endl;
        return 0;
    }

    Cronologia crono;
    f >> crono;

    string palabra;
    cout << "Inserta palabra con la que filtrar: " << endl;
    cin >> palabra;

    int borrados = crono.removeByKey(palabra);

    cout << "Se han filtrado " << borrados << " elementos" << endl;
    cout << "Cronología filtrada: " << endl;
    cout << crono;
    return 0;
}