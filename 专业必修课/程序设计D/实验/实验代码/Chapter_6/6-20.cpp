#include <iostream>
#include <cmath>
const double PI = 3.141592635897;
class SimpleCircle {
public:
    SimpleCircle() : itsRadius(new int(0)) {}
    SimpleCircle(int radius) : itsRadius(new int(radius)) {}
    ~SimpleCircle() { delete itsRadius; }

    int getRadius() const { return *itsRadius; }
    void setRadius(int radius) { *itsRadius = radius; }
    double calculatePerimeter() const { return PI * (*itsRadius) * 2; }
    double calculateArea() const { return PI * pow(*itsRadius, 2); }

private:
    int *itsRadius;
};
int main() {
    SimpleCircle circle(5);
    std::cout << "Radius: " << circle.getRadius() << std::endl;
    std::cout << "Perimeter: " << circle.calculatePerimeter() << std::endl;
    std::cout << "Area: " << circle.calculateArea() << std::endl;

    circle.setRadius(10);
    std::cout << "Radius: " << circle.getRadius() << std::endl;
    std::cout << "Perimeter: " << circle.calculatePerimeter() << std::endl;
    std::cout << "Area: " << circle.calculateArea() << std::endl;
    return 0;
}