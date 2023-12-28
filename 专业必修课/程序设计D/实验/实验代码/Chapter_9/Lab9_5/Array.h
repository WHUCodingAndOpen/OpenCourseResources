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