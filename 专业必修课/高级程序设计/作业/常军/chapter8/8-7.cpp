#include <bits/stdc++.h>

class Point {
public:
    int x, y;
    Point(int x, int y) : x(x), y(y) {}

    Point& operator ++() {
        x++;
        y++;
        return *this;
    }

    Point& operator --() {

        x--;
        y--;
        return *this;
    }

    Point operator ++(int) {
        Point temp = *this;
        ++*this;
        return temp;
    }

    Point operator --(int) {
        Point temp = *this;
        --*this;
        return temp;
    }

    
    
};

int main() {
    Point p(1, 2);
    std::cout << (++p).x << " " << p.y << std::endl;
    std::cout << (p++).x << " " << p.y << std::endl;
    std::cout << (--p).x << " " << p.y << std::endl;
    std::cout << (p--).x << " " << p.y << std::endl;
}