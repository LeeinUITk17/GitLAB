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
void NhapList(List& l,Node*node) {
	if (l.pHead == NULL) {
		l.pHead = node;
		l.pTail = node;
	}
	else {
		node->pNext = l.pHead;
		l.pHead = node;
	}
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
void Split(List l, List& l1, List& l2) {

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
