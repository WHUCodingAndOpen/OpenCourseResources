#include <iostream>
using namespace std;
struct Date
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};
int main()
{
    system("chcp 65001");
	Date date;
	cout << "请输入年、月、日、小时、分、秒：";
	cin >> date.year >> date.month >> date.day >> date.hour >> date.minute>> date.second;
    cout << date.year << "年" << date.month << "月" << date.day << "日" << date.hour << "时" << date.minute << "分" << date.second << "秒" << endl;
}