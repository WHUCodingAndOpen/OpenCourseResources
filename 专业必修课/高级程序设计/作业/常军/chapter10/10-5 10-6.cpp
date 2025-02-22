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