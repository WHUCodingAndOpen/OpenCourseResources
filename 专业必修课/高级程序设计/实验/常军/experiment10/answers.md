# 第十章实验

## 10-1

使用C++标准模板库（STL）中的双向队列（deque）重新实现实验9中的实验任务2。

源码：

```cpp
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
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment10]
└─$ g++ 10-1.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment10]
└─$ ./a.out
1 2 3 4 5
6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
```

## 10-2

声明一个整型数组，使用C++标准模板库（STL）中的查找算法`find()`进行数据的查找，然后应用排序算法`sort()`，并配合使用标准函数对象 `greater<T>` 对数据进行升序和降序排序。

源码：

```cpp
#include "bits/stdc++.h"

int main() {
    // 声明一个整型数组
    std::vector<int> numbers = {50, 40, 30, 20, 10};

    // 使用find()查找元素
    int target = 30;
    auto it = std::find(numbers.begin(), numbers.end(), target);

    if (it != numbers.end()) {
        std::cout << "元素 " << target << " 在数组中的位置是: " << std::distance(numbers.begin(), it) << std::endl;
    } else {
        std::cout << "元素 " << target << " 不在数组中" << std::endl;
    }

    // 使用sort()进行升序排序
    std::sort(numbers.begin(), numbers.end());

    // 输出排序后的数组
    std::cout << "升序排序后的数组: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 使用sort()和greater<T>()进行降序排序
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // 输出排序后的数组
    std::cout << "降序排序后的数组: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment10]
└─$ g++ 10-2.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment10]
└─$ ./a.out
元素 30 在数组中的位置是: 2
升序排序后的数组: 10 20 30 40 50
降序排序后的数组: 50 40 30 20 10
```
