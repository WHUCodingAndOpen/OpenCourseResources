// 5-3、下面程序的运行结果是什么，实际运行一下，看看和你的设想有何不同？
#include <iostream>
using namespace std;

int x = 5, y = 7;

void myFunction() {
    int y = 10;
    cout << "x from myFunction " << x << endl;
    cout << "y from myFunction " << y << endl;
}

int main() {
    cout << "x from main " << x << endl;
    cout << "y from main " << y << endl;
    myFunction();
    cout << "Back from myFunction!\n\n";
    cout << "x from main " << x << endl;
    cout << "y from main " << y << endl;
    return 0;
}
