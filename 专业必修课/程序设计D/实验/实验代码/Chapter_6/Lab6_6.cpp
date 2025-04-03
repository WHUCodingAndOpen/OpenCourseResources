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
    const int Number = 5;
    Employee employees[Number]={
        Employee("John Doe", "123 Main St", "Anytown", "12345"),
        Employee("Jane Doe", "456 Oak St", "Sometown", "67890"),
        Employee("Jim Brown", "789 Pine St", "Anytown", "12345"),
        Employee("Jake White", "321 Elm St", "Othertown", "67890"),
        Employee("Jill Black", "654 Willow St", "Sametown", "12345")
    };
    for(int i = 0; i < Number; i++){
        employees[i].display();
        std::cout << std::endl;
    }
    employees[0].change_name("New Name");
    employees[0].display();
    std::cout << std::endl;
    return 0;
}