//定义一个Cat类，拥有静态数据成员numOfCats，记录Cat的个体数目；静态成员函数getNumOfCats()，读取numOfCats。
//设计程序测试这个类，体会静态数据成员和静态成员函数的用法。

#include <iostream>
using namespace std;
class Cat{
public:
    Cat() { numOfCats++; }
    static int getNumOfCats() { return numOfCats; }

private:
    static int numOfCats;
};
int Cat::numOfCats = 0;
int main() {
    Cat cat_1;
    Cat cat_2;
    Cat cat_3;
    cout << "当前Cat的个体数目: " << Cat::getNumOfCats() << endl;
    return 0;
}
