#include <bits/stdc++.h>
using namespace std;

class Boat;
class Car;

int getTotalWeight(Boat b, Car c);

class Boat{
    int weight;

    public:
    Boat(int w){
        weight = w;
    }
    friend int getTotalWeight(Boat b, Car c);
};

class Car{
    int weight;

    public:
    Car(int w){
        weight = w;
    }
    friend int getTotalWeight(Boat b, Car c);
};

int getTotalWeight(Boat b, Car c) {
    return b.weight + c.weight;
};

int main() {
    int boat_weight, car_weight;
    cin >> boat_weight >> car_weight;
    Boat b(boat_weight);
    Car c(car_weight);
    cout << getTotalWeight(b, c) << endl;
}