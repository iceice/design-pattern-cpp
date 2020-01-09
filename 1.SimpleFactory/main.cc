#include <iostream>
#include "simple_factory.h"

using namespace std;

char rechar() {
    char ch = getchar();
    while (ch == ' ' || ch == '\n' || ch == '\r') ch = getchar();
    return ch;
}

int main() {
    double num_a, num_b;
    char op;
    printf("Please input number a:\n");
    scanf("%lf", &num_a);
    printf("Please select operation (+, -, *, /):\n");
    op = rechar();
    printf("Please input number b:\n");
    scanf("%lf", &num_b);
    
    Operation* oper = OperationFactory::CreateOperate(op);
    oper->set(num_a, num_b);
    try {
        double result = oper->GetResult();
        printf("Result is %lf\n", result);
    }
    catch(const std::runtime_error& e) {
        std::cerr << e.what();
    }
}
