#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");

    int a;
    cout<<"请输入你的分数：";
    cin>>a;
    if(a>=90&&a<=100)
    {
        cout<<"优"<<endl;
    }
    else if(a>=80&&a<90)
    {
        cout<<"良"<<endl;
    }
    else if(a>=60&&a<80)
    {
        cout<<"中"<<endl;
    }
    else if(a>=0&&a<60)
    {
        cout<<"差"<<endl;
    }
    else
    {
        cout<<"输入错误"<<endl;
    }
    return 0;
}