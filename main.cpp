#include <iostream>
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

};

class Lista{
private:
    list <Oggetto*> listaspesa;
    string nomelista;
public:
    Lista(list <Oggetto*> l, string n) : listaspesa(l), nomelista(n) {}
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
    }
    void removeOggetto(Oggetto*o){
        listaspesa.remove(o);
    }

    int getNumeroOggetti() const {
        int totale = 0;
        for (const auto i: listaspesa)
            totale+= i->getQuantità();
        return totale;
    }
};

class Utente{
private:
    string nomeutente;
    list <shared_ptr<Lista>> liste;
public:
    Utente(string n, list <shared_ptr<Lista>> l) : nomeutente(n), liste(l) {}
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
};









int main() {



    return 0;
}
