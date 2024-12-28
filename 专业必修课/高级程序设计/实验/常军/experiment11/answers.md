# 第十一章实验

## 11-1

仔细阅读以下的程序，观察程序的输出，注意对输出格式的控制方法。  

- 如果第10行代码报错E0144（`constchar *` 类型的值不能用于初始化`char *` 类型的实体），可用以下方法修改：不改代码，修改项目属性。`项目>>属性>>C/C++>>语言>>符合模式`，将符合模式由是改为否。
- 第4行代码（`#define D(a) T<<#a<<endl; a`）中的#a表示宏替换时将参数a字符串化。
- 提醒：注意观察程序的输出结果存放位置。

```cpp
#include <fstream>
using namespace std;
#define D(a) T<<#a<<endl; a
ofstream T("output.out");

int main() {
    D(int i = 53;)
    D(float f = 470013.141593;)
    const char *s = "Is there any more?";


    D(T.setf(ios::unitbuf);)
    D(T.setf(ios::showbase);)
    D(T.setf(ios::uppercase);)
    D(T.setf(ios::showpos);)
    D(T << i << endl;)
    
    D(T.setf(ios::hex, ios::basefield);)
    D(T << i << endl;)

    D(T.unsetf(ios::uppercase);)
    D(T.setf(ios::oct, ios::basefield);)
    D(T << i << endl;)

    D(T.unsetf(ios::showbase);)
    D(T.setf(ios::dec, ios::basefield);)
    D(T.setf(ios::left, ios::adjustfield);)
    D(T.fill('0');)
    D(T << "fill char:" << T.fill() << endl;)
    D(T.width(8);)
    T << i << endl;
    D(T.setf(ios::right, ios::adjustfield);)
    D(T.width(8);)
    T << i << endl;
    D(T.setf(ios::internal, ios::adjustfield);)
    D(T.width(8);)
    T << i << endl;
    D(T << i << endl;) // without width(10)
    
    D(T.unsetf(ios::showpos);)
    D(T.setf(ios::showpoint);)
    D(T << "prec=" << T.precision() << endl;)
    D(T.setf(ios::scientific, ios::floatfield);)
    D(T << endl << f << endl;)
    D(T.setf(ios::fixed, ios::floatfield);)
    D(T << f << endl;)
    D(T.setf(ios_base::fmtflags(0), ios::floatfield);)
    D(T << f << endl;)
    D(T.precision(16);)
    D(T << "prec=" << T.precision() << endl;)
    D(T << endl << f << endl;)
    D(T.setf(ios::scientific, ios::floatfield);)
    D(T << endl << f << endl;)
    D(T.setf(ios::fixed, ios::floatfield);)
    D(T << f << endl;)
    D(T.setf(ios_base::fmtflags(0), ios::floatfield);)
    D(T << f << endl;)
    D(T.width(8);)
    T << s << endl;
    D(T.width(36);)
    T << s << endl;
    D(T.setf(ios::left, ios::adjustfield);)
    D(T.width(36);)
    T << s << endl;
    D(T.unsetf(ios::showpoint);)
    D(T.unsetf(ios::unitbuf);) 
    return 0;
}
```

output.out：

```txt
int i = 53;
float f = 470013.141593;
T.setf(ios::unitbuf);
T.setf(ios::showbase);
T.setf(ios::uppercase);
T.setf(ios::showpos);
T << i << endl;
+53
T.setf(ios::hex, ios::basefield);
T << i << endl;
0X35
T.unsetf(ios::uppercase);
T.setf(ios::oct, ios::basefield);
T << i << endl;
065
T.unsetf(ios::showbase);
T.setf(ios::dec, ios::basefield);
T.setf(ios::left, ios::adjustfield);
T.fill('0');
T << "fill char:" << T.fill() << endl;
fill char:0
T.width(8);
+5300000
T.setf(ios::right, ios::adjustfield);
T.width(8);
00000+53
T.setf(ios::internal, ios::adjustfield);
T.width(8);
+0000053
T << i << endl;
+53
T.unsetf(ios::showpos);
T.setf(ios::showpoint);
T << "prec=" << T.precision() << endl;
prec=6
T.setf(ios::scientific, ios::floatfield);
T << endl << f << endl;

4.700132e+05
T.setf(ios::fixed, ios::floatfield);
T << f << endl;
470013.156250
T.setf(ios_base::fmtflags(0), ios::floatfield);
T << f << endl;
470013.
T.precision(16);
T << "prec=" << T.precision() << endl;
prec=16
T << endl << f << endl;

470013.1562500000
T.setf(ios::scientific, ios::floatfield);
T << endl << f << endl;

4.7001315625000000e+05
T.setf(ios::fixed, ios::floatfield);
T << f << endl;
470013.1562500000000000
T.setf(ios_base::fmtflags(0), ios::floatfield);
T << f << endl;
470013.1562500000
T.width(8);
Is there any more?
T.width(36);
000000000000000000Is there any more?
T.setf(ios::left, ios::adjustfield);
T.width(36);
Is there any more?000000000000000000
T.unsetf(ios::showpoint);
T.unsetf(ios::unitbuf);
```

## 11-2

编写程序，用二进制文件打开指定的一个文件，在每一行前加行号。

file.txt：

```txt
你说得对，
但是《Rust》是由 Mozilla 自主研发的一款全新零开销抽象编程语言。
语言发生在一个被称作「RAII」的资源管理世界，
在这里，退出作用域的对象将被授予「drop」方法，回收资源之力。
你将扮演一位名为「Ferris」的神秘角色在编码的旅行中邂逅形状各异、生命周期独特的变量们，
和它们一起击败强大的编译错误，找回失散的内存安全——
同时，逐步发掘「Servo」的真相。
```

源码：

```cpp
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
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment11]
└─$ g++ 11-2.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment11]
└─$ ./a.out
```

file.txt:

```txt
1 你说得对，
2 但是《Rust》是由 Mozilla 自主研发的一款全新零开销抽象编程语言。
3 语言发生在一个被称作「RAII」的资源管理世界，
4 在这里，退出作用域的对象将被授予「drop」方法，回收资源之力。
5 你将扮演一位名为「Ferris」的神秘角色在编码的旅行中邂逅形状各异、生命周期独特的变量们，
6 和它们一起击败强大的编译错误，找回失散的内存安全——
7 同时，逐步发掘「Servo」的真相。
```

## 11-3

使用实验10中的学生类数组，输入数据，显示出来，使用I/O流把此数组的内容写入磁盘文件，再显示出文件内容。

源码：

```cpp
#include <iostream>
#include <fstream>
#include <vector>

class Student {
public:
    std::string name;
    int age;
    double grade;

    Student() : name(""), age(0), grade(0.0) {}

    Student(const std::string& name, int age, double grade)
        : name(name), age(age), grade(grade) {}

    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << student.name << " " << student.age << " " << student.grade;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Student& student) {
        is >> student.name >> student.age >> student.grade;
        return is;
    }
};

int main() {
    std::vector<Student> students;
    std::string filename = "students.txt";

    // 输入学生数据
    std::cout << "Enter student data (name age grade):" << std::endl;
    Student temp;
    while (std::cin >> temp) {
        students.push_back(temp);
        if (std::cin.peek() == '\n') break; // 假设一行输入表示结束
    }

    // 显示学生数据
    std::cout << "\nEntered student data:" << std::endl;
    for (const auto& student : students) {
        std::cout << student << std::endl;
    }

    // 写入文件
    std::ofstream out_file(filename, std::ios::binary);
    if (!out_file) {
        std::cerr << "Cannot open file for writing." << std::endl;
        return 1;
    }
    for (const auto& student : students) {
        out_file << student << std::endl;
    }
    out_file.close();

    // 从文件读取并显示内容
    std::ifstream in_file(filename, std::ios::binary);
    if (!in_file) {
        std::cerr << "Cannot open file for reading." << std::endl;
        return 1;
    }
    std::cout << "\nContent from the file:" << std::endl;
    while (in_file >> temp) {
        std::cout << temp << std::endl;
    }
    in_file.close();

    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment11]
└─$ g++ 11-3.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment11]
└─$ ./a.out
Enter student data (name age grade):
fQwQf 114 514

Entered student data:
fQwQf 114 514

Content from the file:
fQwQf 114 514
```

students.txt:

```txt
fQwQf 114 514
```
