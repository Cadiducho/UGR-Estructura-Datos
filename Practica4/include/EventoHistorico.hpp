#ifndef EVENTOHISTORICO_HPP
#define EVENTOHISTORICO_HPP

#include <iostream>
#include <string>
#include <set>
#include <cassert>
#include <sstream>

#include "Fecha.hpp"

using namespace std;

typedef string Suceso;

class EventoHistorico {
private:
    pair<Fecha, set<Suceso>> eventos;

public:

    typedef set<Suceso>::iterator iterator;
    typedef set<Suceso>::const_iterator const_iterator;

    EventoHistorico() {}
    EventoHistorico(const Fecha& f) {
        setFecha(f);
    }
    EventoHistorico(const Fecha& f, const std::set<Suceso>& suc) {
        setFecha(f);
        setSucesos(suc);
    }

    Fecha getFecha() const {
        return eventos.first;
    }

    void setFecha(const Fecha& f) {
        assert(f.getYear() > 0); //usar EC
        eventos.first = f;
    }

    /**
     * Obtener el conjunto de sucesos
     * @return Sucesos
     */
    set<Suceso> getSucesos() const {
        return eventos.second;
    }

    /**
     * Establecer el conjunto de sucesos
     * @param sucesos Conjunto de sucesos
     */
    void setSucesos(const set<Suceso>& sucesos) {
        eventos.second = sucesos;
    }

    /**
     * Insertar un suceso en esta fecha
     * @param s Suceso
     * @return Verdadero si se ha insertado, falso si ya estbaa
     */
    bool addSuceso(const Suceso& s) {
        return eventos.second.insert(s).second;
    }

    /**
     * Insertar un conjunto de sucesos
     * @param s Conjunto
     */
    void addSucesos(const set<Suceso> s) {
        return eventos.second.insert(s.begin(), s.end());
    }

    /**
     * Eliminar un suceso
     * @param s Suceso a eliminar
     * @return True si se ha eliminado
     */
    bool removeSuceso(Suceso& s) {
        return eventos.second.erase(s) > 0;
    }

    /**
     * Eliminar un suceso
     * @param it Posicion donde está el suceso
     */
    void removeSuceso(const_iterator it) {
        if (eventos.second.count(*it) > 0) {
            eventos.second.erase(it);
        }
    }

    //Busquedas y por clave

    /**
     * Comprobar si ese suceso está registrado
     * @param s Suceso
     * @return True si está en los eventos
     */
    bool hasSuceso(const Suceso& s) {
        return eventos.second.count(s) > 0;
    }

    /**
     * Buscar por clave
     * @param key Clave
     * @return Conjunto de claves encontradas
     */
    set<Suceso> searchByKey(const string& key) const {
        set<Suceso> sucesos;
        for (const_iterator it = begin(); it != end(); ++it) {
            if (it->find(key) != string::npos) {
                sucesos.insert(*it);
            }
        }
        return sucesos;
    }

    /**
     * Eliminar por clave
     * @param key Clave
     * @return numero de claves eliminadas
     */
    int removeByKey(const string& key) {
        int i = 0;
        for (const_iterator it = begin(); it != end(); ++it) {
            if ((it->find(key)) != string::npos) {
                eventos.second.erase(it);
                i++;
            }
        }
        return i;
    }

    /**
     * Buscar suceso
     * @param s Suceso
     * @return Iterador de donde se encuentra
     */
    const_iterator searchSuceso(const Suceso& s) const {
        return eventos.second.find(s);
    }

    //Codigo de los iteradores
    iterator begin() {
        return eventos.second.begin();
    }

    iterator end() {
        return eventos.second.end();
    }

    const_iterator begin() const {
        return eventos.second.begin();
    }

    const_iterator end() const {
        return eventos.second.end();
    }
};

istream& operator>>(istream& is, EventoHistorico& e) {
    const char SPLIT = '#';
    set<string> a;
    string aux;

    /*getline(is, aux, SPLIT);
    bool ec = stoi(aux);*/
    getline(is, aux, SPLIT);
    int year = stoi(aux);
    //Fecha fecha(year, ec);
    Fecha fecha(year);

    getline(is, aux);
    istringstream ss(aux);
    while (getline(ss, aux, SPLIT)) {
        a.insert(aux);
    }

    if (is) {
        e.setFecha(fecha);
        e.setSucesos(a);
    }

    return is;
}

ostream& operator<<(ostream& os, const EventoHistorico& e) {
    os << e.getFecha() <<": " << endl;

    for (EventoHistorico::const_iterator it_ev = e.begin(); it_ev != e.end(); ++it_ev) {
        os << " ===> " << (*it_ev) << endl;
    }
    return os;
}

#endif
