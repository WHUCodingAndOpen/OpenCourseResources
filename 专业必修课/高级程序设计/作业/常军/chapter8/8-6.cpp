#include <bits/stdc++.h>

class Shape
{
public:
    virtual double getArea() = 0;
    virtual double getPerim() = 0;
};

class Rectangle : public Shape
{
protected:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {};

    double getArea()
    {
        return length * width;
    };

    double getPerim()
    {
        return 2 * (length + width);
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getArea()
    {
        return  3.14159265 * radius * radius;
    };

    double getPerim()
    {
        return 2 * 3.14159265 * radius;
    };
};

int main() {
    Rectangle rect(3, 4);
    Circle circle(5);

    std::cout << "Rectangle area: " << rect.getArea() << std::endl;
    std::cout << "Rectangle perimeter: " << rect.getPerim() << std::endl;
    std::cout << "Circle area: " << circle.getArea() << std::endl;
    std::cout << "Circle perimeter: " << circle.getPerim() << std::endl;

    return 0;
}