#include <iostream>

// 基类 Vehicle
class Vehicle {
public:
    virtual void Run() {
        std::cout << "Vehicle is running" << std::endl;
    }
    virtual void Stop() {
        std::cout << "Vehicle stopped" << std::endl;
    }
};

// 派生类 Bicycle
class Bicycle : virtual public Vehicle {
public:
    void Run() override {
        std::cout << "Bicycle is running" << std::endl;
    }
    void Stop() override {
        std::cout << "Bicycle stopped" << std::endl;
    }
};

// 派生类 Motorcar
class Motorcar : virtual public Vehicle {
public:
    void Run() override {
        std::cout << "Motorcar is running" << std::endl;
    }
    void Stop() override {
        std::cout << "Motorcar stopped" << std::endl;
    }
};

// 派生类 Motorcycle
class Motorcycle : public Bicycle, public Motorcar {
public:
    void Run() override {
        std::cout << "Motorcycle is running" << std::endl;
    }
    void Stop() override {
        std::cout << "Motorcycle stopped" << std::endl;
    }
};

int main() {
    Vehicle vehicle;
    Bicycle bicycle;
    Motorcar motorcar;
    Motorcycle motorcycle;

    // 直接调用
    vehicle.Run();
    vehicle.Stop();

    bicycle.Run();
    bicycle.Stop();

    motorcar.Run();
    motorcar.Stop();

    motorcycle.Run();
    motorcycle.Stop();

    // 使用 Vehicle 类型的指针
    Vehicle* ptr;

    ptr = &vehicle;
    ptr->Run();
    ptr->Stop();

    ptr = &bicycle;
    ptr->Run();
    ptr->Stop();

    ptr = &motorcar;
    ptr->Run();
    ptr->Stop();

    ptr = &motorcycle;
    ptr->Run();
    ptr->Stop();

    return 0;
}
