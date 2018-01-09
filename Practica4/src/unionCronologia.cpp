#include <iostream>
#include <fstream>

#include "../include/Cronologia.hpp"

using namespace std;

int main(int argc, char ** argv){

    if (argc != 3) {
        cout << " ./unionCronologia <crono 1> <crono 2> " << endl;
        return 0;
    }

    ifstream f1(argv[1]);
    if (!f1){
        cout << " No se encuentra el archivo" << argv[1] << endl;
        return 0;
    }
    ifstream f2(argv[2]);
    if (!f2){
        cout << " No se encuentra el archivo" << argv[1] << endl;
        return 0;
    }

    Cronologia c1, c2;
    f1 >> c1;
    f2 >> c2;

    c1.Union(c2);

    cout << c1;
}
