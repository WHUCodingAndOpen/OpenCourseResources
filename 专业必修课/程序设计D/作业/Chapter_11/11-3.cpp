// 使用 I/O 流以文本方式建立一个文件 test1.txt ，写入字符“已成功写入文件！”；
// 使用 I/O 流以文本方式打开文件 test1.txt ，读出其内容并显示。
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outputFile("test1.txt");
    if (outputFile.is_open()) {
        outputFile << "已成功写入文件！" << std::endl;
        outputFile.close();
        std::cout << "文件写入成功" << std::endl;
    } else {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    std::ifstream inputFile("test1.txt");
    if (inputFile.is_open()) {
        std::string content;
        std::getline(inputFile, content);
        inputFile.close();

        std::cout << "文件内容: " << content << std::endl;
    } else {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    return 0;
}