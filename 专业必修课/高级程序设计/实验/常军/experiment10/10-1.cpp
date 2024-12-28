#include <iostream>
#include <deque>

int main() {
    std::deque<int> A, B;

    // 向链表A中插入5个元素
    for (int i = 1; i <= 5; ++i) {
        A.push_back(i);
    }

    // 向链表B中插入5个元素
    for (int i = 6; i <= 10; ++i) {
        B.push_back(i);
    }

    // 打印链表A和B
    for(auto i : A) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for(auto i : B) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 将链表B中的元素加入到链表A的尾部
    A.insert(A.end(), B.begin(), B.end());

    // 打印合并后的链表A
    for(auto i : A) {
        std::cout << i << " ";
    }

    return 0;
}