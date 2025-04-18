// 定义一个 dog 类，包含体重和年龄两个成员变量及相应的成员函数。
// 声明一个实例 dog1 ，体重为 5 ，年龄为 10 ，使用 I/O 流把 dog1 的状态写入磁盘文件；
// 再声明一个实例 dog2 ，通过读文件把 dog1 的状态赋给 dog2. 
// 分别使用文本方式和二进制方式操作文件，看看结果有何不同，再看看磁盘文件的 ASCII 码有何不同。

#include <iostream>
#include <fstream>

class Dog {
public:
    int weight, age;

    Dog() = default;
    Dog(int weight, int age) : weight(weight), age(age) {}
    ~Dog() = default;
    
    void display() {
        std::cout << "Weight: " << weight << " Age: " << age << std::endl;
    }
};

int main() {
    Dog dog1(5, 10);

    std::ofstream textFile("dog_text.txt");
    textFile << dog1.weight << " " << dog1.age;
    textFile.close();

    Dog dog2_text(0, 0);
    std::ifstream textFileRead("dog_text.txt");
    textFileRead >> dog2_text.weight >> dog2_text.age;
    textFileRead.close();

    std::ofstream binaryFile("dog_binary.bin", std::ios::binary);
    binaryFile.write(reinterpret_cast<char*>(&dog1), sizeof(Dog));
    binaryFile.close();

    Dog dog2_binary(0, 0);
    std::ifstream binaryFileRead("dog_binary.bin", std::ios::binary);
    binaryFileRead.read(reinterpret_cast<char*>(&dog2_binary), sizeof(Dog));
    binaryFileRead.close();

    return 0;
}