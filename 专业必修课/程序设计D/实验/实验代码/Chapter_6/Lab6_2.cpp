#include <iostream>
using namespace std;

const int SIZE = 3;

void transposeMatrix(int **matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void printMatrix(int **matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int **matrix = new int *[SIZE];
    for (int i = 0; i < SIZE; i++) {
        matrix[i] = new int[SIZE];
    }

    int count = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {  
             
             
            matrix[i][j] = count++;
        }
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    transposeMatrix(matrix);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(matrix);

    for (int i = 0; i < SIZE; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}