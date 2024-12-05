#include <bits/stdc++.h>

class BaseClass{
public:
    void fn1(){
        std::cout << "BaseClass fn1" << std::endl;
    }

    void fn2(){
        std::cout << "BaseClass fn2" << std::endl;
    }
};

class DerivedClass : public BaseClass{
public:
    void fn1(){
        std::cout << "DerivedClass fn1" << std::endl;
    }

    void fn2(){
        std::cout << "DerivedClass fn2" << std::endl;
    }
};

int main(){
    DerivedClass d;
    BaseClass *b = &d;
    DerivedClass *c = &d;
    d.fn1();
    d.fn2();
    b->fn1();
    b->fn2();
    c->fn1();
    c->fn2();
}