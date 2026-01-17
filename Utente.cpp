#include <iostream>
#include <memory>
#include <string>
#include <list>
#include "Utente.h"
#include "Lista.h"

using namespace std;

    Utente::Utente(string n) : nomeutente(n) {}
    Utente::~Utente(){}

    const list <shared_ptr<Lista>> &Utente::getListe() const {
        return liste;
    }
    void Utente::setListe(const list <shared_ptr<Lista>> &liste) {
        Utente::liste = liste;
    }

    const string &Utente::getNomeutente() const {
        return nomeutente;
    }
    void Utente::setNomeutente(const string &nomeutente) {
        Utente:: nomeutente = nomeutente;
    }

    void Utente::aggiungiLista(const shared_ptr<Lista>& lista){
        liste.push_back(lista);
    }

    void Utente::removeLista(const shared_ptr<Lista>& lista){
        liste.remove(lista);
    }

    void Utente::print() const{
        cout<<"Liste di "<<this->nomeutente<<":\n";
        for(const auto i: liste){
            cout<<"-"<<i->getNomelista()<<"\n";
        }
        cout<<"\n";
    }







//
// Created by Liam on 17/01/26.
//
