// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template<typename T>
class Queue {
public:
    Queue() : list() {} // 默认构造函数
    ~Queue() {} // 析构函数

    void enqueue(const T& item) {
        list.insertRear(item); // 在链表尾部插入元素
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return list.deleteFront(); // 删除并返回链表头部元素
    }

    bool isEmpty() const {
        return list.isEmpty(); // 检查链表是否为空
    }

    int getSize() const {
        return list.getSize(); // 返回链表的大小
    }

private:
    LinkedList<T> list; // 使用 LinkedList 作为底层数据结构
};

#endif // QUEUE_H
