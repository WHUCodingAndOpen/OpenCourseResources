#include <iostream>
#include <memory>
#define MYSTEMP \
    std::cout << __func__ << " was called..." << std::endl
using namespace std;

class BaseClass
{
private:
    int number = 0;
public:
    BaseClass(){
        MYSTEMP;
    }
    ~BaseClass(){

        MYSTEMP;
    };
};

class DerivedClass:public BaseClass
{
private:
    
public:
    DerivedClass(){

        MYSTEMP;
    }
    ~DerivedClass(){

        MYSTEMP;
    }
};




int main(){

    auto derivedClass = make_unique<DerivedClass>();


    return 0;
}