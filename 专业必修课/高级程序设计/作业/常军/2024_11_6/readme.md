# 2024_11_6

## 4-10

设计一个用于人事管理的“人员”类。由于考虑到通用性，这里只抽象出所有类型人员都具有的属性：编号、性别、出生日期、身份证号等。其中“出生日期”声明为一个“日期”类内嵌子对象。用成员函数实现对人员信息的录入和显示。要求包括：构造函数和析构函数、复制构造函数、内联成员函数、带默认形参值的成员函数、类的组合。  

## 4-13

定义一个 Circle类，有数据成员 radius(半径),成员函数getArea(),计算圆的面积，构造一个 Circle的对象进行测试。  

## 4-16

据下面C++代码绘出相应的 UML图形表示出类 ZRF、类 SSH和类 Person 之间的继承关系。  

```cpp
class Person{
public:
Person(const Persona right);
~Person();
private:
char Name;
int Age;
};
class ZRF:protected Person{};
class SsH:private Person{};
```

## 4-19

编写一个名为 CPU的类，描述一个 CPU的以下信息：时钟频率，最大不会超过3000MHz;字长可以是32位或64位；核数可以是单核、双核或四核；是否支持超线
程。各项信息要求使用位域来表示。通过输出 sizeof(CPU)来观察该类所占的字节数。  

## 4-20

定义一个负数类 Complex,使得下面的代码能够工作：  

```cpp
Complex c1(3,5);//用复数 3+5i初始化c1
Complex c2=4.5; //用实数 4.5初始化 c2
cl.add(c2); //将 c1与 c2相加，结果保存在 c1中
c1.show(); //将 c1输出(这时的结果应该是7.5+5i)
```
