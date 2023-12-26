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
