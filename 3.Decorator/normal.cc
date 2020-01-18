/*
 定义一个装扮的普通作法，明显存在的问题就是当我们先要新增加一种装扮的
 时候，就要完全修改Person这个类，显然这不是一个好办法。
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name) : _name(name) {}

    void show() { cout << "装扮的: " << _name << endl; }

    void TShirts() { cout << "T恤 "; }
    void Jeans() { cout << "牛仔裤 "; }
    void Sneaker() { cout << "球鞋 "; }
    
    void Suit() { cout << "西装 "; }
    void Tie() { cout << "领带 "; }
    void Leather() { cout << "皮鞋 "; }
private:
    string _name;
};

int main()
{
    Person p("码农");
    cout << "第一种装扮：\n";
    p.TShirts();
    p.Jeans();
    p.Sneaker();
    p.show();

    cout << "第二种装扮：\n";
    p.Suit();
    p.Tie();
    p.Leather();
    p.show();

    return 0;
}