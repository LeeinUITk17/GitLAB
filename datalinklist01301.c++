/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[]
template
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
	int info;
	Node* pNext;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

void CreateList(List& l);
void NhapList(List& l);
int DemSoPhanTu(List l);
void Split(List l, List& l1, List& l2);
void XuatList(List l);

int main()
{
	List l, l1, l2;
	CreateList(l);
	CreateList(l1);
	CreateList(l2);
	NhapList(l);
	if (DemSoPhanTu(l) == 0)
		cout << "Danh sach rong." << endl;
	else
	{
		cout << "Danh sach vua nhap la: ";
		XuatList(l);
		cout << endl;
		Split(l, l1, l2);
		cout << "Cac so chan trong danh sach la: ";
		XuatList(l1);
		cout << endl;
		cout << "Cac so le trong danh sach la: ";
		XuatList(l2);
		cout << endl;
	}
	return 0;
}

//###INSERT CODE HERE -
void CreateList(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
Node* createNode(int initData) {
	Node* node = new Node;
	node->info = initData;
	node->pNext = NULL;
	return node;
}
void Addtail(List &l, Node* node) {
	if (l.pHead == NULL) {
		l.pHead = node;
		l.pTail = node;
	}
	else {
		l.pTail->pNext = node;
		l.pTail = node;
	}
}
void NhapList(List& l) {
	Node* node;
	int x;
	do {
		cin >> x;
		if (x == 0) break;
		node = createNode(x);
		Addtail(l, node);
	} while (x != 0);
}
int DemSoPhanTu(List l) {
	int count = 0;
	Node* node = l.pHead;
	while (node != NULL) {
		count++;
		node = node->pNext;
	}
	return count;
}
Node* getNode(List l, int index) {
	Node* node = l.pHead;
	int i = 0;
	while (node != NULL && i != index) {
		i++;
		node = node->pNext;
	}
	if (i == index && node != NULL) {
		return node;
	}
	return NULL;
}
int checkAppear(int a[], int n, int num) {
	for (int i = 0; i < n; i++) {
		if (a[i] == num) return 1;
	}
	return 0;
}
void OddEvenCheck(int a[], int n, List& l1, List& l2) {
	for (int i = 0; i < n; i++) {
		//l1 odd list
		//l2 even list
		Node* node;
		if (a[i] % 2 == 0) {
			node = createNode(a[i]);
			Addtail(l1, node);
		}
		else {
			node = createNode(a[i]);
			Addtail(l2, node);
		}
	}
}
void Split(List l, List& l1, List& l2) {
	int n = DemSoPhanTu(l);
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		Node* node = getNode(l, i);
		p[i] = node->info;
	}
	int* arr = new int[n];
	int narr = 0;
	for (int i = 0; i < n; i++) {
		if (checkAppear(arr, narr, p[i]) == 0) {
			arr[narr] = p[i];
			narr++;
		}
	}
	OddEvenCheck(arr, narr, l1, l2);
}
void XuatList(List l) {
	if (l.pHead != NULL) {
		Node* node = l.pHead;
		while (node != NULL) {
			cout << node->info << " ";
			node = node->pNext;
		}
	}
}
