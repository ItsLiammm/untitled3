#include <iostream>
#include <memory>
#include <string>
#include <list>
#include "Oggetto.h"

using namespace std;


    Oggetto::Oggetto(string n, string c, int q) : nome(n), categoria(c), quantità(q) {}
    Oggetto::~Oggetto(){}

    const string &Oggetto::getNome() const {
        return nome;
    }
    void Oggetto::setNome(const string &nome) {
        Oggetto::nome = nome;
    }

    const string &Oggetto::getCategoria() const {
        return categoria;
    }
    void Oggetto::setCategoria(const string &categoria) {
        Oggetto::categoria = categoria;
    }

    int Oggetto::getQuantità() const {
        return quantità;
    }
    void Oggetto::setQuantità(int quantità) {
        Oggetto::quantità = quantità;
    }

    void Oggetto::print(){
        cout<< this->nome << " appartiene alla categoria: "<< this->categoria << ", e sono: "<< this->quantità<<endl;
    }

//
// Created by Liam on 17/01/26.
//
