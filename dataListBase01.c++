#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
struct list {
	Node* head;
	Node* tail;
};
Node* createNode(int initdata) {
	Node* node = new Node;
	node->data = initdata;
	node->next = NULL;
	return node;
}
void createList(list& l) {
	l.head = NULL;
	l.tail = NULL;
}
void Addhead(list& l, Node* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	else {
		node->next = l.head;
		l.head = node;
	}
}
void Addtail(list&l, Node* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	else {
		l.tail->next = node;
		l.tail = node;
	}
}
void InsertAfterQ(list& l, Node* p, Node* q) {
if (q != NULL)
	{
		p->next = q->next;
		q->next = p;
		if (l.tail == q)
			l.tail = p;
	}
	else
		Addhead(l, p);
}
int Removehead(list& l, int& x) {
if (l.head != NULL)
	{
		Node* node = l.head;
		x = node->data;
		l.head = node->next;
		delete node;
		if (l.head == NULL)
			l.tail = NULL;
		return 1;
	}
	return 0;
}
int RemoveAfterQ(list& l, Node* q, int& x) {
	if (q != NULL)
	{
		Node* p = q->next;
		if (p != NULL)
		{
			if (l.tail == p)
				l.tail = q;
			q->next = p->next;
			x = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}
int RemoveXs(list& l, int x) {
	Node* p = l.head;
	Node* q = NULL;
	while (p != NULL && p->data != x) {
		q = p;
		p = p->next;
	}
	if (p == NULL) return 0;
	if (q != NULL) RemoveAfterQ(l, q, x);//int x is value of delete<RemoveXs>
	else Removehead(l,x);
	return 1;
}
void printList(list l) {
	if (l.head != NULL) {
		Node* node = l.head;
		while (node != NULL) {
			cout << node->data << " ";
			node = node->next;
		}
	}
}
Node* search(list l, int x) {
	Node* node = l.head;
	while (node != NULL && node->data != x) {
		node = node->next;
	}
	if (node != NULL) return node;
	return NULL;
}
int length(list l) {
	int count = 0;
	Node* node = l.head;
	while (node != NULL) {
		count++;
		node = node->next;
	}
	return count;
}
void destroyList(list& l) {
	int x;// x is value data of delete node, can use array to replace..<Removehead> need a object<--to save data--> to call !
	Node* node = l.head;
	while (node != NULL) {
		Removehead(l, x);
		node = l.head;
	}
	l.tail = NULL;
}
Node* getNode(list l, int index) {
	Node* node = l.head;
	int i = 0;
	while (node != NULL && i != index) {
		node = node->next;
		i++;
	}
	if (i == index && node != NULL) {
		return node;
	}
	return NULL;
}
bool checkPrime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i < n - 1; i+=2) {
		if (n % i == 0) return false;
	}
	return true;
}
int CountAppear(int a[], int n,int num) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == num) count++;
	}
	return count;
}
int CheckAppear(int a[], int n, int num) {
	for (int i = 0; i < n; i++) {
		if (a[i] == num) return 1;
	}
	return 0;
}
void NumAppear(list l) {
	int n = length(l);
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		Node* node = getNode(l, i);
		p[i] = node->data;
	}
	cout << endl;
	int* arr = new int[n];
	int narr = 0;
	for (int i = 0; i < n; i++) {
		if (CheckAppear(arr, narr, p[i]) == 0) {
			arr[narr] = p[i];
			narr++;
		}
	}
	cout << "Danh sach vua nhap la: "; printList(l);
	cout << endl;
	cout << "So lan xuat hien cua tung phan tu trong danh sach la:\n";
	for (int i = 0; i < narr; i++) {
		cout << arr[i] << ": " << CountAppear(p, n, arr[i]) << endl;
	}
}
void OddEvenCheck(int a[], int n, int odd[], int &nodd, int even[], int &neven) {
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			odd[nodd] = a[i];
			nodd++;
		}
		else {
			even[neven] = a[i];
			neven++;
		}
	}
}
void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
void OddEven(list l) {
	int n = length(l);
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		Node* node = getNode(l, i);
		p[i] = node->data;
	}
	cout << endl;
	int* arr = new int[n];
	int narr = 0;
	for (int i = 0; i < n; i++) {
		if (CheckAppear(arr, narr, p[i]) == 0) {
			arr[narr] = p[i];
			narr++;
		}
	}
	cout << "Danh sach vua nhap la: "; printList(l);
	cout << endl;
	int* odd = new int[n];
	int* even = new int[n];
	int nodd = 0, neven = 0;
	OddEvenCheck(arr, narr, odd, nodd, even, neven);
	cout << "Cac so chan trong danh sach la: "; print(odd, nodd);
	cout << endl;
	cout << "Cac so le trong danh sach la: "; print(even, neven);
}
void PrimeNegative(list l) {
	cout << "Danh sach vua nhap la: "; printList(l);
	cout << endl;
	int index = 1;
	int count = 0;
	Node* node = l.head;
	while (node != NULL) {
		if (checkPrime(node->data) == true && index % 2 != 0) count++;
		index++;
		node = node->next;
	}
	cout << "Danh sach co " << count << " so nguyen to o vi tri le.";
}
int main() {
	list listss;
	createList(listss);
	Node* node;
	int x;
	do {  
		cin >> x;
		if (x == 0) break;
			node = createNode(x);
			Addtail(listss, node);
	} while (x != 0);
	if (listss.head == NULL) cout << "Danh sach rong.";
	//else PrimeNegative(listss);
	//else NumAppear(listss);
	else OddEven(listss);
	return 0;
}