#include <iostream>
#include "component.h"
#include "decorator.h"

using namespace std;

int main()
{
    Phone *p = new IPhone("Iphone11 pro max");
    Phone *memory = new ConcreteDecoratorA(p);
    Phone *storage = new ConcreteDecoratorB(memory);
    storage->show();
    cout << endl;
    return 0; 
}
