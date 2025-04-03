#include <iostream>
#include <memory>
using namespace std;

class Animal
{
protected:
    int age = 0;
public:
    Animal() = default;
};

class Dog:public Animal{
    public:
    void setAge(int newAge){
        age = newAge;
    }
    void display(){
        printf("dog's age is %d.",age);
    }
};




int main(){

    auto dog = make_unique<Dog>();
    dog->setAge(20);

    dog->display();




    return 0;
}