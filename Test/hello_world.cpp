#include<iostream>
#include<vector>
#include<set>
using namespace std;

int& test1() {
	int a = 100;
	return a;
}

int& test2() {
	static int b = 10000;
	return b;
}

int* test3() {
	int e = 200;
	return &e;
}

int& test() {
	static int a = 100;
	return a;
}
int main()
{
	/*int &c = test1();
	cout << "c = " << c << endl;
	cout << "c = " << c << endl;
	cout << "c = " << c << endl;
	cout << "c = " << c << endl;
	int &d = test2();
	cout << "d = " << d << endl;
	cout << "d = " << d << endl;
	int *e = test3();
	cout << "e = " << *e << endl;
	cout << "e = " << *e << endl;*/

	int& b = test();
	cout << "b = " << b << endl;
	test() = 1000;
	cout << "b = " << b << endl;

	return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
}