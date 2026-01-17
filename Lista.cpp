#include <iostream>
#include <memory>
#include <string>
#include <list>
#include "Lista.h"
#include "Oggetto.h"
#include "Observer.h"

using namespace std;



    Lista::Lista(string n) : nomelista(n) {}
    Lista::~Lista(){}

    const list<Oggetto*> &Lista::getListaspesa() const {
        return listaspesa;
    }
    void Lista::setListaspesa(const list<Oggetto*> &listaspesa) {
        Lista::listaspesa = listaspesa;
    }

    const string &Lista::getNomelista() const {
        return nomelista;
    }
    void Lista::setNomelista(const string &nomelista) {
        Lista::nomelista = nomelista;
    }

    void Lista::addOggetto(Oggetto* o) {
        listaspesa.push_back(o);
        notifyObserver();
    }
    void Lista::removeOggetto(Oggetto*o){
        listaspesa.remove(o);
        notifyObserver();
    }

    int Lista::getNumeroOggetti() const {
        int totale = 0;
        for (const auto i: listaspesa)
            totale+= i->getQuantità();
        return totale;
    }

    void Lista::print() const{
        cout<<"\n"<<this->nomelista<<" contiene: "<<endl;
        for(auto i: listaspesa){
            i->print();
        }
    }

    void Lista::addObserver(Observer* o){
        observers.push_back(o);
    }
    void Lista::removeObserver(Observer* o){
        observers.remove(o);
    }
    void Lista::notifyObserver(){
        for(const auto i: observers) {
            i->update(listaspesa);
        }
    };









//
// Created by Liam on 17/01/26.
//
