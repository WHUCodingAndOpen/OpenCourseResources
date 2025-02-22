#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::string filename = "file.txt"; // 指定要打开的文件名
    std::ifstream input_file(filename, std::ios::binary); // 以二进制方式打开文件进行读取
    std::vector<std::string> lines; // 用于存储带行号的内容

    if (!input_file) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    std::string line;
    int line_number = 1;
    while (std::getline(input_file, line)) {
        lines.push_back(std::to_string(line_number) + " " + line); // 在每一行前加行号
        ++line_number;
    }

    input_file.close(); // 关闭输入文件

    // 重新以二进制方式打开文件进行写入（这将清空原文件内容）
    std::ofstream output_file(filename, std::ios::binary | std::ios::trunc);
    if (!output_file) {
        std::cerr << "无法打开文件进行写入" << std::endl;
        return 1;
    }

    // 将带有行号的内容写回文件
    for (const auto& numbered_line : lines) {
        output_file.write(numbered_line.c_str(), numbered_line.size());
        output_file.put('\n'); // 添加换行符
    }

    output_file.close(); // 关闭输出文件

    return 0;
}
