#pragma once
#include<iostream>
using namespace std;

class Point {
public:
	//获取x坐标
	int getX();

	//设置x坐标
	void setX(int v);

	//获取y坐标
	int getY();

	//设置y坐标
	void setY(int v);
private:
	//成员属性
	int x;
	int y;
};

