#include <iostream>
using namespace std;
int fn1() {
    int *p = new int (5);
    return *p;
}
int main() {
    int a = fn1();
    cout << "the value of a is: " << a << endl;
    return 0;
}

/*
这段代码中的问题是内存泄漏
在 fn1()中，使用 new 关键字动态分配了一个 int 类型的内存
但是没有使用 delete 关键字来释放这块内存
这块内存在 fn1 函数返回后就无法再访问，但它仍然被占用，无法被其他部分的代码使用
*/