#include <iostream>
#include "5-13.h"
#ifdef _WIN32
#include <windows.h>
#endif
int main() {
    X x;
    Y y;
    Z z;

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    
    std::cout << "初始值: " << x.get() << std::endl;

    y.g(&x);
    std::cout << "调用Y的g函数后: " << x.get() << std::endl;

    z.f(&x);
    std::cout << "调用Z的f函数后: " << x.get() << std::endl;

    h(&x);
    std::cout << "调用h函数后: " << x.get() << std::endl;

    return 0;
}