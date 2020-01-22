#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "leifeng.h"

class IFactory
{
public:
    IFactory() {}
    virtual ~IFactory() {}
    virtual LeiFeng *CreateLeiFeng() = 0;
};

class StudentFactory : public IFactory
{
public:
    LeiFeng *CreateLeiFeng() { return new Student(); }
};

class VolunteerFactory : public IFactory
{
public:
    LeiFeng *CreateLeiFeng() { return new Volunteer(); }
};

#endif // _FACTORY_H_