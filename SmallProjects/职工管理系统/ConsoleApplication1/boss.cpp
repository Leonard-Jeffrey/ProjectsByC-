#include"boss.h"

//���캯��ʵ��
boss::boss(int ID, string name, int dID) {
	this->mID = ID;
	this->mName = name;
	this->mDeptID = dID;
}

//��ʾԱ����Ϣ
void boss::showInfo() {
	cout << "��ţ�" << this->mID << "\t������" << this->mName << "\tְλ��" << this->getDeptName() << "\tְ�𣺴��칫˾���У�����Ա�����������۷壡" << endl;
}

//��ȡԱ��ְλ
string boss::getDeptName() {
	return string("�ϰ�");
}

//��������ʵ��
boss::~boss() {

}