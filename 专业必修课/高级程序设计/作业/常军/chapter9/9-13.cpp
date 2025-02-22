#include <bits/stdc++.h>

int main(){
    std::deque<char> d;
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');

    std::cout << "First: " << d.front() << std::endl; // 输出第一个元素
    std::cout << "last: " << d.back() << std::endl; // 输出最后一个元素

    return 0;
}