#include <iostream>
#include <memory>
#include <string>
#include <list>
#include "Utente.h"
#include "Lista.h"
#include "ListaObserver.h"
#include "Oggetto.h"

using namespace std;

int main() {
    Utente liam("Liam");
    Utente massimiliano("Massimiliano");
    Utente sabina("Sabina");

    auto listaSpesa = make_shared<Lista>("Lista della spesa settimanale");
    auto listaNonna = make_shared<Lista>("Lista della spesa per la nonna");
    auto listaFesta = make_shared<Lista>("Lista della spesa per la festa");

    ListaObserver observers("della spesa settimanele");
    listaSpesa->addObserver(&observers);
    ListaObserver observers1("della spesa per la nonna");
    listaNonna->addObserver(&observers1);
    ListaObserver observers2("della spesa per la festa");
    listaFesta->addObserver(&observers2);

    sabina.aggiungiLista(listaSpesa);
    massimiliano.aggiungiLista(listaSpesa);
    liam.aggiungiLista(listaFesta);
    massimiliano.aggiungiLista(listaFesta);
    sabina.aggiungiLista(listaNonna);

    liam.print();
    sabina.print();
    massimiliano.print();

    Oggetto*a;
    a= new Oggetto("Filoncino di pane", "Panetteria", 1);
    Oggetto*b;
    b= new Oggetto("Penne rigate", "Pasta", 2);
    Oggetto*c;
    c= new Oggetto("Spaghetti", "Pasta", 3);
    Oggetto*d;
    d= new Oggetto("Acqua", "Bevande", 5);
    Oggetto*e;
    e= new Oggetto("Vino", "Bevande", 2);
    Oggetto*f;
    f= new Oggetto("Succo di frutta", "Bevande", 3);
    Oggetto*g;
    g= new Oggetto("Minestrina", "Pasta", 2);
    Oggetto*h;
    h= new Oggetto("Candeline", "Cartoleria", 10);
    Oggetto*i;
    i= new Oggetto("Torta", "Dolci", 1);
    Oggetto*l;
    l= new Oggetto("Tovaglioli", "Utensili",2);

    listaSpesa->addOggetto(a);
    listaSpesa->addOggetto(b);
    listaSpesa->addOggetto(c);
    listaNonna->addOggetto(g);
    listaFesta->addOggetto(h);
    listaFesta->addOggetto(i);
    listaFesta->addOggetto(b);
    listaSpesa->removeOggetto(a);
    listaFesta->removeOggetto(b);

    return 0;
}
