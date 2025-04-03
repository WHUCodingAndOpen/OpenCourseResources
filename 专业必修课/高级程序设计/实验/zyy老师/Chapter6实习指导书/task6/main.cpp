#include "Employee.h"
#include <array>

int main(){


    std::array<Employee,5> employeeArray{
        Employee{"employee1","Whu","Hubei","430072"},
        Employee{"employee2","Whu","Hubei","430072"},
        Employee{"employee3","Whu","Hubei","430072"},
        Employee{"employee4","Whu","Hubei","430072"},
        Employee{"employee5","Whu","Hubei","430072"},
        };

    for (auto e:employeeArray){
        e.display();
    }



    return 0;
}