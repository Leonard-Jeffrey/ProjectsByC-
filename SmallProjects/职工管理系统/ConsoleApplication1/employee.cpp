#include"employee.h"

//构造函数实现
employee::employee(int ID, string name, int dID) {
	this->mID = ID;
	this->mName = name;
	this->mDeptID = dID;
}


//展示员工信息
void employee::showInfo() {
	cout << "编号：" << this->mID << "\t姓名：" << this->mName << "\t岗位：" << this->getDeptName() << "\t职责：" << "完成经理交给的任务" << endl;
}

//获取员工部门编号
string employee::getDeptName() {
	return string("员工");
}

//析构函数实现
employee::~employee() {

}

