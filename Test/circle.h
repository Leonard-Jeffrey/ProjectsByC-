#pragma once
#include<iostream>
#include"point.h"
using namespace std;


class Circle {
public:
	//设置半径
	void setR(int R);

	//获取半径
	int getR();

	//设置圆心
	void setCenter(int xv, int yv);

	//获取圆心
	Point getCenter();

	//判断成员函数：判断一个点与圆的相对位置；
	int positionJudge(Point p);
private:
	//成员属性
	int r;
	Point center;
};
