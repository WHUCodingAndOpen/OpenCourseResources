// 下列程序有何问题，请仔细体会使用指针时应避免出现这个问题
#include <iostream>
using namespace std;
int main() {
    int *p;
    *p=9;
    cout << "the value at p:" << *p;
    return 0;
}
/* 改正后的代码
#include <iostream>
using namespace std;
int main() {
    int value = 0;
    int *p = &value;
    *p = 9;
    cout << "the value at p:" << *p;
    return 0;
}
*/