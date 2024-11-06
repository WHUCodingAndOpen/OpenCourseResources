#include "Ctype.h"

void Ctype::Print()
{
    // cout << "a=" << ++a << endl; // 错误，因为类的静态函数只能调用静态成员
    cout << "s=" << ++s << endl; // 正确
}
Ctype::Ctype()
{
    a = 0;
    s++;
    cout << "a = " << ++a << endl;
}
int Ctype::s = 0;
