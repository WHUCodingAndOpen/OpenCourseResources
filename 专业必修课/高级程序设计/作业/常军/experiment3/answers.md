# 实验3

## 3-7

完成函数，参数为两个unsigned short int型数，返回值为第一个参数除以第二个参数的结果，数据类型为short int；如果第二个参数为0，则返回值为-1。在主程序中实现输入输出。注意观察函数的参数传入传出、返回值。  

源码：

```c++
#include <iostream>

using namespace std;

short int devide(unsigned short int a,unsigned short int b)
{   if (b!=0){
        return a / b;
    }else{
        return -1;
    }
};

int main()
{   unsigned short int a,b;
    cout << "请输入a: ";
    cin >> a ;
    cout << "请输入b: ";
    cin >> b ;
    cout << "结果为: " << devide(a,b);
    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/项目/WHU_ALP_2024/2024_10_28]
└─$ g++ 3-7.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/项目/WHU_ALP_2024/2024_10_28]
└─$ ./a.out
请输入a: 4
请输入b: 0
结果为: -1
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/项目/WHU_ALP_2024/2024_10_28]
└─$ ./a.out
请输入a: 6
请输入b: 5
结果为: 1
```

## 3-13

递归的方法编写函数求 Fibonacci级数，公式为
$$ F_n =F_{n-1}  +F_{n-2},(n>2),F_1=F_2=1 $$
观察递归调用的过程。  

源码：

```c++
#include <iostream>

using namespace std;

int Fibonacci(int n) {
    if (n <= 1) return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n;
    cout << "请输入n: ";
    cin >> n;
    cout << Fibonacci(n);
    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/项目/WHU_ALP_2024/2024_10_28]
└─$ g++ 3-13.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/项目/WHU_ALP_2024/2024_10_28]
└─$ ./a.out
请输入n: 2
1
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/项目/WHU_ALP_2024/2024_10_28]
└─$ ./a.out
请输入n: 5
5
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/项目/WHU_ALP_2024/2024_10_28]
└─$ ./a.out 
请输入n: 42
267914296
```

## 3-15

写递归函数 getPower 计算$x^y$,在同一个程序中针对整型和实型实现两个重载的
函数：

```c++  
int getPower(int x, int y); //整型版本，当y<0时，返回0  
double getPower(double x,int y);  //实型版本  
```

在主程序中实现输入输出，分别输入一个整数a 和一个实数b作为底数，再输入一个
整数m作为指数，输出$a^m$和$b^m$。另外请读者思考，如果在调用getPower 函数计算
$a^m$时希望得到一个实型结果(实型结果表示范围更大，而且可以准确表示m<0时
的结果)，该如何调用?注意观察递归调用的过程。

源码：

```c++
#include <iostream>
#include <cmath>
using namespace std;

int getPower(int x, int y){
    return pow(x,y);
}

double getPower(double x,int y){
    return pow(x,y);
}


int main(){
    int a,m;
    double b;
    cout << "请依次输入a,b,m: ";
    cin >> a >> b >> m;
    cout << getPower(a,m) << endl;
    cout << getPower(b,m) << endl;
    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/项目/WHU_ALP_2024/2024_10_28]
└─$ ./a.out
请依次输入a,b,m: 3
0.5
2
9
0.25
```

显然，传入实数底数即可得到一个实型结果。

## 3-10

编写函数求两个整数的最大公约数和最小公倍数。要求两个整数以及结果在主函数中输入输出。  
源码：

```c++
#include <iostream>
using namespace std;

int gcd(int a, int b) {//辗转相除法
    int r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
    return 0;
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment3]
└─$ g++ 3-10.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment3]
└─$ ./a.out
5
3
1
15

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment3]
└─$ ./a.out
8
6
2
24

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment3]
└─$ ./a.out
6
8
2
24
```

## 3-9

编写函数判别一个整数是否是质数？要求在主函数中输入输出。

源码：

```c++
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cout << "请输入一个整数：";
    cin >> num;
    if (isPrime(num)) {
        cout << num << " 是质数。" << endl;
    }else{
        cout << num << " 不是质数。" << endl;
    }
}
```

运行结果：

```bash
┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment3]
└─$ g++ 3-9.cpp

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment3]
└─$ ./a.OUT
请输入一个整数：4
4 不是质数。

┌──(fqwqf㉿LAPTOP-TQH90R00)-[/mnt/c/Users/fQwQf/Desktop/project/WHU_ALP_2024/experiment3]
└─$ ./a.OUT
请输入一个整数：23
23 是质数。
```
