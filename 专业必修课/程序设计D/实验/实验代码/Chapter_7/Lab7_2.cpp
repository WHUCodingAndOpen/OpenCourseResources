#include <iostream>

class BaseClass {
public:
    BaseClass(int num) : Number(num) {
        std::cout << "BaseClass Constructor. Number: " << Number << std::endl;
    }

    ~BaseClass() {
        std::cout << "BaseClass Destructor. Number: " << Number << std::endl;
    }

private:
    int Number;
};

class DerivedClass : public BaseClass {
public:
    DerivedClass(int num, double value) : BaseClass(num), Value(value) {
        std::cout << "DerivedClass Constructor. Value: " << Value << std::endl;
    }

    ~DerivedClass() {
        std::cout << "DerivedClass Destructor. Value: " << Value << std::endl;
    }

private:
    double Value;
};

int main() {
    DerivedClass derivedObj(42, 3.14);

    return 0;
}
