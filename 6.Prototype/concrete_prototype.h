#ifndef _CONCRETE_PROTOTYPE_H_
#define _CONCRETE_PROTOTYPE_H_

#include "prototype.h"
#include <iostream>
#include <string>

class Resume : public Prototype
{
private:
    std::string _name;
    std::string _sex;
    std::string _age;
    std::string _time;
    std::string _company;

public:
    Resume(std::string name) : _name(name), _sex(""), _age(""), _time(""), _company("") {}

    // 拷贝构造函数
    Resume(const Resume& other)
    {
        _name = other._name;
        _sex = other._sex;
        _age = other._age;
        _time = other._time;
        _company = other._company;
    }
    
    ~Resume() {}


    void SetPersonalInfo(std::string sex, std::string age)
    {
        _sex = sex;
        _age = age;
    }

    void SetWorkExperience(std::string time, std::string company)
    {
        _time = time;
        _company = company;
    }

    void Display()
    {
        std::cout << _name << " " << _age << "  " << _sex << std::endl;
        std::cout << _time << " " << _company << std::endl;
        std::cout << std::endl;
    }

    Resume* Clone()
    {
        return new Resume(*this);
    }

};

#endif // _CONCRETE_PROTOTYPE_H_