#include <iostream>
#include "proxy.h"

using namespace std;

int main()
{
    Proxy p("zhangyu");
    p.GiveDolls();
    p.GiveFlowers();
    p.GiveFoods();
    return 0;
}