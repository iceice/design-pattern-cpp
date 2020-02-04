#ifndef _CONCRETE_OBSERVER_H_
#define _CONCRETE_OBSERVER_H_

#include "observer.h"
#include <iostream>
#include <string>

using namespace std;

class ConcreteObserver : public IObserver
{
private:
    string _name;
public:
    ConcreteObserver(string name) : _name(name) {}

    void Update(float price)
    {
        cout << _name << " price: " << price << endl;
    }
};

#endif // _CONCRETE_OBSERVER_H_