# 第六章作业

## 6-18

下列程序有何问题，请改正；仔细体会使用指针时应避免出现的这个问题。  

```cpp
#include<iostream>
using namespace std;
int fn1(){
int *p=new int(5);
return *p;
}
int main(){
int a=fn1();
cout<<"the value of a is:"<<a;
return 0;
}
```

解答：  
内存泄漏：在fn1函数中，使用new动态分配了一个int类型的内存，但在函数结束时，这个内存没有被释放。这会导致内存泄漏。  
避免方法：在fn1函数中，使用delete释放动态分配的内存。

```cpp
#include<iostream>
using namespace std;

int fn1(){
    int *p = new int(5);
    int value = *p; //保存指针所指向的值
    delete p; //释放动态分配的内存
    return value; //返回值
}

int main(){
    int a = fn1();
    cout << "the value of a is: " << a << endl;
    return 0;
}
```

## 6-20

实现一个名为SimpleCircle的简单圆类。其数据成员int* itsRadius为一个指向其半径值的指针，存放其半径值。设计对数据成员的各种操作，给出这个类的完整实现并测试这个类。  

源码：  

```cpp
#include <bits/stdc++.h>

class SimpleCircle{
    private:

        int* itsRadius;
    public:
        SimpleCircle(int r){
            itsRadius = new int(r);
        }

        ~SimpleCircle(){
            delete itsRadius;
        }

        void setRadius(int radius){
            *itsRadius = radius;
        }

        int getRadius(){
            return *itsRadius;
        }

        float getArea(){
            return 3.14159 * (*itsRadius) * (*itsRadius);
        }
};

int main() {
    // 创建一个SimpleCircle对象，半径为5
    SimpleCircle circle(5);

    // 输出圆的半径和面积
    std::cout << "Radius: " << circle.getRadius() << std::endl;
    std::cout << "Area: " << circle.getArea() << std::endl;

    // 修改半径并输出新的面积
    circle.setRadius(10);
    std::cout << "New Radius: " << circle.getRadius() << std::endl;
    std::cout << "New Area: " << circle.getArea() << std::endl;

    return 0;
}
```

运行结果：  

```Powershell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\charter6> g++ 6-20.cpp
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\charter6> ./a.exe

Radius: 5
Area: 78.5397
New Radius: 10
New Area: 314.159
```

## 6-21

编写一个函数，统计一条英文句子中字母的个数，在主程序中实现输入输出。  

源码：

```cpp
#include <bits/stdc++.h>

int getAlpha(std::string a){
    int ans = 0;
    for (char i : a){
        if(std::isalpha(i)){
            ans ++;
        }
    }
    return ans;
}

int main(){
    std::cout << getAlpha("!!!@#🤣🤣🤣") << std::endl;
    std::cout << getAlpha("#include <bits/stdc++.h>") << std::endl;
    std::cout << getAlpha("MAN,WHAT CAN I SAY!") << std::endl;
    std::cout << getAlpha("Hello world!") << std::endl;
}
```

运行结果：  

```Powershell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\charter6> g++ 6-21.cpp
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\charter6> ./a.exe
0
16
14
10
```

## 6-22

编写函数void reverse(string &s)，用递归函数使字符串s倒序。

源码：

```cpp
#include <iostream>
#include <string>

void reverse(std::string &s, int start, int end) {
    if (start >= end) {
        return;
    }
    std::swap(s[start], s[end]);
    reverse(s, start + 1, end - 1);
}

void reverse(std::string &s) {
    reverse(s, 0, s.length() - 1);
}

int main() {
    std::string s = "Hello, World!";
    reverse(s);
    std::cout<< s << std::endl;
    return 0;
}
```

运行结果：

```Powershell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\charter6> g++ 6-22.cpp
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\charter6> ./a.exe
!dlroW ,olleH
```
