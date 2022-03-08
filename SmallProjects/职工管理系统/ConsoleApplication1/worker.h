#pragma once
#include<iostream>
using namespace std;

//职工抽象基类
class worker {
public:

	//展示员工信息
	virtual void showInfo() = 0; //纯虚函数

	//获取员工部门编号
	virtual string getDeptName() = 0; //纯虚函数

	//员工属性
	int mID;
	string mName;
	int mDeptID;
};
