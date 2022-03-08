#include"manager.h"

//构造函数实现
manager::manager(int ID, string name, int dID) {
	this->mID = ID;
	this->mName = name;
	this->mDeptID = dID;
}

//显示员工信息
void manager::showInfo() {
	cout << "编号：" << this->mID << "\t姓名：" << this->mName << "\t职位：" << this->getDeptName() << "\t职责：完成老板分配的任务，给普通员工下派任务" << endl;
}

//获取员工部门编号
string manager::getDeptName() {
	return string("经理");
}

//析构函数
manager::~manager() {

}