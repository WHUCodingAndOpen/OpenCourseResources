# 第七章实验

## 7-5

定义一个基类Shape，在此基础上派生出Rectangle和Circle，二者带有getArea()函数计算对象的面积。使用Rectangle类创建一个派生类Square()。

## 7-11

定义一个基类BaseClass，从它派生出DerivedClass，BaseClass有成员函数fn1()、fn2()，DerivedClass也有成员函数fn1()、fn2()，在主函数中声明一个DerivedClass的对象，分别用DerivedClass的对象以及BaseClass和DerivedClass的指针来调用fn1()、fn2()，观察运行结果。  

## 7-15

下面的程序能得到预期的结果吗？如何避免类似问题的发生？

```cpp
#include <iostream>
using namespace std;
struct Base1
{
    int x;
};
struct Base2
{
    float y;
};
struct Derived : Base1, Base2
{
};
int main()
{
    Derived *pd = new Derived;
    pd->x = 1;
    pd->y = 2.0f;
    void *pv = pd;
    Base2 *pb = static_cast<Base2 *>(pv);
    cout << pd->y <<" "<< pb->y << endl;
    delete pb;
    return 0;
}
```
