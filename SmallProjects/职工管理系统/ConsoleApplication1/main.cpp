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
	//worker* p = new employee(1,"��˧",1);
	//p->showInfo();
	//delete p;

	//worker* p1 = new manager(2,"��С˧",2);
	//p1->showInfo();
	//delete p1;

	//worker* p2 = new boss(3,"���ַ�",3);
	//p2->showInfo();
	//delete p2;



	workerManager wm;
	char choice;
		//��ӭ����
		cout << "��ӭ����ְ������ϵͳ��" << endl;
		cout << "\t[0] �˵�" << endl;
		cout << "\t[1] �˳�" << endl;
		cout << "��ѡ��";
		int select;
		cin >> select;
		//�ڻ�ӭ���棬�����û�ѡ����д���
		switch (select) {
			//ѡ��0������˵�
		case 0:	
			cout << "Loading";
			for (int k = 0; k < 3;k++) {
				cout << ". ";
				Sleep(700);
			}
			system("cls");
			while (1) {
				wm.showMenu();
				cout << "��ѡ��";
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
					cout << "������ѡ��" << endl;
					//system("pause");
					break;
				}
			}
			break;
			//ѡ��1����ӭ�ٴ�ʹ��
		case 1:
			cout << "��ӭ�ٴ�ʹ��!" << endl;
			system("pause");
			exit(0);
			break;
		}
	return 0;
}