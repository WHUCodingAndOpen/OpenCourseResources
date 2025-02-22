# 第九章实验

## 9-1

编写程序Node.h实现教材例9-5的结点类，并编写程序9-1.cpp实现链表类的基本操作。

Node.h:

```cpp
// Node.h
#ifndef NODE_H
#define NODE_H

// 类模板的定义
template <typename T>
class Node {
public:
    T data; // 数据域

    Node(const T &data, Node<T> *next = 0); // 构造函数
    void insertAfter(Node<T> *p); // 在本结点之后插入一个同类结点p
    Node<T> *deleteAfter(); // 删除本结点的后继节点，并返回其地址
    Node<T> *nextNode(); // 获取后继结点的地址
    const Node<T> *nextNode() const; // 获取后继结点的地址
private:
    Node<T> *next; // 指向后继节点的指针
};


// 类的实现部分
// 构造函数 初始化数据和指针成员
template <typename T>
Node<T>::Node(const T &data, Node<T> *next /* = 0 */) : data(data), next(next) {}

// 返回后继结点的指针
template <typename T>
Node<T> *Node<T>::nextNode() {
    return next;
}

// 返回后继结点的指针
template <typename T>
const Node<T> *Node<T>::nextNode() const {
    return next;
}

// 在当前结点之后插入一个结点p
template <typename T>
void Node<T>::insertAfter(Node<T> *p) {
    p->next = next; // p结点指针域指向当前结点的后继结点
    next = p; // 当前结点的指针域指向p
}


// 删除当前结点的后继结点，并返回其地址
template <typename T>
Node<T> *Node<T>::deleteAfter() {
    Node<T> *tempPtr = next; // 将欲删除的结点地址存储到tempPtr中
    if(next == 0) return 0; // 如果当前结点没有后置结点，则返回空指针
    next = tempPtr->next; // 使当前结点的指针域指向tempPtr的后继结点
    return tempPtr; // 返回被删除的结点的地址
}


#endif
```

9-1.cpp:

```cpp
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
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment9]
└─$ g++ 9-1.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment9]
└─$ ./a.out
1 3
```

## 9-2

编写程序Link.h实现教材例9-6的链表类，在测试程序9-2.cpp中声明两个整型链表A和B，分别插入5个元素，然后把B中的元素加入到A的尾部。

Link.h:

```cpp
#include "Node.h"
#include <stdexcept>

template<typename T>
class LinkedList {
public:
    LinkedList() : front(nullptr), rear(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(-1) {}

    LinkedList(const LinkedList<T> &L) : front(nullptr), rear(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(-1) {
        copy(L);
    }

    ~LinkedList() {
        clear();
    }

    LinkedList<T> &operator=(const LinkedList<T> &L) {
        if (this != &L) {
            clear();
            copy(L);
        }
        return *this;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void reset(int pos = 0) {
        if (pos < 0 || pos > size) {
            throw std::out_of_range("Position out of range");
        }
        position = pos;
        prevPtr = nullptr;
        currPtr = front;
        for (int i = 0; i < pos; ++i) {
            prevPtr = currPtr;
            currPtr = currPtr->nextNode();
        }
    }

    void next() {
        if (currPtr) {
            prevPtr = currPtr;
            currPtr = currPtr->nextNode();
            ++position;
        }
    }

    bool endOfList() const {
        return currPtr == nullptr;
    }

    int currentPosition() const {
        return position;
    }

    void insertFront(const T &item) {
        Node<T> *newNode = new Node<T>(item, front);
        if (isEmpty()) {
            rear = newNode;
        }
        front = newNode;
        ++size;
        reset();
    }

    void insertRear(const T &item) {
        Node<T> *newNode = new Node<T>(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->insertAfter(newNode);
            rear = newNode;
        }
        ++size;
    }

    void insertAt(const T &item) {
        if (position == 0) {
            insertFront(item);
        } else {
            Node<T> *newNode = new Node<T>(item, currPtr);
            prevPtr->insertAfter(newNode);
            currPtr = newNode;
            ++size;
        }
    }

    void insertAfter(const T &item) {
        if (endOfList()) {
            insertRear(item);
        } else {
            Node<T> *newNode = new Node<T>(item, currPtr->nextNode());
            currPtr->insertAfter(newNode);
            if (currPtr == rear) {
                rear = newNode;
            }
            ++size;
        }
    }

    T deleteFront() {
        if (isEmpty()) {
            throw std::out_of_range("Empty list");
        }
        Node<T> *oldFront = front;
        T data = front->data;
        front = front->nextNode();
        delete oldFront;
        if (front == nullptr) {
            rear = nullptr;
        }
        --size;
        reset();
        return data;
    }

    void deleteCurrent() {
        if (currPtr == nullptr) {
            throw std::out_of_range("No current node");
        }
        if (currPtr == front) {
            deleteFront();
        } else {
            prevPtr->deleteAfter();
            Node<T> *tempPtr = currPtr;
            currPtr = currPtr->nextNode();
            delete tempPtr;
            if (currPtr == nullptr) {
                rear = prevPtr;
            }
            --size;
        }
    }

    T &data() {
        if (currPtr == nullptr) {
            throw std::out_of_range("No current node");
        }
        return currPtr->data;
    }

    const T &data() const {
        if (currPtr == nullptr) {
            throw std::out_of_range("No current node");
        }
        return currPtr->data;
    }

    void clear() {
        while (!isEmpty()) {
            deleteFront();
        }
    }

private:
    Node<T> *front, *rear;
    Node<T> *prevPtr, *currPtr;
    int size;
    int position;

    void copy(const LinkedList<T> &L) {
        Node<T> *ptr = L.front;
        while (ptr != nullptr) {
            insertRear(ptr->data);
            ptr = ptr->nextNode();
        }
    }
};
```

9-2.cpp:

```cpp
#include "Link.h"
#include <iostream>

int main() {
    LinkedList<int> A;
    LinkedList<int> B;

    for (int i = 1; i <= 5; ++i) {
        A.insertRear(i);
    }

 
    for (int i = 6; i <= 10; ++i) {
        B.insertRear(i);
    }

  
    B.reset();
    while (!B.endOfList()) {
        A.insertRear(B.data());
        B.next();
    }

    A.reset(); 
    while (!A.endOfList()) {
        std::cout << A.data() << " ";
        A.next();
    }
    std::cout << std::endl;

    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment9]
└─$ g++ 9-2.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment9]
└─$ ./a.out
1 2 3 4 5 6 7 8 9 10
```

## 9-3

编写程序queue.h用链表类实现队列（或栈）类，并编写测试程序9-3.cpp中声明一个整型队列（或栈）对象，插入5个元素，压入队列（或栈），并依次取出并显示出来。

queue.h:

```cpp
#ifndef QUEUE_H
#define QUEUE_H

#include "Link.h"

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

#endif
```

9-3.cpp:

```cpp
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

```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment9]
└─$ g++ 9-3.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment9]
└─$ ./a.out
1 2 3 4 5
```

## 9-4

将直接插入排序、直接选择排序、冒泡排序、顺序查找函数封装到第9章的数组类中，作为成员函数，实现并测试这个类。

Array.h:

```cpp
// Array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

// 数组类模板定义
template <typename T>
class Array {
public:
    Array(int sz = 50); // 构造函数
    Array(const Array<T>&a); // 复制构造函数
    ~Array();
    Array<T>&operator=(const Array<T>&rhs); // 重载"="使数组对象可以整体赋值
    T &operator[] (int i); // 重载"[]",使Array对象可以起到C++普通数组的作用
    const T &operator[](int i) const; // "[]"运算符的const版本
    operator T*(); // 重载到T*类型的转换，使Array对象可以起到C++普通数组的作用
    operator const T *() const; // 到T*类型转换操作符的const版本
    int getSize() const; // 取数组的大小
    void resize(int sz); // 修改数组的大小

    // 排序和查找函数
    void insertSort(); // 直接插入排序
    void selectSort(); // 直接选择排序
    void bubbleSort(); // 冒泡排序
    int sequentialSearch(const T& item) const; // 顺序查找

private:
    T *list; // T类型指针，用于存放动态分配的数组内存首地址
    int size;
};

// 构造函数
template <typename T>
Array<T>::Array(int sz) {
    assert(sz >= 0); // 用于检查在运行时是否满足某个条件，如果条件为假（即断言失败），则程序会终止并生成一个错误消息
    size = sz; // 将元素个数赋值给变量size
    list = new T[size]; // 动态分配size个T类型的元素空间
}

// 析构函数
template <typename T>
Array<T>::~Array() {
    delete[] list;
}

// 复制构造函数
template <typename T>
Array<T>::Array(const Array<T>&other) {
    // 从对象x取得数组大小，并赋值给当前对象的成员
    size = other.size;
    // 为对象申请内存并进行出错检查
    list = new T[size]; // 动态分配n个T类型的元素空间
    // 从对象x复制数组元素到本对象
    for(int i = 0; i < size; i++) {
        list[i] = other.list[i];
    }
}

// 重载"="运算符，将对象rhs赋值给本对象，实现对象之间的整体复制
template <typename T>
Array<T>&Array<T>::operator=(const Array<T> &rhs) {
    if(&rhs != this) {
        // 如果本对象中的数组大小与rhs不同，则删除数组原有内存，然后重新分配
        if(size != rhs.size) {
            delete[] list; // 删除数组原有内存
            size = rhs.size; // 设置本对象的数组大小
            list = new T[size]; // 重新分配n个元素内存
        }
        // 从对象x复制数组元素到本对象
        for(int i = 0; i < size; i++) {
            list[i] = rhs.list[i];
        }
    }
    return *this; // 返回当前对象的引用
}

// 重载下标运算符，实现与普通数组一样通过下标访问元素，并且具有越界检查功能
template <typename T>
T &Array<T>::operator[] (int n) {
    assert(n >= 0 && n < size); // 检查下标是否越界
    return list[n]; // 返回下标为n的数组元素
}

// 重载指针转换运算符，将Array类的对象名转换为T类型的指针，指向当前对象中的私有数组
// 因而可以像使用普通数组首地址一样使用Array类的对象名
template <typename T>
Array<T>::operator T *() {
    return list; // 返回当前对象中私有数组的首地址
}

template <typename T>
Array<T>::operator const T *() const {
    return list; // 返回当前对象中私有数组的首地址
} 


// 取当前数组的大小
template <typename T>
int Array<T>::getSize() const {
    return size;
}

// 将数组大小修改为sz
template <typename T>
void Array<T>::resize(int sz) {
    assert(sz >= 0); // 检查sz是否为非负
    if(sz == size) return; // 如果指定的大小与原有大小一样，什么也不做
    T* newList = new T[sz]; // 申请新的数组内存
    int n =(sz < size) ? sz : size; // 将sz与size中较小的一个赋值给n
    // 将原有数组中的前n个元素复制到新数组中
    for(int i = 0; i < n; i++) {
        newList[i] = list[i];
    }
    delete[] list; // 删除原数组
    list = newList; // 使list指向新数组
    size = sz; // 更新size
}

// 直接插入排序
template <typename T>
void Array<T>::insertSort() {
    for (int i = 1; i < size; ++i) {
        T temp = list[i];
        int j = i - 1;
        while (j >= 0 && list[j] > temp) {
            list[j + 1] = list[j];
            --j;
        }
        list[j + 1] = temp;
    }
}

// 直接选择排序
template <typename T>
void Array<T>::selectSort() {
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (list[j] < list[min]) {
                min = j;
            }
        }
        if (min != i) {
            T temp = list[i];
            list[i] = list[min];
            list[min] = temp;
        }
    }
}

// 冒泡排序
template <typename T>
void Array<T>::bubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (list[j] > list[j + 1]) {
                T temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

// 顺序查找
template <typename T>
int Array<T>::sequentialSearch(const T& item) const {
    for (int i = 0; i < size; ++i) {
        if (list[i] == item) {
            return i; // 找到元素，返回索引
        }
    }
    return -1; // 未找到元素，返回-1
}

#endif
```

9-4.cpp:

```cpp
#include "Array.h"
#include <iostream>

int main() {
    Array<int> arr(10);
    // 填充数组
    std::cout << "原始数组: ";
    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = arr.getSize() - i;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 测试直接插入排序
    arr.insertSort();
    std::cout << "直接插入排序后的数组: ";
    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 重新填充数组
    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = arr.getSize() - i;
    }

    // 测试直接选择排序
    arr.selectSort();
    std::cout << "直接选择排序后的数组: ";
    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 重新填充数组
    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = arr.getSize() - i;
    }

    // 测试冒泡排序
    arr.bubbleSort();
    std::cout << "冒泡排序后的数组: ";
    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 测试顺序查找
    int index = arr.sequentialSearch(5);
    if (index != -1) {
        std::cout << "在索引 " << index << " 处找到数字5" << std::endl;
    } else {
        std::cout << "未找到数字5" << std::endl;
    }

    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment9]
└─$ g++ 9-4.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment9]
└─$ ./a.out
原始数组: 10 9 8 7 6 5 4 3 2 1
直接插入排序后的数组: 1 2 3 4 5 6 7 8 9 10
直接选择排序后的数组: 1 2 3 4 5 6 7 8 9 10
冒泡排序后的数组: 1 2 3 4 5 6 7 8 9 10
在索引 4 处找到数字5
```
