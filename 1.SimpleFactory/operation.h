#ifndef _OPERATION_H_
#define _OPERATION_H_

#include <stdexcept>

class Operation
{
public:
    Operation() : _number_a(0), _number_b(0){};

    virtual ~Operation();

    void set(double a, double b)
    {
        _number_a = a;
        _number_b = b;
    }

    virtual double GetResult() = 0;

protected:
    double _number_a;
    double _number_b;
};

// Add
class OperationAdd : public Operation
{
public:
    double GetResult()
    {
        return _number_a + _number_b;
    }
};

// Sub
class OperationSub : public Operation
{
public:
    double GetResult()
    {
        return _number_a - _number_b;
    }
};

// Multiplication
class OperationMul : public Operation
{
public:
    double GetResult()
    {
        return _number_a * _number_b;
    }
};

//
class OperationDiv : public Operation
{
public:
    double GetResult()
    {
        if (_number_b == 0)
            throw std::runtime_error("Math error: Attempted to divide by Zero\n");
        return _number_a / _number_b;
    }
};

#endif // _OPERATION_H_H