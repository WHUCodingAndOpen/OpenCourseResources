#include <iostream>
enum class CPU_Rank{
    P1 =1,
    P2,
    P3,
    P4,
    P5,
    P6,
    P7
};

class CPU
{
private:
    CPU_Rank rank{};
    int frequency = 0;
    float voltage = 0.0;
public:
    CPU() = default;
    CPU(CPU_Rank,int,float);
    ~CPU();
    void run();
    void stop();
};

CPU::CPU(CPU_Rank r,int f, float v):rank(r),frequency(f),voltage(v){
    std::cout << "cons ... " <<std::endl;
};

CPU::~CPU()
{
    std::cout << "dis..." << std::endl;
}

void
CPU::run(){
    std::cout << "running "<<std::endl;
}
void 
CPU::stop(){
    std::cout << "stopping.." << std::endl;
}

int main(){

    CPU cpu(CPU_Rank::P2,9000,5);

    cpu.run();
    cpu.stop();

    return 0;
}