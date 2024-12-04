#include<iostream>
using namespace std;

int fn1(){
    int *p = new int(5);
    int value = *p; // 保存指针所指向的值
    delete p; // 释放动态分配的内存
    return value; // 返回值
}

int main(){
    int a = fn1(); // 直接接收返回的值
    cout << "the value of a is: " << a << endl; // 使用双引号和endl换行
    return 0;
}