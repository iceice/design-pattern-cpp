#ifndef _PROXY_H_
#define _PROXY_H_

#include <iostream>
#include <string>

class Subject
{
public:
    Subject() {}
    virtual ~Subject() {}
    virtual void GiveDolls() = 0;
    virtual void GiveFlowers() = 0;
    virtual void GiveFoods() = 0;
};

class Pursuit : public Subject
{
private:
    std::string _girl_name;
public:
    Pursuit(std::string name) : _girl_name(name) {}
    ~Pursuit() {}

    void GiveDolls()
    {
        std::cout << _girl_name << " 送给你一个娃娃" << std::endl;
    }

    void GiveFlowers()
    {
        std::cout << _girl_name << " 送给你一束花" << std::endl;
    }

    void GiveFoods()
    {
        std::cout << _girl_name << " 送给你一箱零食" << std::endl;
    }
};


class Proxy : Subject
{
private:
    Pursuit* _real_subject;
public:
    Proxy(std::string name)
    {
        _real_subject = new Pursuit(name);
    }

    void GiveDolls()
    {
        _real_subject->GiveDolls();
    }

    void GiveFlowers()
    {
        _real_subject->GiveFlowers();
    }

    void GiveFoods()
    {
        _real_subject->GiveFoods();
    }
};

#endif // _PROXY_H