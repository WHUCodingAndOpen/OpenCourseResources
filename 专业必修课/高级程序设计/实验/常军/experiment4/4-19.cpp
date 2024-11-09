#include <iostream>
using namespace std;

class CPU {
public:
    unsigned int frequency : 12; //时钟频率，最大不会超过3000MHz
    unsigned int wordLength : 1; //字长可以是32位或64位
    unsigned int coreNum : 2; //核数可以是单核、双核或四核
    unsigned int hyperThread : 1; //是否支持超线程
};

int main() {
    
    cout << sizeof(CPU) << endl;
    return 0;

}