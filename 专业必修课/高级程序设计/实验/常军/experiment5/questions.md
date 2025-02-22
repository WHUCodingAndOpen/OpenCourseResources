# 第五章实验

## 5-3

下面程序的运行结果是什么，实际运行一下，看看和你的设想有何不同？

```cpp
#include <iostream>
using namespace std;

int x = 5, y = 7;

void myFunction()
{
    int y = 10;
    cout <<"x from myFunction" << x <<"\n";
    cout <<"y from myFunction" << y <<"\n\n";
}

int main()
{
    cout <<"x from main" << x <<"\n";
    cout <<"y from main" << y <"\n";
    myFunction();
    cout <<"Back from myFunction !\n\n";
    cout <<"x from main" << x <<"\n";
    cout <<"y from main" << y <"\n";
    return 0;
}
```

## 5-7

定义一个Cat类，拥有静态数据成员numOfCats，记录Cat的个体数目；静态成员函数getNumOfCats()，读取numOfCats。设计程序测试这个类，体会静态数据成员和静态成员函数的用法。

## 5-13

定义类X、Y、Z，函数`h(X *)`，满足：类X有私有成员i，Y的成员函数`g(X *)`是X的友元函数，实现对X的成员i加1；类Z是类X是友元类，其成员函数`f(X *)`实现对X的成员i加5；函数`h(X*)`是X的友元函数，实现对X的成员i加10。在一个文件中定义和实现类，在另一个文件中实现main()函数。