#include <iostream>
#define MYSTEMP \
    std::cout << __func__ << " was called..." << std::endl

class CPU
{
private:
    int num;

public:
    CPU()
    {
        MYSTEMP;
    };
    ~CPU()
    {
        MYSTEMP;
    }
};

class RAM
{
private:
    int num;

public:
    RAM()
    {

        MYSTEMP;
    }
    ~RAM()
    {
        MYSTEMP;
    }
};

class CDROM
{
private:
    int num;

public:
    CDROM()
    {
        MYSTEMP;
    }
    ~CDROM()
    {
        MYSTEMP;
    }
};

class Computer
{
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;

public:
    Computer(CPU p1, RAM p2, CDROM p3)
        : cpu(p1), ram(p2), cdrom(p3)
    {
        MYSTEMP;
    }
    ~Computer()
    {
        MYSTEMP;
    }
    void run()
    {
        MYSTEMP;
    }
    void stop()
    {
        MYSTEMP;
    }
};
int main()
{

    CPU cpu;
    RAM ram;
    CDROM cdrom;
    Computer computer(cpu, ram, cdrom);
    computer.run();
    computer.stop();

    return 0;
}
