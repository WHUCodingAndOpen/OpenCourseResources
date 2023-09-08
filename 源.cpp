#define _CRT_SECURE_NO_WARNINGS 1	
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;

int main() {
    string folderPath = "D:\\Setup\\Files\\Files";
    string targetContent = "MSC2023";

    for (const auto& entry : filesystem::directory_iterator(folderPath)) 
    {
        if (entry.path().extension() == ".txt") 
        {
            ifstream file(entry.path());
            string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            file.close();

            if (content == targetContent) 
            {
                cout << "The path to the target file: \n" << entry.path().string() << endl;
                break;
            }
        }
    }

    return 0;
}