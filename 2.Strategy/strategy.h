#ifndef _STRATEGY_H_
#define _STRATEGY_H_

// Abstract base class
class CashSuper
{
public:
    CashSuper();
    virtual ~CashSuper();
    virtual double acceptCash(double money) = 0;
};

// This Class is a normal cash.
class CashNormal : public CashSuper
{
public:
    double acceptCash(double money) { return money; }
};

// This Class is a rebate cash according to specified rebate.
class CashRebate : public CashSuper
{
public:
    CashRebate(double r) : _rebate(r) {}

    double acceptCash(double money) { return money * _rebate; }

private:
    double _rebate;
};

// this Class is a full reduction cash.
class CashReturn : public CashSuper
{
public:
    CashReturn(int c, int r) : _condition(c), _return(r) {}

    double acceptCash(double money)
    {
        double ans = money;
        if (money >= _condition)
            ans -= money / _condition * _return;
        return ans;
    }

private:
    double _condition;
    double _return;
};

#endif // _STRATEGY_H_