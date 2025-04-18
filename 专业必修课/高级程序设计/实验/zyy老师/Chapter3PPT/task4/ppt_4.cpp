//  带默认参数的函数
#include <iostream>
using namespace std;
void sum(int num = 10) // 带默认参数函数的定义
{
    int i, s = 0;
    for (i = 1; i <= num; i++)
        s = s + i;
    cout << "sum is:" << s << endl;
}
int main()
{
    sum(100);
    sum();
    return 0;
}