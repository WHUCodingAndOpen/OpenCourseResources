#include <iostream>
#include <string>

void reverse(std::string &s, int start, int end) {
    if (start >= end) {
        return;
    }
    std::swap(s[start], s[end]);
    reverse(s, start + 1, end - 1);
}

void reverse(std::string &s) {
    reverse(s, 0, s.length() - 1);
}

int main() {
    std::string s = "Hello, World!";
    reverse(s);
    std::cout<< s << std::endl;
    return 0;
}