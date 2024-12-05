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