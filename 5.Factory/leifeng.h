#ifndef _LEIFENG_H_
#define _LEIFENG_H_

#include <iostream>
#include <string>

class LeiFeng
{
protected:
    std::string _volunteer_t;

public:
    LeiFeng(std::string type) : _volunteer_t(type) {}

    ~LeiFeng() {}

    void Sweep()
    {
        std::cout << "扫地的" << _volunteer_t << std::endl;
    }

    void Wash()
    {
        std::cout << "洗衣的" << _volunteer_t << std::endl;
    }

    void Buy()
    {
        std::cout << "买菜的" << _volunteer_t << std::endl;
    }
};

class Student : public LeiFeng
{
public:
    Student() : LeiFeng::LeiFeng("学生志愿者") {}
    ~Student() {}
};

class Volunteer : public LeiFeng
{
public:
    Volunteer() : LeiFeng::LeiFeng("社区志愿者") {}
};

#endif // _LEIFENG_H_