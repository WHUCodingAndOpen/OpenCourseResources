#include <iostream>

using namespace std;

short int devide(unsigned short int a,unsigned short int b)
{   if (b!=0){
	    return a / b;
    }else{
	    return -1;
    }
};

int main()
{   unsigned short int a,b;
	cout << "请输入a: ";
	cin >> a ;
    cout << "请输入b: ";
	cin >> b ;
	cout << "结果为: " << devide(a,b);
	return 0;
}