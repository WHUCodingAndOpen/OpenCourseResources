// 写出以下程序的执行结果
#include <iostream>
using namespace std;
class Base {
public:
    void Display() {
        cout << "Display in Base" << endl;
    }
    virtual void Print() {
        cout << "Print in Base" << endl;
    }
};
class Derived : public Base {
public:
    void Display() {
        cout << "Display in Derived" << endl;
    }
    virtual void Print() {
        cout << "Print in Derived" << endl;
    }
};
int main()
{
    Base *b = new Base();
    Derived *d = new Derived();
    b->Display();
    d->Display();
    b->Print();
    d->Print();
    b = d;
    b->Display();
    d->Display();
    b->Print();
    d->Print();

    return 0;
}
