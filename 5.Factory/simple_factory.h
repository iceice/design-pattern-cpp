#ifndef _SIMPLE_FACTORY_H_
#define _SIMPLE_FACTORY_H_

#include "leifeng.h"

class SimpleFactory
{
public:
    static LeiFeng* CreateLeiFeng(std::string type)
    {
        LeiFeng* lf = nullptr;
        if (type == "学生志愿者") lf = new Student();
        else if (type == "社区志愿者") lf = new Volunteer();
        return lf;
    }
};

#endif // _SIMPLE_FACTORY_H_