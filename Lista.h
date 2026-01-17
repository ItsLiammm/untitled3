//
// Created by Liam on 17/01/26.
//

#ifndef UNTITLED3_LISTA_H
#define UNTITLED3_LISTA_H
#include <iostream>
#include <memory>
#include <string>
#include <list>
#include "Subject.h"

using namespace std;

class Oggetto;
class Observer;

class Lista: public Subject {
private:
    list <Oggetto*> listaspesa;
    string nomelista;
    list <Observer*> observers;
public:
    Lista(string n);
    ~Lista();

    const list<Oggetto*> &getListaspesa() const;
    void setListaspesa(const list<Oggetto*> &listaspesa);

    const string &getNomelista() const;
    void setNomelista(const string &nomelista);

    void addOggetto(Oggetto* o);
    void removeOggetto(Oggetto*o);

    int getNumeroOggetti() const;

    void print() const;

    void addObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObserver() override;
    };

#endif //UNTITLED3_LISTA_H
