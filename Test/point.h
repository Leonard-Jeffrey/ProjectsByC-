#pragma once
#include<iostream>
using namespace std;

class Point {
public:
	//��ȡx����
	int getX();

	//����x����
	void setX(int v);

	//��ȡy����
	int getY();

	//����y����
	void setY(int v);
private:
	//��Ա����
	int x;
	int y;
};

