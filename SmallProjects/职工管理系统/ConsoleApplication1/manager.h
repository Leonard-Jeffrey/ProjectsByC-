#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//����������
class manager:public worker {
public:
	manager(int ID, string name, int dID);

	virtual void showInfo();

	virtual string getDeptName();

	~manager();
};
