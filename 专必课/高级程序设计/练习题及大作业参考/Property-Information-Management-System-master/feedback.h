#pragma once
#include<iostream>
using namespace std;
class feedback
{
private:
	bool type;			//信息类型，true为报修，false为投诉
	int householdID;	//提交住户ID
	string time;		//提交时间
	bool state;			//当前状态，true为解决，false为未解决
public:
	//新建信息
	feedback(bool TYPE, int HOUSEHOLDID, string TIME)
	{
		type = TYPE;
		householdID = HOUSEHOLDID;
		time = TIME;
		state = false;
	}
	//
};
