#include"circle.h"

	//���ð뾶
	void Circle::setR(int R) {
		r = R;
	}

	//��ȡ�뾶
	int Circle::getR() {
		return r;
	};

	//����Բ��
	void Circle::setCenter(int xv, int yv) {
		center.setX(xv);
		center.setY(yv);
	}

	//��ȡԲ��
	Point Circle::getCenter() {
		return center;
	}

	//�жϳ�Ա�������ж�һ������Բ�����λ�ã�
	int Circle::positionJudge(Point p) {
		double temp1 = pow(center.getX() - p.getX(), 2) + pow(center.getY() - p.getY(), 2);
		double temp2 = pow(r, 2);
		if (temp1 == temp2) {
			cout << "��" << "(" << p.getX() << ", " << p.getY() << ")" << "��Բ�ϣ�" << endl;
			return 0;
		}
		else if (temp1 > temp2) {
			cout << "��" << "(" << p.getX() << ", " << p.getY() << ")" << "��Բ�⣡" << endl;
			return 1;
		}
		else {
			cout << "��" << "(" << p.getX() << ", " << p.getY() << ")" << "��Բ�ڣ�" << endl;
			return -1;
		}
	}
