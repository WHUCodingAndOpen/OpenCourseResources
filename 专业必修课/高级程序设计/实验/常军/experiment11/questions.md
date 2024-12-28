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

## 11-2

编写程序，用二进制文件打开指定的一个文件，在每一行前加行号。

## 11-3

使用实验10中的学生类数组，输入数据，显示出来，使用I/O流把此数组的内容写入磁盘文件，再显示出文件内容。
