// 在程序中用new分配内存时，如果操作未成功，则用try语句触发一个字符型异常，用catch语句捕获此异常
#include <iostream>

int main() {
    char* ptr = nullptr;
try {
    ptr = new char[1000000000000000];
} catch (const std::bad_alloc& e) {
    try {
        throw 'a';
    } catch (char c) {
        std::cerr << "Caught an exception: " << c << '\n';
    }
}
    return 0;
}