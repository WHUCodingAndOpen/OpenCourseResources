#include <iostream>
#include <cmath>
#include <cstring>

class Employee {
public:
    Employee(std::string name, std::string streetAdress, std::string city, std::string postCode) : name(name), streetAdress(streetAdress), city(city), postCode(postCode) {}
    ~Employee() = default;
    void change_name(std::string name); 
    void display() const {
        std::cout << "Name: " << name << "\nStreet Adress: " << streetAdress << "\nCity: " << city << "\nPostcode: " << postCode << std::endl;
    }
private:
    std::string name, streetAdress, city, postCode;


};
void Employee::change_name(std::string name) {
    this->name = name;
}
int main() {
    Employee employee("John Doe", "123 Main St", "Anytown", "12345");
    employee.display();
    std::cout << std::endl;
    employee.change_name("Jane Doe");
    employee.display();
    return 0;
}