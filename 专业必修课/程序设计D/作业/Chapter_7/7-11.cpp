// 7-11
// 定义一个基类 BaseClass, 从它派生类 DerivedClass.
// BaseClass有成员函数fn1() | fn2(), DerivedClass 也有成员函数fn1() | fn2()
// 在主函数中声明一个DerivedClass的对象，分别用DerivedClass的对象以及BaseClass和DerivedClass的指针来调用fn1() | fn2(),观察运行结果
#include <iostream>
using namespace std;

class BaseClass {
public:
    void fn1() { cout << "BaseClass::fn1()" << endl; }
    void fn2() { cout << "BaseClass::fn2()" << endl; }
};

class DerivedClass : public BaseClass {
public:                                               
    void fn1() { cout << "DerivedClass::fn1()" << endl; }
    void fn2() { cout << "DerivedClass::fn2()" << endl; }
};

int main() {
    DerivedClass derivedObj;

    derivedObj.fn1();
    derivedObj.fn2();

    BaseClass *basePtr = &derivedObj;
    basePtr->fn1();
    basePtr->fn2();

    DerivedClass *derivedPtr = &derivedObj;
    derivedPtr->fn1();
    derivedPtr->fn2();

    return 0;
}