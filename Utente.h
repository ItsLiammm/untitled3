//
// Created by Liam on 17/01/26.
//

#ifndef UNTITLED3_UTENTE_H
#define UNTITLED3_UTENTE_H
#include <iostream>
#include <memory>
#include <string>
#include <list>

using namespace std;

class Lista;

class Utente{
private:
    string nomeutente;
    list <shared_ptr<Lista>> liste;
public:
    Utente(string n);
    ~Utente();

    const list <shared_ptr<Lista>> &getListe() const;
    void setListe(const list <shared_ptr<Lista>> &liste);

    const string &getNomeutente() const;
    void setNomeutente(const string &nomeutente);

    void aggiungiLista(const shared_ptr<Lista>& lista);

    void removeLista(const shared_ptr<Lista>& lista);

    void print() const;
};


#endif //UNTITLED3_UTENTE_H
