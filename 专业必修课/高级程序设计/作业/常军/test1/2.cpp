#include <bits/stdc++.h>
//#include "2.h"

class Boat;
class Car;

void getTotalWeight(Boat a,Car b);

class Boat{
    private:
    int weight;

    public:
    Boat(int a);
    friend void getTotalWeight(Boat a,Car b);

};

class Car{
    private:
    int weight;

    public:
    Car(int a);
    friend void getTotalWeight(Boat a,Car b);

};
Boat::Boat(int a){
        weight = a;
};

Car::Car(int a){
        weight = a;
};

void getTotalWeight(Boat a,Car b){
    std:: cout << a.weight + b.weight;
}

int main(){
    int a,b;
    std::cin >> a >> b;
    Boat B(a);
    Car C(b);
    getTotalWeight(B,C);

}