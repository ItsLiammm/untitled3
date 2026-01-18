#include <gtest/gtest.h>
#include "Oggetto.h"

TEST(OggettoTest, Costruttore){
    Oggetto a("Filoncino di pane", "Panetteria", 2);

    EXPECT_EQ(a.getNome(), "Filoncino di pane");
    EXPECT_EQ(a.getCategoria(), "Panetteria");
    EXPECT_EQ(a.getQuantità(), 2);
}

TEST(OggettoTest, Setter) {
    Oggetto b("Filoncino di pane", "Panetteria", 2);

    b.setNome("Tovaglioli");
    b.setCategoria("Utensili");
    b.setQuantità(3);

    EXPECT_EQ(b.getNome(), "Tovaglioli");
    EXPECT_EQ(b.getCategoria(), "Utensili");
    EXPECT_EQ(b.getQuantità(), 3);
}











//
// Created by Liam on 17/01/26.
//
