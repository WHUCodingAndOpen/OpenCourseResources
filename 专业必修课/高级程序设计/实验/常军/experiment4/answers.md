4-10、设计一个用于人事管理的“人员”类。由于考虑到通用性，这里只抽象出所有类型人员都具有的属性：编号、性别、出生日期、身份证号等。其中“出生日期”声明为一个内嵌子对象“日期”。用成员函数实现对人员信息的录入和显示。要求包括：构造函数和析构函数、复制 构造函数、内联成员函数、带默认形参值的成员函数、类的组合。  

源码：

```cpp
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
    void display() {
        cout << year << "-" << month << "-" << day << endl;
    }
};

class Person {
    
private:
    int id;
    string gender;
    Date birthDate;
    string idCard;
public:
    Person(int i, string g, Date b, string ic="12345") : id(i), gender(g), birthDate(b), idCard(ic) {}
    Person(const Person& p) : id(p.id), gender(p.gender), birthDate(p.birthDate), idCard(p.idCard) {}
    void display() {
        cout << "编号：" << id << endl;
        cout << "性别：" << gender << endl;
        cout << "出生日期：";
        birthDate.display();
    }

    ~Person() {
        cout << "析构函数被调用" << endl;
    }
};

int main() {
    Date d(2000, 1, 1);
    Person p(1, "男", d);
    Person p2(p);
    p.display();
    p2.display();
    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ g++ 4-10.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ ./a.out
编号：1
性别：男
出生日期：2000-1-1
编号：1
性别：男
出生日期：2000-1-1
析构函数被调用
析构函数被调用
```

4-13、定义一个Circle类，有数据成员radius（半径），成员函数getArea()，计算圆的面积。构造一个Circle的对象进行测试。  
源码：

```cpp
#include <iostream>
using namespace std;

class Circle {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double getArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    Circle c(5.0);
    cout << "面积为: " << c.getArea() << endl;
    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ g++ 4-13.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ ./a.out
面积为: 78.5
```

4-19、编写一个名为CPU的类，描述一个CPU以下的信息：时钟频率，最大不会超过3000MHz；字长可以是32位或64位；核数可以是单核、双核或四核；是否支持超线程。各项信息要求使用位域来表示。通过输出sizeof(CPU)来观察该类的字节数。  

源码：

```cpp
#include <iostream>
using namespace std;

class CPU {
public:
    unsigned int frequency : 12; //时钟频率，最大不会超过3000MHz
    unsigned int wordLength : 1; //字长可以是32位或64位
    unsigned int coreNum : 2; //核数可以是单核、双核或四核
    unsigned int hyperThread : 1; //是否支持超线程
};

int main() {
    
    cout << sizeof(CPU) << endl;
    return 0;

}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ g++ 4-19.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ ./a.out
4
```

4-20、定义一个复数类Complex，使得下面的代码能够工作：  
```cpp
Complex c1(3,5); //用复数3+5i初始化c1
Complex c2=4.5; //用实数4.5初始化c2
c1.add(c2)； //将c1和3c2相加，结果保存在c1中
c1.show(); //将c1输出（这时的结果应该是7.5+5i）
```

源码：

```cpp
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }
    void show() {
        cout << real << "+" << imag << "i" << endl;
    }
    Complex operator=(double d) {
        real = d;
        imag = 0;
        return *this;
    }
    
    void add(const Complex &c) {
        *this = *this + c ;
    }
};

int main(){
    Complex c1(3, 5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
};
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ g++ 4-20.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ ./a.out
7.5+5i
```

4-12、定义一个DataType（数据类型）类，能处理包括字符型、整型、浮点型三种数据，给出其构造函数。请自行完善主函数及其测试语句。 

源码：

```cpp
#include <iostream>
using namespace std;

class DataType
{
private:
    int i;
    float f;
    char c;
public:
    DataType(int i)
    {
        this->i = i;
        f = 0;
        c = ' ';
    }
    DataType(float f)
    {
        this->f = f;
        i = 0;
        c = ' ';
    }
    DataType(char c)
    {
        this->c = c;
        i = 0;
        f = 0;
    }
    void print()
    {
        cout << "i = " << i << ", f = " << f << ", c = " << c << endl;
    }
    ~DataType()
    {
        cout << "运行析构函数" << endl;
    }
};

int main(){
    DataType d1(1);
    DataType d2(2.2293f);
    DataType d3('a');
    d1.print();
    d2.print();
    d3.print();
    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ g++ 4-12.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ ./a.out
i = 1, f = 0, c =
i = 0, f = 2.2293, c =
i = 0, f = 0, c = a
运行析构函数
运行析构函数
运行析构函数
```

4-14、定义一个Tree（树）类，有采用ages（树龄），成员函数grow(int years)对ages加上years，age()显示Tree对象的ages值。  

源码：

```cpp
#include <iostream>
using namespace std;

class Tree{

public:
    Tree(int a)
    {
        ages = a;
    }
    void grow(int years)
    {
        ages += years;
    }
    void age()
    {
        cout << "树龄为：" << ages << endl;
    }

private:
    int ages;
};

int main() {
    Tree t(10);
    t.age();
    t.grow(5);
    t.age();
    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ g++ 4-14.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment4]
└─$ ./a.out
树龄为：10
树龄为：15
```
