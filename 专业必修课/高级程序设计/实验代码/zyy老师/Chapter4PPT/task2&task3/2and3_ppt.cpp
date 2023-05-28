//  main.cpp
#include "date.h"
int main()
{
    Date date1;
    Date date2(2005);
    Date date3(2006,12,15);
    cout<<"date1:";      date1.ShowDate();
    cout<<"date2:";      date2.ShowDate();
    cout<<"date3:";      date3.ShowDate();


    Date date4(1999,4,20);
    cout << "date4:"<<endl;
    date4.ShowDate();

    Date date5(2004,10,15);
    cout<<"data5:"<<endl;
    date5.ShowDate();
    return 0;
}
