#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//�����ϰ���
class boss :public worker {
public:
	boss(int ID, string name, int dID);

	virtual void showInfo();

	virtual string getDeptName();

	~boss();
};
