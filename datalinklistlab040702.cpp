/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[]
template
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -struct Node{
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
void addHead(list& l, Node* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	else {
		node->next = l.head;
		l.head = node;
	}
}
void addtail(list& l, Node* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	else {
		l.tail->next = node;
		node = l.tail;
	}
}
void insertAfterQ(list& l, Node* p, Node* q) {
	if (q != NULL) {
		p->next = q->next;
		q->next = p;
		if (l.tail == q) l.tail = q;
	}
	else addHead(l, p);
}
void printlist(list l) {
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
Node* getNode(list l, int index) {
	Node* node = l.head;
	int i = 0;
	while (node != NULL && i != index) {
		i++;
		node = node->next;
	}
	if (node != NULL && i == index) {
		return node;
	}
	return NULL;
}
void selectionSort(list& l, int n) {
	int min;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			Node*nodej = getNode(l, j);
			Node*nodemin = getNode(l, min);
			if (nodej->data < nodemin->data) min = j;
		}
		Node* nodei = getNode(l, i);
		Node* nodemin = getNode(l, min);
		int temp = nodei->data;
		nodei->data = nodemin->data;
		nodemin->data = temp;
	}
}
void InputArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void input(list& l, int a[],int n) {
	Node* node;
	int value;
	for (int i = 0; i < n; i++) {
		value = a[i];
		node = createNode(value);
		if(l.head!=NULL) selectionSort(l, length(l));
		addHead(l, node);
		selectionSort(l, length(l));
		printlist(l);
		cout << "\n";
	}
}
int main() {
	list link;
	createList(link);
	int n;
	cin >> n;
	int* arr = new int[n];
	InputArr(arr, n);
	input(link, arr,n);
	return 0;
}