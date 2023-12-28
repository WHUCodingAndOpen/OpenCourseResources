// Lab12_1.cpp
// 声明一个异常类CExpection,它有成员函数Reason()中用cout显示异常的类型
// 在函数fn1()中用throw语句触发异常
// 在主函数的try模块中调用fn1(),在catch模块中捕获异常

#include <string>
#include <iostream>

// 声明异常类CException
class CException {
private:
    std::string exceptionType;

public:
    CException(const std::string& type) : exceptionType(type) {}

    void Reason() const {
        std::cout << "Exception type: " << exceptionType << std::endl;
    }
};

// 函数fn1中触发异常
void fn1() {
    throw CException("Custom Exception in fn1");
}

int main() {
    try {
        fn1(); // 调用可能抛出异常的函数
    } catch (const CException& e) {
        std::cout << "Caught an exception: ";
        e.Reason(); // 捕获异常并显示异常的原因
    }

    return 0;
}