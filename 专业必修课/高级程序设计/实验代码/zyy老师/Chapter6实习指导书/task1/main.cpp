#include <iostream>
using namespace std;

void matrixTranspose(int input[3][3], int output[3][3])
{
    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            output[i][j] = input[j][i];
        }
    }
}

int main()
{
    int input[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int output[3][3]{};
    matrixTranspose(input, output);


    cout << "input: " << endl;
    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            cout << input[i][j] << "\t";
        }
        cout << endl;
    }



    cout << "output: " << endl;
    for (auto i = 0; i < 3; i++)
    {
        for (auto j = 0; j < 3; j++)
        {
            cout << output[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}