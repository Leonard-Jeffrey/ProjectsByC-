#include"circle.h"

	//设置半径
	void Circle::setR(int R) {
		r = R;
	}

	//获取半径
	int Circle::getR() {
		return r;
	};

	//设置圆心
	void Circle::setCenter(int xv, int yv) {
		center.setX(xv);
		center.setY(yv);
	}

	//获取圆心
	Point Circle::getCenter() {
		return center;
	}

	//判断成员函数：判断一个点与圆的相对位置；
	int Circle::positionJudge(Point p) {
		double temp1 = pow(center.getX() - p.getX(), 2) + pow(center.getY() - p.getY(), 2);
		double temp2 = pow(r, 2);
		if (temp1 == temp2) {
			cout << "点" << "(" << p.getX() << ", " << p.getY() << ")" << "在圆上！" << endl;
			return 0;
		}
		else if (temp1 > temp2) {
			cout << "点" << "(" << p.getX() << ", " << p.getY() << ")" << "在圆外！" << endl;
			return 1;
		}
		else {
			cout << "点" << "(" << p.getX() << ", " << p.getY() << ")" << "在圆内！" << endl;
			return -1;
		}
	}
