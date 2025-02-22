# 第十章

## 10-1/10-2

简单说明插入排序的算法思想。初始化数组data[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20},调用教材中的直接插入排序函数模板进行排序。对此函数模板稍作修改，加入输出语句，在每输入一个待排序元素后显示整个数组，观测排序过程中数据的变化，加深对插入排序算法的理解。

解答：  

插入排序的算法思想是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。

源码：

```cpp
#include <iostream>
using namespace std;

template<typename T>
void insertionSort(T data[], int n) {
    for (int i = 1; i < n; ++i) {
        T key = data[i];
        int j = i - 1;

        // 将data[i]插入到已排序的data[0...i-1]中
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;

        // 输出当前数组状态
        cout << "After inserting element " << key << ": ";
        for (int k = 0; k < n; ++k) {
            cout << data[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(data) / sizeof(data[0]);

    insertionSort(data, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
```

运行结果：

```PowerShell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter10> clang++ '.\10-1 10-2.cpp'
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter10> ./a.exe
After inserting element 3: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After inserting element 5: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After inserting element 7: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After inserting element 9: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After inserting element 11: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After inserting element 13: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After inserting element 15: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After inserting element 17: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After inserting element 19: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After inserting element 2: 1 2 3 5 7 9 11 13 15 17 19 4 6 8 10 12 14 16 18 20
After inserting element 4: 1 2 3 4 5 7 9 11 13 15 17 19 6 8 10 12 14 16 18 20
After inserting element 6: 1 2 3 4 5 6 7 9 11 13 15 17 19 8 10 12 14 16 18 20
After inserting element 8: 1 2 3 4 5 6 7 8 9 11 13 15 17 19 10 12 14 16 18 20
After inserting element 10: 1 2 3 4 5 6 7 8 9 10 11 13 15 17 19 12 14 16 18 20
After inserting element 12: 1 2 3 4 5 6 7 8 9 10 11 12 13 15 17 19 14 16 18 20
After inserting element 14: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 17 19 16 18 20
After inserting element 16: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 19 18 20
After inserting element 18: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After inserting element 20: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
Sorted array: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
```

## 10-3/10-4

简单说明选择排序的算法思想。初始化数组data[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20},调用教材中的直接选择排序函数模板进行排序。对此函数模板稍作修改，加入输出语句，在每输入一个待排序元素后显示整个数组，观测排序过程中数据的变化，加深对选择排序算法的理解。

解答：  
选择排序是一种简单直观的排序算法。其基本思想是：每次从未排序的部分中选择最小（或最大）的元素，将其放到已排序部分的末尾。

源码：

```cpp
#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        // 交换当前元素和找到的最小元素
        if (minIndex != i) {
            T temp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = temp;
        }
        // 输出当前数组状态
        cout << "After pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << data[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(data) / sizeof(data[0]);
    selectionSort(data, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}
```

运行结果：

```PowerShell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter10> clang++ '.\10-3 10-4.cpp'
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter10> ./a.exe
After pass 1: 1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20
After pass 2: 1 2 5 7 9 11 13 15 17 19 3 4 6 8 10 12 14 16 18 20
After pass 3: 1 2 3 7 9 11 13 15 17 19 5 4 6 8 10 12 14 16 18 20
After pass 4: 1 2 3 4 9 11 13 15 17 19 5 7 6 8 10 12 14 16 18 20
After pass 5: 1 2 3 4 5 11 13 15 17 19 9 7 6 8 10 12 14 16 18 20
After pass 6: 1 2 3 4 5 6 13 15 17 19 9 7 11 8 10 12 14 16 18 20
After pass 7: 1 2 3 4 5 6 7 15 17 19 9 13 11 8 10 12 14 16 18 20
After pass 8: 1 2 3 4 5 6 7 8 17 19 9 13 11 15 10 12 14 16 18 20
After pass 9: 1 2 3 4 5 6 7 8 9 19 17 13 11 15 10 12 14 16 18 20
After pass 10: 1 2 3 4 5 6 7 8 9 10 17 13 11 15 19 12 14 16 18 20
After pass 11: 1 2 3 4 5 6 7 8 9 10 11 13 17 15 19 12 14 16 18 20
After pass 12: 1 2 3 4 5 6 7 8 9 10 11 12 17 15 19 13 14 16 18 20
After pass 13: 1 2 3 4 5 6 7 8 9 10 11 12 13 15 19 17 14 16 18 20
After pass 14: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 19 17 15 16 18 20
After pass 15: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 17 19 16 18 20
After pass 16: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 19 17 18 20
After pass 17: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 19 18 20
After pass 18: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 19: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
Sorted array: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
```

## 10-5/10-6

简单说明交换排序的算法思想。初始化数组data[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20},调用教材中的直接起泡排序函数模板进行排序。对此函数模板稍作修改，加入输出语句，在每输入一个待排序元素后显示整个数组，观测排序过程中数据的变化，加深对起泡排序算法的理解。

解答：  
交换排序是一种常见的排序算法，其中最典型的实现是起泡排序（Bubble Sort）。起泡排序的基本思想是：通过多次遍历待排序的序列，依次比较相邻的两个元素，如果它们的顺序错误就交换它们的位置。经过每一趟遍历，未排序的最大元素会“冒泡”到序列的末尾。

源码：

```cpp
#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T data[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                // 交换相邻元素
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
        // 输出当前数组状态
        cout << "After pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << data[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(data) / sizeof(data[0]);
    bubbleSort(data, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}
```

运行结果：

```PowerShell
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter10> clang++ '.\10-5 10-6.cpp'
PS C:\Users\fQwQf\Desktop\project\WHU_ALP_2024\chapter10> ./a.exe
After pass 1: 1 3 5 7 9 11 13 15 17 2 4 6 8 10 12 14 16 18 19 20
After pass 2: 1 3 5 7 9 11 13 15 2 4 6 8 10 12 14 16 17 18 19 20
After pass 3: 1 3 5 7 9 11 13 2 4 6 8 10 12 14 15 16 17 18 19 20
After pass 4: 1 3 5 7 9 11 2 4 6 8 10 12 13 14 15 16 17 18 19 20
After pass 5: 1 3 5 7 9 2 4 6 8 10 11 12 13 14 15 16 17 18 19 20
After pass 6: 1 3 5 7 2 4 6 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 7: 1 3 5 2 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 8: 1 3 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 9: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 10: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 11: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 12: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 13: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 14: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 15: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 16: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 17: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 18: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
After pass 19: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
Sorted array: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
```
