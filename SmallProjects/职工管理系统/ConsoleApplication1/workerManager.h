#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class workerManager {
public:
	//构造函数
	workerManager();

	//数据保存到文件
	void save();

	//统计文件中人数
	int getEmpNum();

	//初始化
	void initEmp();

	//展示菜单
	void showMenu();

	//选择0：退出系统
	void exitSystem();

	//选择1：显示职工
	void showWorker();

	//选择2：添加职工
	void addWorker();

	//选择3：删除职工
	int isExist(int ID);
	void deleteWorker();

	//选择4：查找职工
	void searchWorker();

	//选择5：修改职工
	void modifyWorker();

	//选择6：按照编号排序
	void sortWorker();

	//选择7：清空文档；
	void cleanFile();

	//析构函数
	~workerManager();

	//成员属性
	int mNum; //记录文件职工数量
	worker ** mArray; //员工数组指针
	bool mfileEmpty;
};
