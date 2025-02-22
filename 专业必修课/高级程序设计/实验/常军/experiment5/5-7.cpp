#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

class Cat {
public:
    Cat() {
        numOfCats++;
    }

    ~Cat() {
        numOfCats--;
    }

    static int getNumOfCats() {
        return numOfCats;
    }

private:
    static int numOfCats;
};

int Cat::numOfCats = 0;

int main() {
    
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    Cat cat1;
    Cat cat2;
    Cat cat3;

    std::cout << "当前有 " << Cat::getNumOfCats() << " 只猫。" << std::endl;

    return 0;
}