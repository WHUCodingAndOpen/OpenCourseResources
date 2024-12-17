#include <bits/stdc++.h>

class SimpleCircle{
    private:

        int* itsRadius;
    public:
        SimpleCircle(int r){
            itsRadius = new int(r);
        }

        ~SimpleCircle(){
            delete itsRadius;
        }

        void setRadius(int radius){
            *itsRadius = radius;
        }

        int getRadius(){
            return *itsRadius;
        }

        float getArea(){
            return 3.14159 * (*itsRadius) * (*itsRadius);
        }
};

int main() {
    // 创建一个SimpleCircle对象，半径为5
    SimpleCircle circle(5);

    // 输出圆的半径和面积
    std::cout << "Radius: " << circle.getRadius() << std::endl;
    std::cout << "Area: " << circle.getArea() << std::endl;

    // 修改半径并输出新的面积
    circle.setRadius(10);
    std::cout << "New Radius: " << circle.getRadius() << std::endl;
    std::cout << "New Area: " << circle.getArea() << std::endl;

    return 0;
}