#include "guiatlf.h"
#include <fstream>

int main() {
    Guia_Tlf guia;

    cout << "Introduce el fichero con una guia de telefonos" << endl;
    string guia1;
    getline(cin, guia1);
    ifstream file1(guia1);
    file1 >> guia;

    cout << "Introduce otro fichero con otra guia de telefonos" << endl;
    Guia_Tlf otraguia;
    string guia2;
    getline(cin, guia2);
    ifstream file2(guia2);
    file2 >> otraguia;

    Guia_Tlf un = guia + otraguia;
    Guia_Tlf dif = guia - otraguia;
    Guia_Tlf inter = guia * otraguia;
    
    cout << endl << "La union de las dos guias: " << endl << un << endl;

    cout << endl << "La diferencia de las dos guias:" << endl << dif << endl;

    cout << endl << "La interseccion de las dos guias:" << endl << inter << endl;
}
