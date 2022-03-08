#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;

void print(int a[], int len) {
	for (int i = 0; i < len; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}




////�����
////1. ������ֵ��ά�ִ�ѣ�
//// ����һ���µ�ֵ
////2. �������ֵ��ά�ִ�ѣ�
////3. ������λ��ά�ִ�ѣ�
//void swap(int a[], int i, int j) {
//	int temp = a[i];
//	a[i] = a[j];
//	a[j] = temp;
//}
//
////Ԫ�������ƶ�
//void heapInsert(int a[], int index) {
//	//�ж�������������ֹ�����������
//	//1��������ڵ㣻
//	//2��С�ڵ��ڸ��ڵ㣻
//	while (a[index] > a[(index - 1) / 2]) {
//		swap(a,index,(index - 1)/2);
//		index = (index - 1) / 2;
//	}
//}
//
////Ԫ�������ƶ�
//void heapify(int a[], int index, int heapsize) {
//	int left = 2 * index + 1;
//	while (left < heapsize) {
//		int largest = (left + 1 < heapsize && a[left + 1] > a[left]) ? left + 1 : left;
//		if (a[largest] > a[index]) {
//			swap(a, index, largest);
//			index = largest;
//			left = 2 * index + 1;
//		}
//		else
//			break;
//	}
//}


//void heapSort(int a[], int len) {
//	if (a == NULL || len < 2)
//		return;
//	for (int i = len-1;i >= 0;i--) {
//		heapInsert(a, i);
//	}
//	swap(a, 0, len-1);
//	heapify(a, 0, --len);
//	while (len > 0) {
//		swap(a, 0, len-1);
//		heapify(a, 0, --len);
//	}
//}

//void minRoot(int a[], int index) {
//	while (index > 0) {
// 
//		if (a[index] < a[(index - 1) / 2]) {
//			swap(a, index, (index-1)/2);
//			index = (index - 1) / 2;
//		}
//	}
//}

void sortDistanceK(int a[], int len, int k) {
	priority_queue<int, vector<int>, greater<int> > q;
	int i = 0;
	for (i = 0;i < k;i++) {
		q.push(a[i]);
	}
	int j;
	for (j=0;i < len;j++,i++) {
		q.push(a[i]);
		a[j] = q.top();
		q.pop();
	}

	while (!q.empty()) {
		a[j++] = q.top();
		q.pop();
	}
}

void SortDistanceK(int a[], int len,int k) {
	priority_queue<int, vector<int>, greater<int>> q;
	int i = 0;
	for (;i < (k + 1 > len ? len : k+1);i++) {
		q.push(a[i]);
	}

	int j = 0;
	for (;i < len;++i) {
		a[j++] = q.top();
		q.pop();
		q.push(a[i]);
	}

	for (;j < len;j++) {
		a[j] = q.top();
		q.pop();

	}
}


//��������
void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


//heapInsert
void heapInsert(int a[], int i) {
	while (a[i] > a[(i-1)/2]) {
		swap(a, i, (i-1)/2);
		i = (i - 1) / 2;
	}
}


void heapify(int a[], int i, int heapsize) {
	int left = 2*i + 1;
	
	while (left < heapsize) {
		int largest = (left + 1 < heapsize && a[left + 1] > a[left] ? left + 1 : left);
		if (a[largest] > a[i]) {
			swap(a, largest, i);
			i = largest;
			left = 2 * i + 1;
		}
		else
			break;
	}
}

void heapSort(int a[], int len) {
	if (a == NULL || len < 2) {
		return;
	}
	for (int i = 0; i < len; i++) {
		//ÿ���ڵ���룬��ά������ѣ�
		heapInsert(a, i);
	}
	//�������ֵ��������һ��Ԫ��
	while (len) {
		swap(a, 0, len-1);
		heapify(a,0,--len);
		//len--;
	}
}

void HeapSort(int a[], int len) {
	if (a == NULL || len < 2) {
		return;
	}
	for (int i = len-1;i >=0 ;i--) {
		heapInsert(a, i);
	}
	while (len) {
		swap(a, 0,len-1);
		heapify(a, 0, --len);
	}
}




int d[10] = { 1,0,3,2,4,5,7,6,8,9 };


int main() {
	
	//SortDistanceK(d, 10, 4);
	HeapSort(d, 10);
	print(d, 10);
	return 0;
}

