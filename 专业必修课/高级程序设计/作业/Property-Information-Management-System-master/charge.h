#pragma once
#include<iostream>
using namespace std;
class charge
{
private:
	string name;		//收费名称
	float cost;			//收费金额
	string info;	//收费信息
	string time;		//收费时间
	bool state;			//收费状态
public:
	//初始化收费
	charge(string NAME, float COST, string INFO, string TIME)
	{
		name = NAME;
		cost = COST;
		info = INFO;
		time = TIME;
		state = false;
	}
	//获取收费信息
	string getChargeName()
	{
		return name;
	}
	float getChargeCost()
	{
		return cost;
	}
	string getChargeInfo()
	{
		return info;
	}
	string getChargeTime()
	{
		return time;
	}
	bool getChargeState()
	{
		return state;
	}
	//修改收费状态
	void setChargeState()
	{
		if (state)	state = false;
		else state = true;
	}
};