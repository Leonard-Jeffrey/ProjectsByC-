#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class workerManager {
public:
	//���캯��
	workerManager();

	//���ݱ��浽�ļ�
	void save();

	//ͳ���ļ�������
	int getEmpNum();

	//��ʼ��
	void initEmp();

	//չʾ�˵�
	void showMenu();

	//ѡ��0���˳�ϵͳ
	void exitSystem();

	//ѡ��1����ʾְ��
	void showWorker();

	//ѡ��2�����ְ��
	void addWorker();

	//ѡ��3��ɾ��ְ��
	int isExist(int ID);
	void deleteWorker();

	//ѡ��4������ְ��
	void searchWorker();

	//ѡ��5���޸�ְ��
	void modifyWorker();

	//ѡ��6�����ձ������
	void sortWorker();

	//ѡ��7������ĵ���
	void cleanFile();

	//��������
	~workerManager();

	//��Ա����
	int mNum; //��¼�ļ�ְ������
	worker ** mArray; //Ա������ָ��
	bool mfileEmpty;
};
