// 在标准C++类库中，双向队列类(deque)的成员函数deque::front()返回一个非空双向队列的第一个元素，deque::back()返回一个非空双向队列的最后一个元素。
// 请构造一个字符型双向队列，体会上述几个成员函数的用法。
#include <iostream>
#include <deque>

int main() {
    // 创建一个字符型双向队列
    std::deque<char> dequeChar;

    // 向双向队列的后端添加元素
    dequeChar.push_back('A');
    dequeChar.push_back('B');
    dequeChar.push_back('C');

    // 向双向队列的前端添加元素
    dequeChar.push_front('X');
    dequeChar.push_front('Y');
    dequeChar.push_front('Z');

    // 输出双向队列的第一个元素
    std::cout << "The first element is: " << dequeChar.front() << std::endl;

    // 输出双向队列的最后一个元素
    std::cout << "The last element is: " << dequeChar.back() << std::endl;

    // 移除双向队列的第一个元素
    dequeChar.pop_front();
    std::cout << "After pop_front, the first element is: " << dequeChar.front() << std::endl;

    // 移除双向队列的最后一个元素
    dequeChar.pop_back();
    std::cout << "After pop_back, the last element is: " << dequeChar.back() << std::endl;

    return 0;
}
