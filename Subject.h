//
// Created by Liam on 17/01/26.
//

#ifndef UNTITLED3_SUBJECT_H
#define UNTITLED3_SUBJECT_H
#include <iostream>
#include <memory>
#include <string>
#include <list>

using namespace std;

class Observer;

class Subject {
public:
    virtual void addObserver(Observer* o) =0;
    virtual void removeObserver(Observer* o) =0;
    virtual void notifyObserver() =0;
    virtual ~Subject() = default;
};

#endif //UNTITLED3_SUBJECT_H
