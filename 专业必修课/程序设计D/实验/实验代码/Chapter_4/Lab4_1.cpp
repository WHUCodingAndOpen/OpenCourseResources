#include <iostream>
#include <cmath>
using namespace std;

enum CPU_Rank {P1 = 1, P2, P3, P4, P5, P6, P7};

class CPU{
public:
    CPU() = default;
    CPU(CPU_Rank rank,int frequency, float voltage) : rank(rank),frequency(frequency), voltage(voltage) {
        cout << "Create a new CPU successfully!" << endl;
    }
    
    ~CPU(){
        cout << "Destructor function has played a role." << endl;
    }

    CPU_Rank getRank() const { return rank; }
    int getFrequency() const { return frequency; }
    float getVoltage() const { return voltage; }

    void setRank(CPU_Rank r) { rank = r; }
    void setFrequency(int f) { frequency = f; }
    void setVoltage(float v) { voltage = v; }


    void run() { cout << "CPU is running!" << endl;}
    void stop() { cout << "CPU has stopped!" << endl;}
private:
    CPU_Rank rank;
    int frequency;
    float voltage;
};

int main(){
    CPU a(P6,300,2.8);
    a.run();
    a.stop();

    return 0;
}