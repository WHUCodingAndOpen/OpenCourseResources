#include <iostream>
#include <cmath>

const int MAX_LENGTH = 100;

int checkLength(char *str) {
    int length = 0;
    for( ;*str != '\0'; ){
        str++;
        length++;
    }
    return length;
}

void connect_char(char result[], char str1[], char str2[], int total_length) {
    result[total_length] = '\0';
    for(int i = 0; i < checkLength(str1); i++)
        result[i] = str1[i];
    for(int i = checkLength(str1); i < total_length; i++)
        result[i] = str2[i - checkLength(str1)];
}

int main(){
    char str1[MAX_LENGTH / 2], str2[MAX_LENGTH / 2];
    
    std::cout << "Please enter str1: ";
    std::cin.getline(str1, MAX_LENGTH / 2);
    std::cout << "Please enter str2: ";
    std::cin.getline(str2, MAX_LENGTH / 2);

    const int total_length = checkLength(str1) + checkLength(str2);

    char *result = new char[total_length + 1];

    connect_char(result, str1, str2, total_length);

    std::cout << "The result is: " << result << std::endl;

    delete[] result;
    return 0;
}