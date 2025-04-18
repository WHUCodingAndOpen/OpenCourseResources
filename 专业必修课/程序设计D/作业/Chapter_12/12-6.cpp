// 定义一个异常类CException，有成员函数Reason()，用来显示异常的类型
// 定义函数fn1()触发异常，在主函数的try模块中调用fn1()，在catch模块中捕获异常
// 观察程序的执行流程
#include <iostream>
#include <string>

class CException {
public:
    std::string Reason() {
        return "Exception occurred";
    }
};

void fn1() {
    throw CException();
}

int main() {
    try {
        fn1();
    }
    catch (CException& e) {
        std::cout << "Caught exception: " << e.Reason() << std::endl;
    }

    return 0;
}
