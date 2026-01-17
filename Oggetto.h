//
// Created by Liam on 17/01/26.
//

#ifndef UNTITLED3_OGGETTO_H
#define UNTITLED3_OGGETTO_H
#include <iostream>
#include <memory>
#include <string>
#include <list>

using namespace std;


class Oggetto{
private:
    string nome;
    string categoria;
    int quantità;

public:
    Oggetto(string n, string c, int q=1);
    ~Oggetto();

    const string &getNome() const;
    void setNome(const string &nome);

    const string &getCategoria() const;
    void setCategoria(const string &categoria);

    int getQuantità() const;
    void setQuantità(int quantità);

    void print();

};

#endif //UNTITLED3_OGGETTO_H
