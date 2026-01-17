//
// Created by Liam on 17/01/26.
//

#ifndef UNTITLED3_OBSERVER_H
#define UNTITLED3_OBSERVER_H
#include <iostream>
#include <memory>
#include <string>
#include <list>

using namespace std;

class Oggetto;

class Observer {
public:
    virtual void update(list<Oggetto *> listaspesa) =0;
    virtual ~Observer() = default;
};

#endif //UNTITLED3_OBSERVER_H
