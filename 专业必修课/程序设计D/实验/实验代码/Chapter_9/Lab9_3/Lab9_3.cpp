// lab9-3.cpp
#include <iostream>
#include "Queue.h"

int main() {
    Queue<int> queue; // 创建一个整型队列

    // 入队5个整数
    for (int i = 1; i <= 5; ++i) {
        queue.enqueue(i);
        std::cout << "Enqueued: " << i << std::endl;
    }

    std::cout << "Dequeuing..." << std::endl;

    // 出队并显示每个元素
    while (!queue.isEmpty()) {
        int value = queue.dequeue();
        std::cout << "Dequeued: " << value << std::endl;
    }

    return 0;
}
