#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

//��ְͨ���� �̳� worker��
class employee:public worker {
public:
	//���캯��
	employee(int ID, string name, int dID);

	//��д�麯��
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ���ű��
	virtual string getDeptName();

	//��������
	~employee();
	
};
