#include <iostream>
#include "5-13.h"
#include <windows.h>

int main() {
    X x;
    Y y;
    Z z;
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "初始值: " << x.get() << std::endl;

    y.g(&x);
    std::cout << "调用Y的g函数后: " << x.get() << std::endl;

    z.f(&x);
    std::cout << "调用Z的f函数后: " << x.get() << std::endl;

    h(&x);
    std::cout << "调用h函数后: " << x.get() << std::endl;

    return 0;
}