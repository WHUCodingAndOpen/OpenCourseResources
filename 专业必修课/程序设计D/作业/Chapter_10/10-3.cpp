// 简单说明交换排序的算法思想。
// 初始化数组 data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20}
// 用教材中的直接起泡排序函教模板进行排序。
// 对此函教模板捕作修改，加入输出语句，在每输入一个待排序元素后显示整个教组，观测排序过程中教据的变化，加深对起泡排序算法的理解

// 交换排序的算法思想是通过不断交换元素的位置来达到排序的目的。
// 最常见的交换排序算法是冒泡排序，其核心思想是通过一系列的元素比较和交换来将最大（或最小）的元素“冒泡”到序列的一端。
#include <iostream>

template<typename T, size_t N>
void bubbleSort(T (&data)[N]) {
    bool swapped;
    for (size_t i = 0; i < N - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < N - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }

        std::cout << "After iteration " << i + 1 << ": ";
        for (size_t k = 0; k < N; ++k) {
            std::cout << data[k] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    bubbleSort(data);

    std::cout << "Sorted array: ";
    for (int n : data) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
