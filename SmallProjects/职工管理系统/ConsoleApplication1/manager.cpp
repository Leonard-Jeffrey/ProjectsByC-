#include"manager.h"

//���캯��ʵ��
manager::manager(int ID, string name, int dID) {
	this->mID = ID;
	this->mName = name;
	this->mDeptID = dID;
}

//��ʾԱ����Ϣ
void manager::showInfo() {
	cout << "��ţ�" << this->mID << "\t������" << this->mName << "\tְλ��" << this->getDeptName() << "\tְ������ϰ��������񣬸���ͨԱ����������" << endl;
}

//��ȡԱ�����ű��
string manager::getDeptName() {
	return string("����");
}

//��������
manager::~manager() {

}