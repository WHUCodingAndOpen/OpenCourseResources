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