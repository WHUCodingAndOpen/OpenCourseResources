# 第十一章

## 11-3/11-4

使用 I/O 流以文本方式建立一个文件test1.txt，写入字符“已成功写入文件！”；使用I/O 流以文本方式打开文件test1.txt，读出其内容并显示。

源码：

```cpp
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
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter11]
└─$ g++ 11-3\ 11-4.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter11]
└─$ ./a.out
文件内容: 已成功写入文件！
```

## 11-6

定义一个dog 类，包含体重和年龄两个成员变量及相应的成员函数。声明一个实例dog1，体重为5，年龄为10，使用I/O流把dog1的状态写入磁盘文件；再声明一个实例dog2，通过读文件把dog1的状态赋给dog2。分别使用文本方式和二进制方式操作文件，看看结果有何不同，再看看磁盘文件的ASCII码有何不同。

源码：

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>

class Dog
{
private:
    double weight;
    int age;

public:
    Dog() : weight(0), age(0) {}
    Dog(double w, int a) : weight(w), age(a) {}

    void setWeight(double w) { weight = w; }
    void setAge(int a) { age = a; }

    double getWeight() const { return weight; }
    int getAge() const { return age; }

    void print() const
    {
        std::cout << "Weight: " << weight << ", Age: " << age << std::endl;
    }
};

void writeDogToFileText(const Dog &dog, const std::string &filename)
{
    std::ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << dog.getWeight() << " " << dog.getAge() << std::endl;
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void readDogFromFileText(Dog &dog, const std::string &filename)
{
    std::ifstream inFile(filename);
    if (inFile.is_open())
    {
        double weight;
        int age;
        inFile >> weight >> age;
        dog.setWeight(weight);
        dog.setAge(age);
        inFile.close();
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void writeDogToFileBinary(const Dog &dog, const std::string &filename)
{
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile.is_open())
    {
        outFile.write(reinterpret_cast<const char *>(&dog), sizeof(Dog));
        outFile.close();
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void readDogFromFileBinary(Dog &dog, const std::string &filename)
{
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open())
    {
        inFile.read(reinterpret_cast<char *>(&dog), sizeof(Dog));
        inFile.close();
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
}

int main()
{
    Dog dog1(5, 10);
    Dog dog2;

    // Text mode
    writeDogToFileText(dog1, "dog1_text.txt");
    readDogFromFileText(dog2, "dog1_text.txt");
    std::cout << "Dog2 after reading from text file: ";
    dog2.print();

    // Binary mode
    writeDogToFileBinary(dog1, "dog1_binary.bin");
    readDogFromFileBinary(dog2, "dog1_binary.bin");
    std::cout << "Dog2 after reading from binary file: ";
    dog2.print();

    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter11]
└─$ g++ 11-6.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter11]
└─$ ./a.out
Dog2 after reading from text file: Weight: 5, Age: 10
Dog2 after reading from binary file: Weight: 5, Age: 10
```

## 11-9

编写程序实现如下功能：打开指定的一个文本文件，在每一行前加行号。

源码：

```cpp
#include <iostream>
#include <fstream>
#include <string>

void addLineNumbers(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inFile(inputFilename);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open input file: " << inputFilename << std::endl;
        return;
    }

    std::ofstream outFile(outputFilename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open output file: " << outputFilename << std::endl;
        inFile.close();
        return;
    }

    std::string line;
    int lineNumber = 1;

    while (std::getline(inFile, line)) {
        outFile << std::right << lineNumber << ": " << line << std::endl;
        lineNumber++;
    }

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFilename;
    std::string outputFilename;

    std::cout << "Enter the input file name: ";
    std::cin >> inputFilename;
    std::cout << "Enter the output file name: ";
    std::cin >> outputFilename;

    addLineNumbers(inputFilename, outputFilename);

    return 0;
}
```

input.txt:

```txt
你说得对，
但是《Rust》是由 Mozilla 自主研发的一款全新零开销抽象编程语言。
语言发生在一个被称作「RAII」的资源管理世界，
在这里，退出作用域的对象将被授予「drop」方法，回收资源之力。
你将扮演一位名为「Ferris」的神秘角色在编码的旅行中邂逅形状各异、生命周期独特的变量们，
和它们一起击败强大的编译错误，找回失散的内存安全——
同时，逐步发掘「Servo」的真相。
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter11]
└─$ g++ 11-9.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/chapter11]
└─$ ./a.out
Enter the input file name: input.txt
Enter the output file name: output.txt
```

output.txt:

```txt
1: 你说得对，
2: 但是《Rust》是由 Mozilla 自主研发的一款全新零开销抽象编程语言。
3: 语言发生在一个被称作「RAII」的资源管理世界，
4: 在这里，退出作用域的对象将被授予「drop」方法，回收资源之力。
5: 你将扮演一位名为「Ferris」的神秘角色在编码的旅行中邂逅形状各异、生命周期独特的变量们，
6: 和它们一起击败强大的编译错误，找回失散的内存安全——
7: 同时，逐步发掘「Servo」的真相。
```
