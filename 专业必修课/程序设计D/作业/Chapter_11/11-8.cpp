// 提示用户输入一个十进制整数，分别用十进制、八进制和十六进制形式输出。
#include <iostream>

int main() {
    int decimal;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    std::cout << "Decimal: " << decimal << std::endl;
    std::cout << "Octal: " << std::oct << decimal << std::endl;
    std::cout << "Hexadecimal: " << std::hex << decimal << std::endl;

    return 0;
}
