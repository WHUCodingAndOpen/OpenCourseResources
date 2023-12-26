#include "Node.h"
#include <iostream>

int main() {

    Node<int> *head = new Node<int>(1); // 创建头结点
    Node<int> *node2 = new Node<int>(2); // 创建第二个节点
    head->insertAfter(node2); // 将第二个节点插入头结点之后


    Node<int> *node3 = new Node<int>(3); // 创建第三个节点
    head->insertAfter(node3); // 将第三个节点插入头结点之后


    Node<int> *deletedNode = node3->deleteAfter(); // 删除第三个节点之后的节点并获取其地址
    delete deletedNode; // 释放被删除节点的内存


    Node<int> *current = head; // 从头结点开始遍历
    while (current != nullptr) {
        std::cout << current->data << " "; // 打印当前节点数据
        current = current->nextNode(); // 移动到下一个节点
    }
    std::cout << std::endl;


    while (head != nullptr) {
        Node<int> *next = head->nextNode(); // 获取下一个节点的地址
        delete head; // 删除当前节点
        head = next; // 移动到下一个节点
    }

    return 0;
}
