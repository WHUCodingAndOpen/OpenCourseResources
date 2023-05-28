#include "Employee.h"

int main(){
    Employee employee("Tom","Whu","Hubei","430072");
    employee.display();
    employee.changeName("Tomcat");
    employee.display();
    return 0;
}