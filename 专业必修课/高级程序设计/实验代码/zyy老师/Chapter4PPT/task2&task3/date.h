//  日期类的定义。函数成员定义在类体中。
//  date.h
#include <iostream>
using namespace std;
class Date // 定义日期类Date
{
public: // 声明类成员
    Date(int y = 2011, int m = 1, int d = 1);
    ~Date();
    void ShowDate();

private:
    int year;
    int month;
    int day;
}; // 以括号及分号结束，体现封装
