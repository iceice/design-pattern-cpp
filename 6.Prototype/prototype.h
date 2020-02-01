#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

class Prototype
{
public:
    Prototype() {}

    virtual ~Prototype() {}

    virtual Prototype* Clone() = 0;

    virtual void Display() = 0;
};

#endif // _PROTOTYPE_H_