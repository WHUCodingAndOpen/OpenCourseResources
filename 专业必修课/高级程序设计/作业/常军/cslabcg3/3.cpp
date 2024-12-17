#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    double x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    double ans = 0;
    for(int i = 0; i < n; i++){
        //向量叉乘求面积岂不是更好？
        ans += x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
    }
    ans = abs(ans) / 2;
    printf("%.2f", ans);
    return 0;
}