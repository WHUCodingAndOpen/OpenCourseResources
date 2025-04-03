#include <iostream>
#include <cmath>
using namespace std;
enum CPU_Rank { P1 = 1, P2, P3, P4, P5, P6, P7 };

class CPU{
public:
    CPU() = default;
    CPU(CPU_Rank rank,int frequency, float voltage) : rank(rank),frequency(frequency), voltage(voltage) {
        cout << "Create a new CPU successfully!" << endl;
    }
    
    ~CPU(){
        cout << "CPU Destructor function has played a role." << endl;
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

enum RAM_Type { DDR3, DDR4, DDR5 };

class RAM {
public:
    RAM() = default;
    RAM(RAM_Type type, int capacityGB) : type(type), capacityGB(capacityGB) {
        cout << "Create a new RAM successfully!" << endl;
    }

    ~RAM() {
        cout << "RAM Destructor function has played a role." << endl;
    }

    RAM_Type getType() const { return type; }
    int getCapacityGB() const { return capacityGB; }

    void setType(RAM_Type t) { type = t; }
    void setCapacityGB(int capacity) { capacityGB = capacity; }

    void readData() { cout << "RAM is reading data!" << endl; }
    void writeData() { cout << "RAM is writing data!" << endl; }

private:
    RAM_Type type;
    int capacityGB;
};

enum CDROM_Type {
    DVD,
    BluRay
};

class CDROM {
public:
    CDROM() = default;
    CDROM(CDROM_Type type, int speed) : type(type), speed(speed) {
        cout << "Create a new CDROM successfully!" << endl;
    }

    ~CDROM() {
        cout << "CDROM Destructor function has played a role." << endl;
    }

    CDROM_Type getType() const { return type; }
    int getSpeed() const { return speed; }

    void setType(CDROM_Type t) { type = t; }
    void setSpeed(int s) { speed = s; }

    void readDisk() { cout << "CDROM is reading disk!" << endl; }
    void ejectDisk() { cout << "CDROM has ejected the disk!" << endl; }

private:
    CDROM_Type type;
    int speed;
};


class Computer {
public:
    Computer() = default;
    Computer(CPU cpu, RAM ram, CDROM cdrom) : cpu(cpu), ram(ram), cdrom(cdrom) {
        cout << "Create a new Computer successfully!" << endl;
    }

    ~Computer() {
        cout << "Computer Destructor function has played a role." << endl;
    }

private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
};

int main() {

    CPU cpu(P4, 3000, 1.2);
    RAM ram(DDR4, 16);
    CDROM cdrom(DVD, 8);

    Computer myComputer(cpu, ram, cdrom);

    return 0;
}