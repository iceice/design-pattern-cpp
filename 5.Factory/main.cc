#include <iostream>
#include "leifeng.h"
#include "factory.h"
#include "simple_factory.h"

using namespace std;

int main()
{
    // 简单工厂模式
    LeiFeng* student1 = SimpleFactory::CreateLeiFeng("学生志愿者");
    LeiFeng* student2 = SimpleFactory::CreateLeiFeng("学生志愿者");
    LeiFeng* student3 = SimpleFactory::CreateLeiFeng("学生志愿者");
    student1->Buy();
    student2->Sweep();
    student3->Wash();

    // 工厂模式
    IFactory *factory = new VolunteerFactory();
    LeiFeng *volunteer1 = factory->CreateLeiFeng();
    LeiFeng *volunteer2 = factory->CreateLeiFeng();
    LeiFeng *volunteer3 = factory->CreateLeiFeng();
    volunteer1->Buy();
    volunteer2->Sweep();
    volunteer3->Wash();
    return 0;
}