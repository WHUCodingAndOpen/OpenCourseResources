#pragma once
#include<iostream>
using namespace std;
class parking
{
private:
	int ID;
	float cost;
	int householdID;
public:
	//初始化车位
	parking(int ID, float COST, int HOUSEHOLDID)
	{
		this->ID = ID;
		cost = COST;
		householdID = HOUSEHOLDID;
	}
	//获取车位信息
	int getParkingID()
	{
		return ID;
	}
	float getParkingCost()
	{
		return cost;
	}
	int getParkingHouseholdID()
	{
		return householdID;
	}
	//修改车位信息
	void setParkingCost(float COST)
	{
		cost = COST;
	}
	void setParkingHouseholdID(int ID)
	{
		householdID = ID;
	}
};
