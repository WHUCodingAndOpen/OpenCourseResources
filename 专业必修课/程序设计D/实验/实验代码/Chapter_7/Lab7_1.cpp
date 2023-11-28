#include <iostream>
class Animal {

public:
    int age;
    Animal(int initialAge) : age(initialAge) {}
    int getAge() const { return age; }
};

class Dog : public Animal {
public:
    Dog(int initialAge) : Animal(initialAge) {}
    void setAge(int n) {
        age = n; 
    }
};

int main() {
    Dog myDog(3);
    myDog.setAge(5);
    std::cout << "Dog's Age: " << myDog.getAge() << std::endl;
    return 0;
}