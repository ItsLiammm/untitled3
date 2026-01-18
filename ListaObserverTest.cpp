#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Lista.h"
#include "Observer.h"
#include "Oggetto.h"

class MockObserver : public Observer {
public:
    MOCK_METHOD(void, update, ( list<Oggetto*>), (override));
};

TEST(ListaObserverTest, Notify){
    Lista listaSpesa("Spesa");
    MockObserver mockObs;

    listaSpesa.addObserver(&mockObs);
    Oggetto a("Filoncino di pane", "Panetteria", 2);

    EXPECT_CALL(mockObs, update(testing::_)).Times(1);
    listaSpesa.addOggetto(&a);
}



//
// Created by Liam on 17/01/26.
//
