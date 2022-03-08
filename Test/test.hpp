#include<iostream>
using namespace std;
#include<string>

template<typename T1>
class Array {

public:
	//有参拷贝函数
	Array(int capacity) {
		count = 0;
		this->capacity = capacity;
		//p = (T1 *)malloc(this->capacity * sizeof(T1));
		this->p = new T1[this->capacity];
		//cout << sizeof(T1);
		if (p == NULL) {
			cout << "创建失败！！！" << endl;
			return;
		}
		cout << "创建成功！！！" << endl;
	}
	//拷贝构造函数
	Array(const Array& A) {
		this->count = A.count;
		this->capacity = A.capacity;

		//深拷贝
		//this->p = (T1*)malloc(this->capacity * sizeof(T1));
		this->p = new T1[this->capacity];
		for (int i = 0;i < this->count;i++) {
			this->p[i] = A.p[i];
		}
	}

	//尾插法
	void tailInsert(T1& n) {
		if (this->count >= this->capacity) {
			cout << "容量已满，请先扩容！" << endl;
			return;
		}
		this->p[this->count] = n;
		this->count++;
	}

	//尾删法
	void tailDelete() {
		if (this->count == 0) {
			cout << "数组为空！" << endl;
			return;
		}
		this->count--;
	}

	// 运算符重载：[]，允许使用下标；
	T1& operator[](int index) {

		return this->p[index];
	}

	////运算符重载：=，防止浅拷贝问题；
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

	//获取容量
	int getCapacity() {
		return this->capacity;
	}

	//获取元素个数
	int getCount() {
		return this->count;
	}

	//析构函数
	~Array() {
		if (this->p != NULL) {
			delete[] this->p;
			this->p = NULL;
			this->capacity = 0;
			this->count = 0;
			cout << "啊，我死了！" << endl;
		}
	}

	//私有属性
private:
	int count;
	int capacity;
	T1* p;
};

