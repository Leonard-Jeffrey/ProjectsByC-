#pragma once
#include<iostream>
#include"point.h"
using namespace std;


class Circle {
public:
	//���ð뾶
	void setR(int R);

	//��ȡ�뾶
	int getR();

	//����Բ��
	void setCenter(int xv, int yv);

	//��ȡԲ��
	Point getCenter();

	//�жϳ�Ա�������ж�һ������Բ�����λ�ã�
	int positionJudge(Point p);
private:
	//��Ա����
	int r;
	Point center;
};
