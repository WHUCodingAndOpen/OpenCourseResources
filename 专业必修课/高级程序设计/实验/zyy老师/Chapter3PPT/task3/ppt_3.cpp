// 参数类型不同的函数重载
#include <iostream>
using namespace std;
int abs(int x) // 形参为整型
{
    return x > 0 ? x : -x;
}
double abs(double x) // 形参为双精度型
{
    return x > 0 ? x : -x;
}
long abs(long x) // 形参为长整型
{
    return x > 0 ? x : -x;
}
int main()
{
    std::abs(5.5);
    int x1 = 4;
    double x2 = 5.5;
    long x3 = 6L;
    // 从上到下依此调用函数 123
    cout << "|x1|=" << ::abs(x1) << endl;
    cout << "|x2|=" << ::abs(x2) << endl;
    // call of overloaded 'abs(double&)' is ambiguous
    // 使用 C++17会报错，原因可能是标准库引入了 abs 这个函数，导致函数指定不明确
    // 指定为全局作用域或者不指定 namespace std 即可解决！
    // 以下是对照
    cout << "conflict with std:abs() => std: |x2| = " << std::abs(x2) << endl;

    cout << "|x3|=" << ::abs(x3) << endl;
    return 0;
}
