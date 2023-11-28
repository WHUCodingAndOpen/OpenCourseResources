#include <iostream>
#include <cstring>

int main() {
    std::string str1, str2;
    
    std::cout << "Please enter str1: ";
    std::getline(std::cin, str1);
    std::cout << "Please enter str2: ";
    std::getline(std::cin, str2);

    std::string result = str1 + str2;

    std::cout << "The result is: " << result << std::endl;
    
    return 0;
}