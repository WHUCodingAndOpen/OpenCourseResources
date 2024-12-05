#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    vector<int> counts(26, 0); // 用于存储每个字母出现的次数，初始化为0

    // 读取输入的英文文章
    while (getline(cin, line)) {
        for (char c : line) {
            if (islower(c)) { // 只统计小写字母
                counts[c - 'a']++; // 将字母转换为索引，并增加其计数
            }
        }
    }

    int maxCount;

    for (int &i : counts){
        maxCount = max(maxCount,i);
    }

    // 根据每个字母的出现次数，打印出相应的柱状图
    for (int i = maxCount; i > 0; --i) {
        for (int j = 0; j < 26; ++j) {
            if (counts[j] >= i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    // 打印出所有的字母
    for (char c = 'a'; c <= 'z'; ++c) {
        cout << c ;
    }
    cout << endl;

    return 0;
}
