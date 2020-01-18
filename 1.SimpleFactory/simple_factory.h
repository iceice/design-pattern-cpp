#ifndef _SIMPLE_FACTORY_H_
#define _SIMPLE_FACTORY_H_

#include "operation.h"

class OperationFactory
{
public:
    static Operation *CreateOperate(char op)
    {
        Operation *oper = nullptr;

        if (op == '+')
            oper = new OperationAdd();
        else if (op == '-')
            oper = new OperationSub();
        else if (op == '*')
            oper = new OperationMul();
        else if (op == '/')
            oper = new OperationDiv();

        return oper;
    }
};

#endif // _SIMPLE_FACTORY_H_