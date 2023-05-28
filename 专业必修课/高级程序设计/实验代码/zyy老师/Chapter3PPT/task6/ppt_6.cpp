// 观察此函数的运行结果，
// 用内联函数实现求两个整数中最大数。
#include <iostream>
using namespace std;
inline int max(int x, int y) // 内联函数
{
    return x > y ? x : y;
}
int main()
{
    int a, b, c;
    cout << "Input two data:";
    cin >> a >> b;
    cout << "The max is:" << max(a, b) << endl;
    return 0;
}
