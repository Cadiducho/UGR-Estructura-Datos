#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <iostream>

struct elemento {
    int n;
    int max;

    friend std::ostream& operator<<(std::ostream &salida, const elemento &e){
        salida << "( "<< e.n << ", " << e.max << " )";
        return salida;
    };
};

#endif
