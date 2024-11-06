#include <iostream>
#define MYPRINT(n) \
    std::cout << #n << " = " << n << std::endl

int Func(int x = 5, int y = 10) // 对还是错？为什么？
{
    return x + y;
}

int main()
{
    MYPRINT(Func(1, 2));
    // MYPRINT(Func(,5)); // 报错！
    // 对还是错？为什么？
    // 错误！参数必须从左往右赋值

    MYPRINT(Func(5));

    return 0;
}
