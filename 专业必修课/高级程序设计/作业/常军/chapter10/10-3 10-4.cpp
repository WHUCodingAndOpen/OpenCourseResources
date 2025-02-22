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