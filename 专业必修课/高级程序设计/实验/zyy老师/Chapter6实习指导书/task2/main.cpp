#include <iostream>
using namespace std;

void matrixTranspose(int** input, int** output)
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
    int ** input = new int*[3]{};
    for (auto i = 0;i<3;i++){
        input[i] = new int[3]{i*3+1,i*3+2,i*3+3};
    }
    int ** output = new int*[3]{};
    for (auto i = 0;i<3;i++){
        output[i] = new int[3]{};
    }



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




    for (auto i = 0;i<3;i++){
        delete[] input[i];
    }
    delete input;


    for (auto i = 0;i<3;i++){
        delete[] output[i];
    }
    delete output;



    return 0;
}