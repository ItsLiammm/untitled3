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
    Oggetto(string n, string c, int q=1) : nome(n), categoria(c), quantità(q) {}
    ~Oggetto(){}

    const string &getNome() const {
        return nome;
    }
    void setNome(const string &nome) {
        Oggetto::nome = nome;
    }

    const string &getCategoria() const {
        return categoria;
    }
    void setCategoria(const string &categoria) {
        Oggetto::categoria = categoria;
    }

    int getQuantità() const {
        return quantità;
    }
    void setQuantità(int quantità) {
        Oggetto::quantità = quantità;
    }

    void print(){
        cout<< this->nome << " appartiene alla categoria: "<< this->categoria << ", e sono: "<< this->quantità<<endl;
    }

};

class Observer {
public:
    virtual void update(list<Oggetto *> listaspesa) =0;
    virtual ~Observer() = default;
};

class Subject {
public:
    virtual void addObserver(Observer* o) =0;
    virtual void removeObserver(Observer* o) =0;
    virtual void notifyObserver() =0;
    virtual ~Subject() = default;
};

class ListaObserver: public Observer {
private:
    string nomeLista;
public:
    ListaObserver(const string& n) : nomeLista(n){}

    void update(const list<Oggetto*> listaspesa) override{
        int totale = 0;
        cout << "Nella lista "<<this->nomeLista<<" ci sono: "<< "\n";
        for (const auto i: listaspesa) {
            totale += i->getQuantità();
            cout <<"-"<<i->getQuantità()<< " "<<i->getNome()<<" appartenente alla categoria: "<<i->getCategoria()<< "\n";
        }
        cout <<"\n" "Gli oggetti totali nella lista sono: "<<totale<<"\n\n\n";
    }
};

class Lista: public Subject {
private:
    list <Oggetto*> listaspesa;
    string nomelista;
    list <Observer*> observers;
public:
    Lista(string n) : nomelista(n) {}
    ~Lista(){}

    const list<Oggetto*> &getListaspesa() const {
        return listaspesa;
    }
    void setListaspesa(const list<Oggetto*> &listaspesa) {
        Lista::listaspesa = listaspesa;
    }

    const string &getNomelista() const {
        return nomelista;
    }
    void setNomelista(const string &nomelista) {
        Lista::nomelista = nomelista;
    }

    void addOggetto(Oggetto* o) {
        listaspesa.push_back(o);
        notifyObserver();
    }
    void removeOggetto(Oggetto*o){
        listaspesa.remove(o);
        notifyObserver();
    }

    int getNumeroOggetti() const {
        int totale = 0;
        for (const auto i: listaspesa)
            totale+= i->getQuantità();
        return totale;
    }

    void print() const{
        cout<<"\n"<<this->nomelista<<" contiene: "<<endl;
        for(auto i: listaspesa){
            i->print();
        }
    }

    void addObserver(Observer* o) override{
        observers.push_back(o);
    }
    void removeObserver(Observer* o) override{
        observers.remove(o);
    }
    void notifyObserver() override{
        for(const auto i: observers) {
            i->update(listaspesa);
        }
    }
};


class Utente{
private:
    string nomeutente;
    list <shared_ptr<Lista>> liste;
public:
    Utente(string n) : nomeutente(n) {}
    ~Utente(){}

    const list <shared_ptr<Lista>> &getListe() const {
        return liste;
    }
    void setListe(const list <shared_ptr<Lista>> &liste) {
        Utente::liste = liste;
    }

    const string &getNomeutente() const {
        return nomeutente;
    }
    void setNomeutente(const string &nomeutente) {
        Utente:: nomeutente = nomeutente;
    }

    void aggiungiLista(const shared_ptr<Lista>& lista){
        liste.push_back(lista);
    }

    void removeLista(const shared_ptr<Lista>& lista){
        liste.remove(lista);
    }

    void print() const{
        cout<<"Liste di "<<this->nomeutente<<":\n";
        for(const auto i: liste){
            cout<<"-"<<i->getNomelista()<<"\n";
        }
        cout<<"\n";
    }
};



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
