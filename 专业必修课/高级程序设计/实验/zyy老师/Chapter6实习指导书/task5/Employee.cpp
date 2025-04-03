#include "Employee.h"

Employee::Employee(std::string name0,
 std::string address0, 
 std::string city0,
  std::string postCode0):name(name0),address(address0),city(city0),postCode(postCode0){};
  void Employee::changeName(std::string newName){
    this->name = newName;
  }

  void Employee::display(){
    // auto &[a,b,c,d] = *this;
    MYPRINT(name);
    MYPRINT(address);
    MYPRINT(city);
    MYPRINT(postCode);
  }


