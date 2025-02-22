#include <bits/stdc++.h>

int main() {
    std::stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    std::stack<int> s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);

    std::stack<int> s3;
    s3.push(1);
    s3.push(2);
    s3.push(4);

    std::stack<int> s4;
    s4.push(1);
    s4.push(1);
    s4.push(1);
    s4.push(1);

    std::cout << (s1 == s2) << std::endl; // 输出1，表示s1和s2相等
    std::cout << (s1 < s3) << std::endl; // 输出1，表示s1小于s3
    std::cout << (s1 < s4) << std::endl; // 输出0，表示s1大于s4

    return 0;
}