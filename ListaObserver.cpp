#include <iostream>
#include <memory>
#include <string>
#include <list>
#include "ListaObserver.h"
#include "Oggetto.h"

using namespace std;


    ListaObserver::ListaObserver(const string& n) : nomeLista(n){}

    void ListaObserver::update(const list<Oggetto*> listaspesa){
        int totale = 0;
        cout << "Nella lista "<<this->nomeLista<<" ci sono: "<< "\n";
        for (const auto i: listaspesa) {
            totale += i->getQuantità();
            cout <<"-"<<i->getQuantità()<< " "<<i->getNome()<<" appartenente alla categoria: "<<i->getCategoria()<< "\n";
        }
        cout <<"\n" "Gli oggetti totali nella lista sono: "<<totale<<"\n\n\n";
    }






//
// Created by Liam on 17/01/26.
//
