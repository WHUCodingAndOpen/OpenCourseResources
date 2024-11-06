#include <iostream>
using namespace std;

class Sample
{
private:
    int x;
    int &rx;
    const float pi;

public:
    Sample(int x1)
        : x(x1), pi(3.14), rx(x){};
    Sample() = default;
    virtual ~Sample() = default;

    // 初始化顺序同成员在类里声明的顺序
    // 与初始化列表顺序无关
    // rx 和 pi 必须被初始化
    void Print()
    {
        cout << "x=" << x << " "
             << "rx=" << rx << " "
             << "pi=" << pi
             << endl;
    }
};

int main()
{
    Sample a(10);
    a.Print();

    return 0;
}
