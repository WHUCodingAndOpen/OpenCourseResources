#include <iostream>
#define MYPRINT(n) \
    std::cout << #n << " = " << n << std::endl

class Employee
{
private:
    std::string name;
    std::string address;
    std::string city;
    std::string postCode;

public:
    Employee() = default;
    Employee(std::string, std::string, std::string, std::string);
    void changeName(std::string);
    void display();
};
