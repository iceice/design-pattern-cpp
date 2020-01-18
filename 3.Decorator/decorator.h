#ifndef _DECORATOR_H_
#define _DECORATOR_H_

#include <iostream>
#include "component.h"

class Decorator : public Phone
{
private:
    Phone *_phone; // 要修饰的手机

public:
    Decorator(Phone *p) : _phone(p) {}

    ~Decorator() {}

    void show() { _phone->show(); }
};

class ConcreteDecoratorA : public Decorator
{
private:
    void AddDecorator() { std::cout << "16G内存 "; }

public:
    ConcreteDecoratorA(Phone *p) : Decorator(p) {}

    void show()
    {
        Decorator::show();
        AddDecorator();
    }
};

class ConcreteDecoratorB : public Decorator
{
private:
    void AddDecorator() { std::cout << "512G存储容量 "; }

public:
    ConcreteDecoratorB(Phone *p) : Decorator(p) {}

    void show()
    {
        Decorator::show();
        AddDecorator();
    }
};

#endif // _DECORATOR_H_