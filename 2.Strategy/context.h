#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <string>
#include "strategy.h"

class Context
{
private:
    CashSuper *cs;

public:
    Context(std::string type);

    double GetResult(double money);
};

Context::Context(std::string type)
{
    // Imitated Simple Factory
    if (type == "normal")
        cs = new CashNormal();
    else if (type == "rebate-8")
        cs = new CashRebate(0.8);
    else if (type == "return-300-100")
        cs = new CashReturn(300, 100);
}

double Context::GetResult(double money)
{
    return cs->acceptCash(money);
}

#endif // _CONTEXT_H_