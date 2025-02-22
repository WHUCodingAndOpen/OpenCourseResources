#include <iostream>
#include "queue.h"

int main() {
    Queue<int> queue; // 创建一个整型队列

    // 入队5个整数
    for (int i = 1; i <= 5; ++i) {
        queue.enqueue(i);
    }


    // 出队并显示每个元素
    while (!queue.isEmpty()) {
        int value = queue.dequeue();
        std::cout << value << " ";
    }

    return 0;
}
