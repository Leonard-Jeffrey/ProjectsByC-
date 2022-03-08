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




////大根堆
////1. 插入新值，维持大堆；
//// 插入一个新的值
////2. 返回最大值，维持大堆；
////3. 从任意位置维持大堆；
//void swap(int a[], int i, int j) {
//	int temp = a[i];
//	a[i] = a[j];
//	a[j] = temp;
//}
//
////元素向上移动
//void heapInsert(int a[], int index) {
//	//判断条件包含了终止的两种情况；
//	//1）到达根节点；
//	//2）小于等于父节点；
//	while (a[index] > a[(index - 1) / 2]) {
//		swap(a,index,(index - 1)/2);
//		index = (index - 1) / 2;
//	}
//}
//
////元素向下移动
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


//交换函数
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
		//每个节点插入，并维护大根堆；
		heapInsert(a, i);
	}
	//交换最大值与堆上最后一个元素
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

