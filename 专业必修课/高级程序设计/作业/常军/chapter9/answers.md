# 第九章

## 9-1

程序中提示输入班级中的学生人数 N，再依次提示用户输入N个人在课程A中的考试成绩，然后计算出平均成绩，显示出来。请使用本章中的数组类模板Array定义浮点型数组存储考试成绩。  

源码：

```cpp
#include <bits/stdc++.h>
#include <windows.h>

template <class T> // 数组类模板定义
class Array
{
private:
    T *list;  // 用于存放动态分配的数组内存首地址
    int size; // 数组大小（元素个数）
public:
    Array(int sz = 50);                       // 构造函数
    Array(const Array<T> &a);                 // 拷贝构造函数
    ~Array();                                 // 析构函数
    Array<T> &operator=(const Array<T> &rhs); // 重载"=“
    T &operator[](int i);                     // 重载"[]”
    const T &operator[](int i) const;
    operator T *(); // 重载到T*类型的转换
    operator const T *() const;
    int getSize() const; // 取数组的大小
    void resize(int sz); // 修改数组的大小
    float average();
};

template <class T>
Array<T>::Array(int sz)
{                       // 构造函数
    assert(sz >= 0);    // sz为数组大小（元素个数），应当非负
    size = sz;          // 将元素个数赋值给变量size
    list = new T[size]; // 动态分配size个T类型的元素空间
}
template <class T>
Array<T>::~Array()
{ // 析构函数
    delete[] list;
}
// 复制构造函数
template <class T>
Array<T>::Array(const Array<T> &a)
{
    size = a.size; // 从对象x取得数组大小，并赋值给当前对象的成员
    // 为对象申请内存并进行出错检查
    list = new T[size];            // 动态分配n个T类型的元素空间
    for (int i = 0; i < size; i++) // 从对象X复制数组元素到本对象
        list[i] = a.list[i];
}

// 重载"="运算符，将对象rhs赋值给本对象。实现对象之间的整体赋值
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
    if (&rhs != this)
    {
        // 如果本对象中数组大小与rhs不同，则删除数组原有内存，然后重新分配
        if (size != rhs.size)
        {
            delete[] list;      // 删除数组原有内存
            size = rhs.size;    // 设置本对象的数组大小
            list = new T[size]; // 重新分配n个元素的内存
        }
        // 从对象X复制数组元素到本对象
        for (int i = 0; i < size; i++)
            list[i] = rhs.list[i];
    }
    return *this; // 返回当前对象的引用
}

// 重载下标运算符，实现与普通数组一样通过下标访问元素
// 并且具有越界检查功能
template <class T>
T &Array<T>::operator[](int n)
{
    assert(n >= 0 && n < size); // 检查下标是否越界
    return list[n];             // 返回下标为n的数组元素
}
template <class T>
const T &Array<T>::operator[](int n) const
{
    assert(n >= 0 && n < size); // 检查下标是否越界
    return list[n];             // 返回下标为n的数组元素
}
// 重载指针转换运算符，将Array类的对象名转换为T类型的指针
template <class T>
Array<T>::operator T *()
{
    return list; // 返回当前对象中私有数组的首地址
}
template <class T>
Array<T>::operator const T *() const
{
    return list; // 返回当前对象中私有数组的首地址
}
// 取当前数组的大小
template <class T>
int Array<T>::getSize() const
{
    return size;
}
// 将数组大小修改为sz
template <class T>
void Array<T>::resize(int sz)
{
    assert(sz >= 0); // 检查sz是否非负
    if (sz == size)  // 如果指定的大小与原有大小一样，什么也不做
        return;
    T *newList = new T[sz];          // 申请新的数组内存
    int n = (sz < size) ? sz : size; // 将sz与size中较小的一个赋值给n
    // 将原有数组中前n个元素复制到新数组中
    for (int i = 0; i < n; i++)
        newList[i] = list[i];
    delete[] list;  // 删除原数组
    list = newList; // 使list指向新数组
    size = sz;      // 更新size
}

template <class T>
float Array<T>::average()
{
    float ans;
    // 将原有数组中前n个元素复制到新数组中
    for (int i = 0; i < size; i++)
        ans += list[i];
    return ans/size;
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int n;
    std::cout << "请输入班级中的学生人数 N: ";
    std::cin >> n;

    Array<float> scores(n); // 使用Array类存储浮点型数组

    for (int i = 0; i < n; ++i)
    {
        float score;
        std::cout << "请输入第 " << i + 1 << " 个学生在课程A中的考试成绩: ";
        std::cin >> score;
        scores[i] = score; // 将成绩添加到数组中
    }

    float averageScore = scores.average(); // 计算平均成绩
    std::cout << "课程A的平均成绩是: " << averageScore << std::endl;

    return 0;
}
```

运行结果：

```Powershell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter9> clang++ 9-1.cpp

PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter9> ./a.exe
请输入班级中的学生人数 N: 6
请输入第 1 个学生在课程A中的考试成绩: 98
请输入第 2 个学生在课程A中的考试成绩: 86
请输入第 3 个学生在课程A中的考试成绩: 78
请输入第 4 个学生在课程A中的考试成绩: 65
请输入第 5 个学生在课程A中的考试成绩: 87
请输入第 6 个学生在课程A中的考试成绩: 76
课程A的平均成绩是: 81.6667
```

## 9-4

在双向链表中使用的结点类与单链表中使用的结点类相比，应有何不同？请声明并实现双向链表中使用的结点类DNode。  

解答：  
在双向链表中，每个结点除了需要存储数据外，还需要存储两个指针，一个指向前一个结点，另一个指向后一个结点。这样，每个结点都可以通过前一个结点的指针访问到前一个结点，也可以通过后一个结点的指针访问到后一个结点。  

源码：

```cpp
template <typename T>
class DNode {
public:
    T data; // 存储数据
    DNode<T>* prev; // 指向前一个结点的指针
    DNode<T>* next; // 指向后一个结点的指针

    // 构造函数
    DNode(T d, DNode<T>* p = nullptr, DNode<T>* n = nullptr) : data(d), prev(p), next(n) {}

    // 析构函数
    ~DNode() {
    // 如果有前一个结点，需要更新前一个结点的next指针
    if (prev != nullptr) {
        prev->next = next;
    }
    // 如果有后一个结点，需要更新后一个结点的prev指针
    if (next != nullptr) {
        next->prev = prev;
    }
}
};

```

## 9-9

在标准C++类库中，对栈类（stack）重载了==、!=、>、>=、<、<=等运算符，以对两个不同的栈进行算术比较运算操作。请构造一个整型栈，以=、<运算为例，对两个栈进行算术比较运算，体会其比较规则，运行程序，观测其输出。  

源码：

```cpp
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
```

运行结果：

```Powershell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter9> clang++ 9-9.cpp

PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter9> ./a.exe
1
1
0
```

解答：  

1. 等价比较（==）：

    只有当两个栈包含的元素数量相等且对应位置的元素完全相同时，结果为 true。

2. 关系比较（<, <=, >, >=）：

    从栈的顶部开始逐个比较对应位置的元素。遇到第一个不同的元素时，以此元素的大小关系作为栈的大小关系。

## 9-13

在标准C++类库中，双向队列类（deque）的成员函数deque::front()返回一个非空双向队列的第一个元素，deque::back()返回一个非空双向队列的最后一个元素。请构造一个字符型双向队列，体会上述几个成员函数的用法。

源码：

```cpp
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
```

运行结果：

```Powershell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter9> clang++ 9-13.cpp
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter9> ./a.exe
First: a
last: c
```
