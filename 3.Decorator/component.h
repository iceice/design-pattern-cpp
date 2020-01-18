#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <iostream>
#include <string>

// Component base class
class Phone
{
protected:
    std::string _pname;

public:
    Phone() {}

    Phone(std::string name) : _pname(name) {}

    virtual ~Phone() {}

    virtual void show() = 0;
};

// Concrete component iphone
class IPhone : public Phone
{
public:
    IPhone(std::string name) : Phone(name) {}

    ~IPhone() {}

    void show() { std::cout << Phone::_pname << "的装饰:\n"; }
};

// Concrete component android
class Android : public Phone
{
public:
    Android(std::string name) : Phone(name) {}

    ~Android() {}

    void show() { std::cout << Phone::_pname << "的装饰\n"; }
};

#endif // _COMPONENT_H_