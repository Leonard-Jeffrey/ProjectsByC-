#include"employee.h"

//���캯��ʵ��
employee::employee(int ID, string name, int dID) {
	this->mID = ID;
	this->mName = name;
	this->mDeptID = dID;
}


//չʾԱ����Ϣ
void employee::showInfo() {
	cout << "��ţ�" << this->mID << "\t������" << this->mName << "\t��λ��" << this->getDeptName() << "\tְ��" << "��ɾ�����������" << endl;
}

//��ȡԱ�����ű��
string employee::getDeptName() {
	return string("Ա��");
}

//��������ʵ��
employee::~employee() {

}

