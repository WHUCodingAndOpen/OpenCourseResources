#include <iostream>
using namespace std;
int main()
{
    short int i;
    unsigned short int j;
    j = 50000;
    i = j;
    cout << "Short int is :"<< i << endl;
    cout << "Short unsigned int is : "<< j << endl;
    return 0;
}
// 观察思考：将正数50000赋值给变量i以后，输出i的结果是什么？
// 为什么？输出j的结果是什么？为什么