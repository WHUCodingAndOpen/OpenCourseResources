#pragma once
#include<iostream>
using namespace std;
class roomtype
{
private:
	int typeId;			//房型编号
	string typeName;	//房型名称
	float typeArea;		//房型面积
public:
	roomtype(int TYPEID, string TYPENAME, float TYPEAREA)
	{
		typeId = TYPEID;
		typeName = TYPENAME;
		typeArea = TYPEAREA;
	}
	//获取房型信息
	int getTyoeId()
	{
		return typeId;
	}
	string getTypeName()
	{
		return typeName;
	}
	float typeArea()
	{
		return typeArea;
	}
};