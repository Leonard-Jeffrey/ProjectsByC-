#include<iostream>
using namespace std;
#include "workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<windows.h>
#include<stdlib.h>

int main() {

	//test
	//worker* p = new employee(1,"商帅",1);
	//p->showInfo();
	//delete p;

	//worker* p1 = new manager(2,"商小帅",2);
	//p1->showInfo();
	//delete p1;

	//worker* p2 = new boss(3,"李林峰",3);
	//p2->showInfo();
	//delete p2;



	workerManager wm;
	char choice;
		//欢迎界面
		cout << "欢迎进入职工管理系统！" << endl;
		cout << "\t[0] 菜单" << endl;
		cout << "\t[1] 退出" << endl;
		cout << "请选择：";
		int select;
		cin >> select;
		//在欢迎界面，根据用户选择进行处理
		switch (select) {
			//选择0，进入菜单
		case 0:	
			cout << "Loading";
			for (int k = 0; k < 3;k++) {
				cout << ". ";
				Sleep(700);
			}
			system("cls");
			while (1) {
				wm.showMenu();
				cout << "请选择：";
				cin >> choice;
				switch (choice) {
				case '0':
					wm.exitSystem();
					break;
				case '1':
					wm.showWorker();
					break;
				case '2':
					wm.addWorker();
					break;
				case '3':
					wm.deleteWorker();
					break;
				case '4':
					wm.searchWorker();
					break;
				case '5':
					wm.modifyWorker();
					break;
				case '6':
					wm.sortWorker();
					break;
				case '7':
					wm.cleanFile();
					break;
				default:
					cout << "请重新选择：" << endl;
					//system("pause");
					break;
				}
			}
			break;
			//选择1，欢迎再次使用
		case 1:
			cout << "欢迎再次使用!" << endl;
			system("pause");
			exit(0);
			break;
		}
	return 0;
}