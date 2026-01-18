#include <gtest/gtest.h>
#include "Utente.h"
#include "Lista.h"
#include <memory>
using namespace std;

TEST(UtenteTest, Add){
    Utente liam("Liam");

    auto listaSpesa = make_shared<Lista>("Spesa");
    auto listaFesta= make_shared<Lista>("Festa");

    liam.aggiungiLista(listaSpesa);
    liam.aggiungiLista(listaFesta);

    EXPECT_EQ(liam.getListe().size(), 2);
}










//
// Created by Liam on 18/01/26.
//
