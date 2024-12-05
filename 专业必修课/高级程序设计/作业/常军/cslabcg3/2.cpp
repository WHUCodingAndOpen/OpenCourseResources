#include <bits/stdc++.h>

using namespace std;

//计算组合数C(n,m)
int c(int a, int b)
{
    if (b > a - b)
    {
        b = a - b;
    };
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a - i;
        ans /= i + 1;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        for(int m=0; m < n-i; m++){
            cout << "  ";
        }
        for(int j = 0; j <= i; j++){
            cout << setw(4) << c(i,j) ;
        }
        cout << endl;
    };
}