#include <iostream>
using namespace std;
class Student
{
private:
    static int count; // 统计学生的总数
    int StudentNo;    // 普通数据成员，学号
public:
    Student()
    {
        ++count;
        StudentNo = count;
    }
    void Print()
    {
        cout << "Student" << StudentNo << " ";
        cout << "count=" << count << endl;
    }
};
int Student::count = 0;
// 静态数据成员必须在类外初始化，前面不能加static

int main()
{
    Student Student1;
    Student1.Print();
    cout << "----------" << endl;
    Student Student2;
    Student1.Print();
    Student2.Print();
    cout << "----------" << endl;
    Student Student3;
    Student1.Print();
    Student2.Print();
    Student3.Print();
    cout << "----------" << endl;
    Student Student4;
    Student1.Print();
    Student2.Print();
    Student3.Print();
    Student4.Print();
    return 0;
}
