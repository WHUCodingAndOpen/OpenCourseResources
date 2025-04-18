#include <iostream>
#define MYPRINT(n) \
    std::cout << #n << " = " << n << std::endl
using namespace std;

class Point
{
private:
    int _x = 0;
    int _y = 0;

public:
    Point &operator++() // 前置++
    {
        ++_x;
        ++_y;
        return *this;
    }

    Point operator++(int) // 后置++
    {
        Point temp;
        temp._x = _x;
        temp._y = _y;

        ++_x;
        ++_y;
        return temp;
    }



        Point &operator--() // 前置--
    {
        --_x;
        --_y;
        return *this;
    }

    Point operator--(int) // 后置--
    {
        Point temp;
        temp._x = _x;
        temp._y = _y;

        --_x;
        --_y;
        return temp;
    }

    friend ostream& operator<<(ostream& out,Point point);
};

ostream& operator<<(ostream& out,Point point){
    out << "{" << point._x << "," <<point._y << "}";
    return out;
}

int main()
{

    Point p;
    MYPRINT(p);
    MYPRINT(p++);
    MYPRINT(++p);
    MYPRINT(p);
    MYPRINT(p--);
    MYPRINT(--p);
    MYPRINT(p);
    return 0;
}