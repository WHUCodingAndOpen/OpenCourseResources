#include <iostream>
using namespace std;
struct Base1
{
    int x;
};
struct Base2
{
    float y;
};
struct Derived : Base1, Base2
{
};
int main()
{
    Derived *pd = new Derived;
    pd->x = 1;
    pd->y = 2.0f;
    void *pv = pd;
    Base2 *pb = static_cast<Base2 *>(pv);
    cout << pd->y <<" "<< pb->y << endl;
    delete pb;
    return 0;
}