#pragma once
#include<iostream>
using namespace std;

//ְ���������
class worker {
public:

	//չʾԱ����Ϣ
	virtual void showInfo() = 0; //���麯��

	//��ȡԱ�����ű��
	virtual string getDeptName() = 0; //���麯��

	//Ա������
	int mID;
	string mName;
	int mDeptID;
};
