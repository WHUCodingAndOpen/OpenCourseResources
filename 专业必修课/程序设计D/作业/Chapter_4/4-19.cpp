#include <iostream>

using namespace std;

class CPU
{
public:
    CPU() : clockFrequency(0), wordLength(0), coreCount(0), hyperThreading(false) {}

    // 输出sizeof(CPU)
    void printSize()
    {
        cout << "Size of CPU: " << sizeof(CPU) << " bytes" << endl;
    }

private:
    // 时钟频率，最大不超过3000MHz
    unsigned int clockFrequency : 12; // 12位可以表示0-4095，对应0-4095MHz
    // 字长可以是32位或64位
    unsigned int wordLength : 1; // 1位表示32位或64位
    // 核数可以是单核、双核或四核
    unsigned int coreCount : 2; // 2位表示0-3，对应单核、双核、四核
    // 是否支持超线程
    bool hyperThreading : 1; // 1位表示是否支持超线程
};

int main()
{
    CPU myCPU;
    myCPU.printSize();

    return 0;
}