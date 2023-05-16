#pragma once
#include<iostream>
using namespace std;
class community
{
private:
	string name;		//小区名称
	int buildingNum;	//楼宇总数
	int householdNum;	//住户总数
	int parkingNum;		//车位总数
public:
	community(string NAME, int BUILDINGNUM, int HOUSEHOLDNUM, int PARKINGNUM)
	{
		name = NAME;
		buildingNum = BUILDINGNUM;
		householdNum = HOUSEHOLDNUM;
		parkingNum = PARKINGNUM;
	}
	//修改小区所有信息
	//输入名称、楼宇数、住户数、车位数
	//无输出
	void ModifyCommunityInfo(string NAME, int BUILDINGNUM, int HOUSEHOLDNUM, int PARKINGNUM)
	{
		name = NAME;
		buildingNum = BUILDINGNUM;
		householdNum = HOUSEHOLDNUM;
		parkingNum = PARKINGNUM;
	}
	//获取小区信息
	string getCommunityName()
	{
		return name;
	}
	int getCommunityBuildingNum()
	{
		return buildingNum;
	}
	int getCommunityHouseholdNum()
	{
		return householdNum;
	}
	int getCommunityParkingNum()
	{
		return parkingNum;
	}
	//修改小区各项信息
	void setCommunityName(string NAME)
	{
		name = NAME;
	}
	void setCommunityBuildingNum(int BUILDINGNUM)
	{
		buildingNum = BUILDINGNUM;
	}
	void setCommunityHouseholdNum(int HOUSEHOLDNUM)
	{
		householdNum = HOUSEHOLDNUM;
	}
	void setCommunityParkingNum(int PARKINGNUM)
	{
		parkingNum = PARKINGNUM;
	}
};