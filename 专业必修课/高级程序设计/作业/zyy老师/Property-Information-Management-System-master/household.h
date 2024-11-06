#pragma once
#include<iostream>
using namespace std;
class household
{
private:
	int ID;				//住户编号		
	string name;		//住户姓名
	string tel;			//联系电话
	string location;	//地址
	float payment;		//付款（预付为正，欠款为负）
public:
	//构造函数，新建住户
	household(int householdID, string NAME, string TEL, string LOCATION, float PAYMENT)
	{
		ID = householdID;
		name = NAME;
		tel = TEL;
		location = LOCATION;
		payment = PAYMENT;
	}
	//获取住户信息
	int getHouseholdID()
	{
		return ID;
	}
	string getHouseholdName()
	{
		return name;
	}
	string getHouseholdTel()
	{
		return tel;
	}
	string getHouseholdLocation()
	{
		return location;
	}
	float getHouseholdPayment()
	{
		return payment;
	}
	//修改住户信息
	void setHouseholdID(int id)
	{
		ID = id;
	}
	void setHouseholdName(string NAME)
	{
		name = NAME;
	}
	void setHouseholdTel(string TEL)
	{
		tel = TEL;
	}
	void setHouseholdLocation(string LOCATION)
	{
		location = LOCATION;
	}
	void setHouseholdPayment(float PAYMENT)
	{
		payment = PAYMENT;
	}
};