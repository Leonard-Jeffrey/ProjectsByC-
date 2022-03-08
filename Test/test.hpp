#include<iostream>
using namespace std;
#include<string>

template<typename T1>
class Array {

public:
	//�вο�������
	Array(int capacity) {
		count = 0;
		this->capacity = capacity;
		//p = (T1 *)malloc(this->capacity * sizeof(T1));
		this->p = new T1[this->capacity];
		//cout << sizeof(T1);
		if (p == NULL) {
			cout << "����ʧ�ܣ�����" << endl;
			return;
		}
		cout << "�����ɹ�������" << endl;
	}
	//�������캯��
	Array(const Array& A) {
		this->count = A.count;
		this->capacity = A.capacity;

		//���
		//this->p = (T1*)malloc(this->capacity * sizeof(T1));
		this->p = new T1[this->capacity];
		for (int i = 0;i < this->count;i++) {
			this->p[i] = A.p[i];
		}
	}

	//β�巨
	void tailInsert(T1& n) {
		if (this->count >= this->capacity) {
			cout << "�����������������ݣ�" << endl;
			return;
		}
		this->p[this->count] = n;
		this->count++;
	}

	//βɾ��
	void tailDelete() {
		if (this->count == 0) {
			cout << "����Ϊ�գ�" << endl;
			return;
		}
		this->count--;
	}

	// ��������أ�[]������ʹ���±ꣻ
	T1& operator[](int index) {

		return this->p[index];
	}

	////��������أ�=����ֹǳ�������⣻
	Array& operator=(Array& A) {
		if (this->p != NULL) {
			delete[] this->p;
			this->capacity = 0;
			this->count = 0;
		}
		//this->p = (T1*)malloc(A->count * sizeof(T1));
		this->p = new T1[A->count];
		this->capacity = A->capacity;
		this->count = A->count;
		for (int i = 0; i < this->count; i++) {
			this->p[i] = A->p[i];
		}
		return *this;
	}

	//��ȡ����
	int getCapacity() {
		return this->capacity;
	}

	//��ȡԪ�ظ���
	int getCount() {
		return this->count;
	}

	//��������
	~Array() {
		if (this->p != NULL) {
			delete[] this->p;
			this->p = NULL;
			this->capacity = 0;
			this->count = 0;
			cout << "���������ˣ�" << endl;
		}
	}

	//˽������
private:
	int count;
	int capacity;
	T1* p;
};

