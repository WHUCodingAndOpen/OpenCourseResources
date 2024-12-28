#include <iostream>
using namespace std;
double P(int n, double x)
{
	if (n == 0){
		return 1;
    }
	else if (n == 1){
		return x;
    }
	else{
		return ((2 * n - 1) * x * P(n - 1, x) - (n - 1) * P(n - 2, x)) / n;
    }
}

int main()
{
	int n;
	double x;
    cout << "请输入n与x: ";
	cin >> n >> x;
	cout << P(n, x);
	return 0;
}



