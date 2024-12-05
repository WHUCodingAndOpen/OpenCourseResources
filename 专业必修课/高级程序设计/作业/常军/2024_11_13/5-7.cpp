#include <iostream>
#include <windows.h>

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
    SetConsoleOutputCP(CP_UTF8);
    Cat cat1;
    Cat cat2;
    Cat cat3;

    std::cout << "当前有 " << Cat::getNumOfCats() << " 只猫。" << std::endl;

    return 0;
}