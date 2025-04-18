// 设计一个异常Exception抽象类
// 在此基础上派生一个OutOfMemory类响应内存不足 
// 一个RangeError类相应输入的数不在指定范围内
// 实现并测试这几个类
#include <iostream>
#include <exception>

class Exception : public std::exception {
public:
    virtual const char* what() const throw() = 0;
};

class OutOfMemory : public Exception {
public:
    const char* what() const throw() {
        return "Out of memory!";
    }
};

class RangeError : public Exception {
public:
    const char* what() const throw() {
        return "Input number is out of range!";
    }
};

int main() {
    try {
        throw OutOfMemory();
    }
    catch (Exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
