#include <bits/stdc++.h>

int getAlpha(std::string a){
    int ans = 0;
    for (char i : a){
        if(std::isalpha(i)){
            ans ++;
        }
    }
    return ans;
}

int main(){
    std::cout << getAlpha("!!!@#🤣🤣🤣") << std::endl;
    std::cout << getAlpha("#include <bits/stdc++.h>") << std::endl;
    std::cout << getAlpha("MAN,WHAT CAN I SAY!") << std::endl;
    std::cout << getAlpha("Hello world!") << std::endl;
}