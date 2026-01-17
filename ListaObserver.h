//
// Created by Liam on 17/01/26.
//

#ifndef UNTITLED3_LISTAOBSERVER_H
#define UNTITLED3_LISTAOBSERVER_H
#include <iostream>
#include <memory>
#include <string>
#include <list>
#include "Observer.h"

using namespace std;

class ListaObserver: public Observer {
private:
    string nomeLista;
public:
    ListaObserver(const string& n);

    void update(const list<Oggetto*> listaspesa) override;
};

#endif //UNTITLED3_LISTAOBSERVER_H
