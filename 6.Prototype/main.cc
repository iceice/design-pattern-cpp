#include <iostream>
#include "concrete_prototype.h"

using namespace std;

int main()
{
    Resume *a = new Resume("Xiaoming");
    a->SetPersonalInfo("male", "23");
    a->SetWorkExperience("2018-2019", "ByteDance");
    
    Resume *b = a->Clone();
    b->SetWorkExperience("2019-2020", "Microsoft");

    Resume *c = a->Clone();
    c->SetWorkExperience("2020-2021", "Hulu");

    a->Display();
    b->Display();
    c->Display();

    return 0;
}
