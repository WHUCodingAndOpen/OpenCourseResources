#include <iostream>
#include <cmath>
#define MYPRINT(n) \
    std::cout << #n << " = " << n << std::endl

int main()
{

    double num1 = 0;
    double num2 = 0;

    std::cout << "please input num1 num2 in order:" << std::endl;
    std::cin >> num1;
    std::cin >> num2;

    MYPRINT(pow(num1, num2));

    return 0;
}