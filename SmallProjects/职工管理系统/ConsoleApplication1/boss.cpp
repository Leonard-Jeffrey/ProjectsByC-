#include"boss.h"

//构造函数实现
boss::boss(int ID, string name, int dID) {
	this->mID = ID;
	this->mName = name;
	this->mDeptID = dID;
}

//显示员工信息
void boss::showInfo() {
	cout << "编号：" << this->mID << "\t姓名：" << this->mName << "\t职位：" << this->getDeptName() << "\t职责：带领公司上市，带领员工走上人生巅峰！" << endl;
}

//获取员工职位
string boss::getDeptName() {
	return string("老板");
}

//析构函数实现
boss::~boss() {

}