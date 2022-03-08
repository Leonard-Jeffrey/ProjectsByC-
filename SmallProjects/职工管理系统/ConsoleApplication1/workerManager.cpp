#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "Employee.txt"

//构造函数实现
//文件总共分为三种状态：1. 文件不存在 2. 文件存在但是为空 3. 文件存在且不为空
workerManager::workerManager() {
	//包含头文件

	//创建文件流对象
	ifstream ifs;

	//读文件
	ifs.open(FILENAME, ios::in);

	//判断文件状态
	if (!ifs.is_open()) {
		//如果文件不存在，打印提示信息，设置相关变量
		cout << "文件不存在！" << endl;

		//初始人数为0
		this->mNum = 0;
		//初始员工数组为空
		this->mArray = NULL;
		//初始文件为空
		this->mfileEmpty = true;
		//关闭文件
		ifs.close();
		return;
	}
		//如果文件存在，判断是否为空
		char ch;
		ifs >> ch;
		if (ifs.eof()) {
			cout << "文件为空！" << endl;
			this->mNum = 0;
			this->mArray = NULL;
			this->mfileEmpty = true;
			ifs.close();
			return;
		}

		//如果文件存在，且不为空
		this->mfileEmpty = false;
		this->mNum = getEmpNum();
		cout << "总共有" << this->mNum << "个职工！" << endl;

		this->mArray = new worker * [this->mNum];
		initEmp();
		ifs.close();
}

//保存文件
void workerManager::save() {
	//包含头文件
	
	//创建文件流对象
	ofstream ofs;

	//打开文件
	ofs.open(FILENAME, ios::out);

	//将职工信息写入文件
	for (int i = 0;i < this->mNum;i++) {
		ofs << this->mArray[i]->mID << " " << this->mArray[i]->mName << " " << this->mArray[i]->mDeptID << endl;
	}
	//关闭文件
	ofs.close();
	//设置文件标志非空
	this->mfileEmpty = false;
}
//获取文件人数
int workerManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string name;
	int dID;

	int num = 0;
	while (ifs >> ID && ifs >> name && ifs >> dID) {
		num++;
	}
	ifs.close();
	return num;
}


//初始化
void workerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		worker* worker = NULL;
		if (id == 1) {
			worker = new employee(id, name,did);
		}
		else if (id == 2) {
			worker = new manager(id ,name, did);
		}
		else {
			worker = new boss(id,name,did);
		}
		this->mArray[index++] = worker;
	}
	ifs.close();
}



//显示菜单
void workerManager::showMenu() {
	cout << " ---------- 菜单 ----------" << endl;
	cout << "        0. 退出系统" << endl;
	cout << "        1. 显示职工" << endl;
	cout << "        2. 增加职工" << endl;
	cout << "        3. 删除职工" << endl;
	cout << "        4. 查找职工" << endl;
	cout << "        5. 修改职工" << endl;
	cout << "        6. 按照编号排序" << endl;
	cout << "        7. 清空文件" << endl;
}



//选择0：退出系统
void workerManager::exitSystem() {
	system("cls");
	cout << "欢迎再次使用！再见！" << endl;
	system("pause");
	exit(0);
}


//选择1：显示职工
void workerManager::showWorker() {
	system("cls");
	if (this->mfileEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < this->mNum; i++) {
			this->mArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//选择2：增加职工
void workerManager::addWorker() {
	system("cls");
	int addnum;
	//与用户交互，询问添加用户数量
	cout << "请输入增加职工数量：";
	cin >> addnum;
	//如果用户添加数量大于0
	if (addnum > 0) {
		//计算新空间大小
		int newSize = this->mNum + addnum;
		//开辟新空间
		worker** pArray = new worker * [newSize];

		//如果原空间不为空，则执行以下代码将原空间赋值给新空间；
		if (this->mArray != NULL) {
			//复制原空间内容
			for (int i = 0;i < this->mNum;i++) {
				pArray[i] = this->mArray[i];
			}
			//释放原空间
			delete[] this->mArray;
		}

		//如果原空间为空，则直接将新空间赋值给员工数组；
		//数组指向新空间
		(this->mArray) = pArray;

		//添加新数据
		int ID;
		string name;
		int dID;
		for (int i = 0;i < addnum;i++) {
			system("cls");
			while (1) {
				cout << "请输入第" << i + 1 << "位员工的编号：";
				cin >> ID;
				if (this->isExist(ID) != -1) {
					cout << "该编号已存在！" << endl;
				}
				else
					break;
			}
			cout << "请输入第" << i + 1 << "位员工的姓名：";
			cin >> name;
			cout << "请输入第" << i + 1 << "位员工的职位：";
			cout << endl;
			cout << "\t[3] 老板" << endl << "\t[2] 经理" << endl << "\t[1] 员工" << endl;
			cin >> dID;


			worker* work = NULL;
		loop:		switch (dID) {
		case 3:
			work = new boss(ID, name, dID);
			break;
		case 2:
			work = new manager(ID, name, dID);
			break;
		case 1:
			work = new employee(ID, name, dID);
			break;
		default:
			cout << "选择错误！" << endl;
			system("pause");
			system("cls");
			cout << "请重新输入第" << i + 1 << "位员工的职位：" << endl;
			cout << "\t3：老板" << endl << "\t2：经理" << endl << "\t1：员工" << endl;
			cin >> dID;
			goto loop;
		}
			
			//将新员工加入到员工数组
			(this->mArray)[mNum + i] = work;
		}
		//更新职工数组大小
		this->mNum = newSize;
		//输出提示信息
		cout << "总共成功添加" << addnum << "名员工！" << endl;
		//将职工数据保存到文件
		this->save();
		this->mfileEmpty = false;
	}
	else {
		cout << "输入错误！" << endl;
	}
	system("pause");
	system("cls");
}

//选择3：删除职工
//判断职工是否存在
int workerManager::isExist(int ID) {
	int record = -1;
	for (int i = 0; i < this->mNum;i++) {
		if (this->mArray[i]->mID == ID) {
			record = i;
			return record;
		}
	}
	return record;
}


void workerManager::deleteWorker() {
	system("cls");
	//判断文件是否存在

	//若文件不存在
	if (this->mNum == 0) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	//若文件存在
	else {
		
		//调用查找函数，先找到员工
		int ID;
		cout << "请输入要删除的员工编号：";
		cin >> ID;

		//判断职工是否存在
		int result = isExist(ID);
		//若职工不存在
		if (result == -1) {
			cout << ID << "号员工不存在！" << endl;
		}
		//若职工存在
		else {
			//进行最后确认
			cout << "确定删除" << ID << "号员工？" << endl;
			cout << "\t[y] 确定" << endl;
			cout << "\t[n] 取消" << endl;
			char select;
			cin >> select;
			switch (select) {
			case 'y':
				int i;
				for (i = result;i < this->mNum - 1;i++) {
					//覆盖要删除的职工信息
					this->mArray[i] = this->mArray[i + 1];
				}
				//更新职工成员
				this->mNum--;
				//将数据同步到文件中
				this->save();
				break;
			case 'n':
				cout << "已经取消！" << endl;
				break;
			}
		}
	}
	system("pause");
	system("cls");
}

//选择4：查找职工
void workerManager::searchWorker() {
	//清屏幕
	system("cls");
	//判断文件是否存在
	if(this->mfileEmpty){
		cout << "文件不存在或数据为空！" << endl;
	}
	else {
		int ID;

		cout << "请输入要查找的职工编号：";
		cin >> ID;

		//调用查找函数，先找到员工
		if (this->isExist(ID) == -1) {
			cout << ID << "号员工不存在！" << endl;
		}
		else {
			cout << "已找到" << ID << "号员工" << endl;
			this->mArray[isExist(ID)]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//修改职工信息
void workerManager::modifyWorker() {
	//清屏幕
	system("cls");

	//判断是否存在职工
	if (this->mNum == 0) {
		cout << "职工信息为空！" << endl;
	}
	else {
		int ID;
		cout << "请输入要修改的职工编号：";
		cin >> ID;

		//判断要修改的职工是否村咋
		if (this->isExist(ID) == -1) {
			cout << "该员工不存在！" << endl;
		}
		else {
			cout << "即将修改以下员工信息：" << endl;
			this->mArray[this->isExist(ID)]->showInfo();
			cout << "请重新输入该用户信息：" << endl;
			cout << "姓名：";
			cin >> this->mArray[this->isExist(ID)]->mName;
			cout << "部门编号：";
			cin >> this->mArray[this->isExist(ID)]->mDeptID;
			cout << "信息修改成功！" << endl;
			this->save();
		}
	}
	system("pause");
	system("cls");
}

//排序
void workerManager::sortWorker() {
	system("cls");
	if (this->mNum == 0) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "[1] 按照编号升序" << endl;
		cout << "[2] 按照编号降序" << endl;
		cout << "请选择排序方式：";
		int select;
		cin >> select;

		if (select == 1) {
			for (int i = 0;i < this->mNum - 1;i++) {
				int min = i;
				for (int j = i + 1; j < this->mNum;j++) {
					if (this->mArray[j]->mID < this->mArray[min]->mID) {
						min = j;
					}
				}
				if (min != i) {
					worker* worker = this->mArray[min];
					this->mArray[min] = this->mArray[i];
					this->mArray[i] = worker;
				}
			}
			this->showWorker();
		}
		else if(select == 2) {
			for (int i = 0;i < this->mNum - 1;i++) {
				int max = i;
				for (int j = i + 1; j < this->mNum;j++) {
					if (this->mArray[j]->mID > this->mArray[max]->mID) {
						max = j;
					}
				}
				if (max != i) {
					worker* worker = this->mArray[max];
					this->mArray[max] = this->mArray[i];
					this->mArray[i] = worker;
				}
			}
			this->showWorker();
		}
		else {
			cout << "输入错误！" << endl;
		}

		cout << "是否保存到文件：" << endl;
		cout << "\t[y] 是 " << endl;
		cout << "\t[n] 否 " << endl;
		char selection;
		cin >> selection;
		switch (selection) {
		case 'y':
			this->save();
			cout << "保存成功！" << endl;
			break;
		case 'n':
			cout << "已取消！" << endl;
			break;
		}

	}
	system("pause");
	system("cls");
}

//清空
void workerManager::cleanFile() {
	if (this->mNum == 0) {
		cout << "文件已经为空！" << endl;
	}
	else {
		char select;
		cout << "清空文件？" << endl;
		cout << "\t[y] 是 " << endl;
		cout << "\t[n] 否 " << endl;
		cin >> select;
		if (select == 'y') {
			//包含头文件
			//创建文件流对象
			ifstream ifs;

			//如果文件存在，删除文件重新创建
			ifs.open(FILENAME, ios::trunc);
			ifs.close();

			//删除缓存
			if (this->mArray != NULL) {
				for (int i = 0;i < this->mNum;i++) {
					if (this->mArray[i] != NULL) {
						delete this->mArray[i];
						this->mArray[i] = NULL;
					}
				}
				delete[] this->mArray;
				this->mArray = NULL;
			}

			this->mArray = NULL;
			this->mNum = 0;
			this->mfileEmpty = true;
			//输出亲空成功的信息
			cout << "清空成功！" << endl;
		}
		else {
			cout << "取消成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}

workerManager::~workerManager() {
	if (this->mArray != NULL) {
		for (int i = 0;i < this->mNum;i++) {
			if (this->mArray[i] != NULL) {
				delete this->mArray[i];
			}
		}
		delete[] this->mArray;
		this->mArray = NULL;
	}
}