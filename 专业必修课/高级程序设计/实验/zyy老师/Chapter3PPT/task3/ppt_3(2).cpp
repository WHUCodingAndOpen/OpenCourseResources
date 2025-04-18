// 参数个数不同的函数重载
#include <iostream>
using namespace std;
int Add(int x, int y) // 2个形参
{
    return x + y;
}
int Add(int x, int y, int z) // 3个形参
{
    return x + y + z;
}
int main()
{
    int a = 3, b = 4, c = 5;
    cout << a << "+" << b << "=" << Add(a, b) << endl;
    cout << a << "+" << b << "+" << c << "=" << Add(a, b, c) << endl;
    return 0;
}
