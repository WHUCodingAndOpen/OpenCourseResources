//定义一个Tree（树）类，有采用ages（树龄），成员函数grow(intyears)对ages加上years，age()显示Tree对象的ages值。

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Tree{
public:
    Tree() = default;
    Tree(int NewAges) : ages(NewAges) {}
    ~Tree() = default;

    void grow(int years);
    int age() const { return ages; }
private:
    int ages;
};
void Tree::grow(int years) {
    ages += years;
}
int main(){
    Tree pine(0);
    pine.grow(5);
    cout << "The age of pine now is " << pine.age() << endl;
    return 0;
}