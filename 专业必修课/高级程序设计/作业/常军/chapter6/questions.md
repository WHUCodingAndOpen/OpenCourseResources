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
cout<<“the value of a is:”<<a;
return 0;
}
```

## 6-20

实现一个名为SimpleCircle的简单圆类。其数据成员int* itsRadius为一个指向其半径值的指针，存放其半径值。设计对数据成员的各种操作，给出这个类的完整实现并测试这个类。  

## 6-21

编写一个函数，统计一条英文句子中字母的个数，在主程序中实现输入输出。  

## 6-22

编写函数void reverse(string &s)，用递归函数使字符串s倒序。
