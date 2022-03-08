#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//普通职工类 继承 worker类
class employee:public worker {
public:
	//构造函数
	employee(int ID, string name, int dID);

	//重写虚函数
	//显示个人信息
	virtual void showInfo();
	//获取部门编号
	virtual string getDeptName();

	//析构函数
	~employee();
	
};
