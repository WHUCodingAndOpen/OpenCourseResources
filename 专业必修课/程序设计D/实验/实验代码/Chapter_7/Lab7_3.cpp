#include <iostream>

class Vehicle{
public:
    Vehicle(int maxSpeed, int weight) : maxSpeed(maxSpeed), weight(weight) {}
    
    void RunStop() {
        std::cout << "Vehicle is running or stopping." << std::endl;
    }
protected:
    int maxSpeed;
    int weight;
};

class Bicycle : virtual public Vehicle {
public:
    Bicycle(int maxSpeed, int weight, int height) : Vehicle(maxSpeed, weight), height(height) {}
protected:
    int height;
};

class Motorcar : virtual public Vehicle {
public:
    Motorcar(int maxSpeed, int weight, int seatNum) : Vehicle(maxSpeed, weight), seatNum(seatNum) {}
protected:
    int seatNum;
};

class Motorcycle : public Bicycle, public Motorcar {
public:
    Motorcycle(int maxSpeed, int weight, int height, int seatNum) : Vehicle(maxSpeed, weight), Bicycle(maxSpeed, weight, height), Motorcar(maxSpeed, weight, seatNum) {}

    void DisplayInfo() {
        std::cout << "MaxSpeed: " << maxSpeed << ", Weight: " << weight << ", Height: " << height << ", SeatNum: " << seatNum << std::endl;
    }
};

int main() {
    Motorcycle myMotorcycle(100, 500, 150, 2);
    myMotorcycle.RunStop();
    myMotorcycle.DisplayInfo();

    return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               