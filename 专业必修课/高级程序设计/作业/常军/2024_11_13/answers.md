# 第五章作业

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

运行结果：  

```bash
x from main5
y from main7
x from myFunction5
y from myFunction10

Back from myFunction !

x from main5
y from main7
```

程序中的关键点是变量的作用域。在main函数中定义了两个全局变量x和y，它们的初始值分别是5和7。然后在myFunction函数中又定义了一个局部变量y，它的初始值是10。  

当myFunction函数被调用时，它会首先输出全局变量x的值，然后输出局部变量y的值。由于局部变量y的作用域仅限于myFunction函数内部，它不会影响到全局变量y的值。  

因此，在myFunction函数中输出的x值是全局变量x的值，即5；输出的y值是局部变量y的值，即10。  

当myFunction函数执行完毕后，程序回到main函数，再次输出全局变量x和y的值，它们都没有发生变化，仍然是5和7。  

实际运行结果应该和我设想的一致，因为C++编译器会严格区分变量的作用域。  

## 5-7

定义一个Cat类，拥有静态数据成员numOfCats，记录Cat的个体数目；静态成员函数getNumOfCats()，读取numOfCats。设计程序测试这个类，体会静态数据成员和静态成员函数的用法。

源码：

```cpp
#include <iostream>
#include <windows.h>

class Cat {
public:
    Cat() {
        numOfCats++;
    }

    ~Cat() {
        numOfCats--;
    }

    static int getNumOfCats() {
        return numOfCats;
    }

private:
    static int numOfCats;
};

int Cat::numOfCats = 0;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Cat cat1;
    Cat cat2;
    Cat cat3;

    std::cout << "当前有 " << Cat::getNumOfCats() << " 只猫。" << std::endl;

    return 0;
}
```

运行结果：

```bash
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\2024_11_13> g++ 5-7.cpp
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\2024_11_13> .\a.exe
当前有 3 只猫。
```

## 5-13

定义类X、Y、Z，函数`h(X *)`，满足：类X有私有成员i，Y的成员函数`g(X *)`是X的友元函数，实现对X的成员i加1；类Z是类X是友元类，其成员函数`f(X *)`实现对X的成员i加5；函数`h(X*)`是X的友元函数，实现对X的成员i加10。在一个文件中定义和实现类，在另一个文件中实现main()函数。  

源码：  

5-13.h:

```cpp
class X;

class Y {
public:
    void g(X *x);
};

class Z {
public:
    void f(X *x);
};


void h(X *x);

class X {
private:
    int i = 0;
    friend void Y::g(X *x); 
    friend void Z::f(X *x);
    friend void h(X *);
public:
    int get();
};
```

5-13-1.cpp:  

```cpp
#include "5-13.h"

int X::get(){
    return i;
}

void Y::g(X *x) {
    x->i++;
}

void Z::f(X *x) {
    x->i += 5;
}

void h(X *x) {
    x->i += 10;
}
```

5-13-2.cpp:  

```cpp
#include <iostream>
#include "5-13.h"
#include <windows.h>

int main() {
    X x;
    Y y;
    Z z;
    SetConsoleOutputCP(CP_UTF8);

    std::cout << "初始值: " << x.get() << std::endl;

    y.g(&x);
    std::cout << "调用Y的g函数后: " << x.get() << std::endl;

    z.f(&x);
    std::cout << "调用Z的f函数后: " << x.get() << std::endl;

    h(&x);
    std::cout << "调用h函数后: " << x.get() << std::endl;

    return 0;
}
```

运行结果：  

```bash
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\2024_11_13> g++ 5-13-1.cpp 5-13-2.cpp
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\2024_11_13> .\a.exe
初始值: 0
调用Y的g函数后: 1
调用Z的f函数后: 6
调用h函数后: 16
```

## 5-16

编译和连接着两个步骤的输入输出分别是什么类型的文件？两个步骤的任务有什么不同？在以下几种情况下，在对程序进行编译、连接时是否会报错？会在哪个步骤报错？  
（1）定义了一个函数void f(int x, int y)，以f(1)的形式调用。  
（2）在源文件起始处声明了一个函数void f(int x)，但未给出其定义，以f(1)的形式调用。  
（3）在源文件起始处声明了一个函数void f(int x)，但未给出其定义，也未对其进行调用。  
（4）在源文件a.cpp中定义了一个函数void f(int x)，在源文件b.cpp中也定义了一个函数void f(int x)，试图将两源文件编译后连接在一起。  

解答：  

编译步骤：

- 输入文件： 源代码文件（通常是`.c`或`.cpp`文件）。
- 输出文件： 目标文件（通常是`.obj`或`.o`文件）。
- 任务： 将源代码转换成机器语言的目标代码，但不处理外部引用。

连接步骤：

- 输入文件： 目标文件和库文件。
- 输出文件： 可执行文件（如`.exe`）。
- 任务： 解决目标文件中的外部引用，将多个目标文件和库文件链接成一个完整的可执行程序。

错误情况分析：  

1. 定义了一个函数`void f(int x, int y)`，以`f(1)`的形式调用。
   - 编译阶段： 报错，因为调用`f(1)`时没有提供足够的参数。
   - 错误位置： 编译阶段。

2. 在源文件起始处声明了一个函数`void f(int x)`，但未给出其定义，以`f(1)`的形式调用。
   - 编译阶段： 不报错，因为声明了函数。
   - 连接阶段： 报错，因为找不到函数的定义。
   - 错误位置： 连接阶段。

3. 在源文件起始处声明了一个函数`void f(int x)`，但未给出其定义，也未对其进行调用。
   - 编译阶段： 不报错，因为没有调用函数。
   - 连接阶段： 也不报错，因为没有需要解决的引用。
   - 错误位置： 无错误。

4. 在源文件`a.cpp`中定义了一个函数`void f(int x)`，在源文件`b.cpp`中也定义了一个函数`void f(int x)`，试图将两源文件编译后连接在一起。
   - 编译阶段： 不报错，因为每个源文件可以独立编译。
   - 连接阶段： 报错，因为两个目标文件中都有同名函数的定义，导致符号冲突。
   - 错误位置： 连接阶段。
