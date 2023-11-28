// 7-15 下面的程序能得到预期的结果吗? 如何避免类似问题的发生?
#include<iostream>
using namespace std;
struct Base1 { int x; };
struct Base2 { float y; };
struct Derived : Base1, Base2 {};
int main() {
    Derived *pd=new Derived;
    pd->x = 1; 
    pd->y = 2.0f;
    void *pv = pd;
    Base2 *pb = static_cast<Base2 *>(pv);
    cout << pd->y << " " << pb->y << endl;
    delete pd;
    return 0;
}
    