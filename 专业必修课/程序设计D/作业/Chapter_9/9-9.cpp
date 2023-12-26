// 在标准C++类库中，对栈类（stack）重载了==、!=、>、>=、<、<=等运算符，以对两个不同的栈进行算术比较运算操作。
// 请构造一个整型栈，以=、<运算为例，对两个栈进行算术比较运算，体会其比较规则，运行程序，观测其输出。
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack1;
    std::stack<int> stack2;

    // 向栈中添加元素
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    stack2.push(1);
    stack2.push(2);
    stack2.push(3);

    // 比较两个栈是否相等
    if (stack1 == stack2) {
        std::cout << "stack1 is equal to stack2" << std::endl;
    } else {
        std::cout << "stack1 is not equal to stack2" << std::endl;
    }

    // 修改 stack2
    stack2.pop();
    stack2.push(4);

    // 比较两个栈的大小
    if (stack1 < stack2) {
        std::cout << "stack1 is less than stack2" << std::endl;
    } else {
        std::cout << "stack1 is not less than stack2" << std::endl;
    }

    return 0;
}
