#include <iostream>
#include <memory>
#define MYSTEMP \
    std::cout << __func__ << " was called..." << std::endl
using namespace std;

class Vehicle
{
private:
    double maxSpeed = 0.0;
    double weight = 0.0;

public:
    Vehicle()
    {
        MYSTEMP;
    }

    ~Vehicle()
    {
        MYSTEMP;
    }
    virtual void run() = 0;

    virtual void stop() = 0;
};

class Bicycle : virtual public Vehicle
{
private:
    double height = 0.0;

public:
    Bicycle()
    {
        MYSTEMP;
    }
    ~Bicycle()
    {
        MYSTEMP;
    }

    void run()
    {
        puts("\nBicycle running...\n");
    }

    void stop()
    {
        puts("Bicycle stopping...\n");
    }
};

class Motorcar : virtual public Vehicle
{
private:
    int seatNum = 0;

public:
    Motorcar()
    {
        MYSTEMP;
    }
    ~Motorcar()
    {
        MYSTEMP;
    }

    void run()
    {
        puts("\nMotorcar running...\n");
    }

    void stop()
    {
        puts("\nMotorcar stopping...\n");
    }
};

class Motorcycle : virtual public Bicycle, virtual public Motorcar
{
public:
    Motorcycle()
    {
        MYSTEMP;
    }
    ~Motorcycle()
    {
        MYSTEMP;
    }

    void run()
    {
        puts("\nMotorcycle running...\n");
    }

    void stop()
    {
        puts("Motorcycle stopping...\n");
    }
};

void test1()
{
    auto v = make_unique<Motorcycle>();
    v->run();
    v->stop();
}

void test2()
{
    auto v2 = make_unique<Bicycle>();
    v2->run();
    v2->stop();
}

void test3()
{
    auto v3 = make_unique<Motorcar>();
    v3->run();
    v3->stop();
}
int main()
{

    test1();
    puts("\n*************************************************************************\n");
    test2();
    puts("\n*************************************************************************\n");
    test3();

    return 0;
}