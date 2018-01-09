#ifndef FECHA_HPP
#define FECHA_HPP

#include <iostream>

class Fecha {
private:
    int year;
    bool ec; //Era Común

public:
    Fecha(int year = 1, bool ec = true) {
        this->year = year;
        this->ec = ec;
    }

    inline int getYear() const {
        return year;
    }

    inline bool isEC() const {
        return ec;
    }

    bool operator<=(const Fecha& f) const {
        return ((f.ec && year <= f.year) || !(ec && year > f.year) || (ec != f.ec));
    }
};

std::ostream& operator<<(std::ostream& os, const Fecha& f) {
    os << f.getYear() << " " << (f.isEC() ? "EC" : "AEC");
    return os;
}

#endif
