#include <iostream>
using namespace std;

int main() {
    char choice;

    while (true) {
        cout << "Menu: A(dd) D(elete) S(ort) Q(uit), Select one: ";
        cin >> choice;
        choice = toupper(choice); // 忽略大小写

        // 使用 if...else 进行初步检查
        if (choice == 'A' || choice == 'D' || choice == 'S' || choice == 'Q') {
            // 有效输入，使用 switch 进一步处理
            switch (choice) {
                case 'A':
                    cout << "数据已经增加。" << endl;
                    break;
                case 'D':
                    cout << "数据已经删除。" << endl;
                    break;
                case 'S':
                    cout << "数据已经排序。" << endl;
                    break;
                case 'Q':
                    cout << "程序结束。" << endl;
                    return 0; // 退出程序
            }
        } else {
            // 无效输入，提示重新输入
            cout << "无效输入，请重新选择。" << endl;
            continue; // 继续循环
        }
    }

    return 0;
}
