#include "Ctype.h"

int main()
{
    Ctype ::Print();
    // 未定义对象时，直接通过类名调用静态成员函数
    Ctype c1, c2;
    c1.Print(); // 可以用对象调用静态成员函数
    c2.Print();
    Ctype c3;
    c3.Print();
    return 0;
}
