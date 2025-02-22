#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 写入文件
    ofstream outFile("test1.txt");
    if (outFile.is_open()) {
        outFile << "已成功写入文件！";
        outFile.close();
    } else {
        cout << "无法打开文件进行写入！" << endl;
    }

    // 读取文件
    ifstream inFile("test1.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << "文件内容: " << line << endl;
        }
        inFile.close();
    } else {
        cout << "无法打开文件进行读取！" << endl;
    }

    return 0;
}