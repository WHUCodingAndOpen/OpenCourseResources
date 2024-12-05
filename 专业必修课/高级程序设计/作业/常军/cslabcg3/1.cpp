#include <bits/stdc++.h>

using namespace std;

int numOfAlpha(string s){
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])){
            ans++;
        }
    }
    return ans;
}

int main(){
    string input;
    getline(cin, input);
    int ans = numOfAlpha(input);
    cout << "这个句子里有" << ans << "个英文字母。" << endl;
}