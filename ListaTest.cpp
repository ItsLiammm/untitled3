#include <gtest/gtest.h>
#include "Lista.h"
#include "Oggetto.h"

TEST(ListaTest, Add){
    Lista lista("Lista della spesa settimanale");
    Oggetto a("Filoncino di pane", "Panetteria", 2);
    Oggetto b("Tovaglioli", "Utensili", 3);

    lista.addOggetto(&a);
    lista.addOggetto(&b);

    EXPECT_EQ(lista.getNumeroOggetti(), 5);
}

TEST(ListaTest, Remove){
    Lista lista("Lista della spesa settimanale");
    Oggetto a("Filoncino di pane", "Panetteria", 2);
    Oggetto b("Tovaglioli", "Utensili", 3);

    lista.addOggetto(&a);
    lista.addOggetto(&b);
    lista.removeOggetto(&a);

    EXPECT_EQ(lista.getNumeroOggetti(), 3);
}





//
// Created by Liam on 17/01/26.
//
