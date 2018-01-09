#ifndef CRONOLOGIA_HPP
#define CRONOLOGIA_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "EventoHistorico.hpp"

using namespace std;

struct comparador {
    bool operator()(const EventoHistorico& a, const EventoHistorico& b) const {
        return (a.getFecha() <= b.getFecha() && !((a.getFecha().isEC() == b.getFecha().isEC()) && (a.getFecha().getYear() == b.getFecha().getYear())));
    }
};

class Cronologia {
private:
    typedef map<Fecha,EventoHistorico,comparador> contenedor;

    contenedor datos;
public:
    typedef contenedor::iterator iterator;
    typedef contenedor::const_iterator const_iterator;

    Cronologia() {}

    Cronologia(const contenedor& v) {
        setCronologia(v);
    }

    contenedor getCronologia() const {
        return datos;
    }

    void setCronologia(const contenedor& v) {
        datos = v;
    }

    void setSucesos(const set<Suceso>& v, const Fecha& f) {
        datos[f].setSucesos(v);
    }

    void addSuceso(const EventoHistorico& e) {
        Fecha f = e.getFecha();

        if (datos.count(f) < 0) {
            pair<Fecha, EventoHistorico> par(f,e);
            datos.insert(par);
        } else {
            datos[f].addSucesos(e.getSucesos());
        }
    }

    void eliminarSuceso(const Fecha& f) {
        datos.erase(f);
    }

    //Consultas y keys

    /**
     * Eliminar claves de una cronologia
     * @param key Clave
     * @return Cantidad de claves eliminadas
     */
    int removeByKey(const string& key) {
        int n = 0;
        const_iterator p = datos.begin();
        while (p != datos.end()) {
            if (p->second.searchByKey(key).size() != 0) {
                p = datos.erase(p);
                n++;
            } else {
                p++;
            }
        }
        return n;
    }

    /**
     * Comprobar si tiene una fecha
     * @param f Fecha
     * @return true si encuentra esa fecha
     */
    bool hasFecha(const Fecha& f) const {
        return datos.count(f) > 0;
    }

    /**
     * Comprobar si tiene un Suceso
     * @param s Suceso
     * @return true si encuentra el suceso
     */
    bool hasSuceso(const Suceso& s) const {
        for (const_iterator p = datos.begin(); p != datos.end(); ++p) {
            if (p->second.searchSuceso(s) != p->second.end()) {
                return true;
            }
        }
        return false;
    }

    /**
     * Buscar un evento histórico a partir de una fecha
     * @param f Fecha
     * @return iterador donde está EventoHistórico
     */
    const_iterator searchEvento(const Fecha& f) const {
        return datos.find(f);
    }

    /**
     * Buscar la fecha en la que tuvo lugar un suceso
     * @param s Suceso
     * @return Fecha del suceso
     */
    Fecha getFechaSuceso(const Suceso& s) const {
        assert(hasSuceso(s));
        for (const_iterator p = datos.begin(); p != datos.end(); ++p) {
            if (p->second.searchSuceso(s) != p->second.end()) {
                return p->first;
            }
        }
    }

    /**
     * Obtener los eventos históricos asociados a una fecha
     * @return EventoHistorico
     */
    EventoHistorico getEventos(const Fecha& f) {
        assert(hasFecha(f));

        return datos[f];
    }

    /**
     * Unir otra cronologia a esta instancia
     */
    void Union(const Cronologia & otra){
        for (const_iterator it = otra.begin(); it != otra.end(); ++it) {
            this->addSuceso((*it).second);
        }
    }

    //Iteradores
    iterator begin() { return datos.begin(); }
    iterator end() { return datos.end(); }

    const_iterator begin() const { return datos.begin(); }
    const_iterator end() const { return datos.end(); }
};

istream& operator>>(std::istream& is, Cronologia& c) {
    EventoHistorico tmp;
    map<Fecha,EventoHistorico,comparador> v;
    pair<Fecha, EventoHistorico> new_element;
    string s;

    // Ignorar blancos iniciales
    while(isspace(is.peek()))
        is.get();

    // Leer línea a línea
    while(getline(is,s)) {
        istringstream ss(s);
        ss >> new_element.second;
        new_element.first = new_element.second.getFecha();
        v.insert(new_element);
    }

    if (is.eof()) {
        c.setCronologia(v);
    }

    return is;
}

ostream& operator<<(std::ostream& os, const Cronologia& c) {
    for (Cronologia::const_iterator it  = c.begin(); it != c.end(); ++it) {
        os << (*it).first << ": " << endl;

        for (EventoHistorico::const_iterator it_evento =(*it).second.begin(); it_evento != (*it).second.end(); ++it_evento) {
            os << " ==> " << (*it_evento) << endl;
        }
    }
    return os;
}

#endif
