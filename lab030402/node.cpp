#include"node.h"
Node* createNode(int initdata) {
	Node* node = new Node;
	node->data = initdata;
	node->next = NULL;
	return node;
}
void createlist(list& l) {
	l.head = NULL;
	l.tail = NULL;
}
void addhead(list& l, Node* node) {
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
		l.tail = node;
	}
}
void InsertAfterQ(list& l, Node* p, Node* q) {
	if (q != NULL) {
		p->next = q->next;
		q->next = p;
		if (l.tail == q) l.tail = p;
	}
	else addhead(l, p);
}
int removehead(list& l, int& x) {
	if (l.head != NULL) {
		Node* node = l.head;
		x = node->data;
		l.head = node->next;
		delete node;
		if (l.head == NULL) {
			l.tail = NULL;
		}
		return 1;
	}
	return 0;
}
int removeAfterQ(list& l, Node* q, int& x) {
	if (q != NULL) {
		Node* p = q->next;
		if (p != NULL) {
			if (l.tail == p) l.tail = q;
			q->next = p->next;
			x = p->data;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}
int removeXs(list& l, int x) {
	Node* p = l.head;
	Node* q = NULL;
	while (p != NULL && p->data != x) {
		q = p;
		p = p->next;
	}
	if (p == NULL) return 0;
	if (q != NULL) removeAfterQ(l, q, x);
	else removehead(l, x);
	return 1;
}
void printList(list l) {
	if (l.head != NULL) {
		Node* node = l.head;
		while (node != NULL) {
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
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
		node = node->next;
		i++;
	}
	if (i == index && node != NULL) return node;
	return NULL;
}
void OddEvenCheck(list l) {
	int* p = new int[length(l)];
	for (int i = 0; i < length(l); i++) {
		Node* node = getNode(l, i);
		p[i] = node->data;
	}
	int* odd = new int[length(l)];
	int* even = new int[length(l)];
	int nOdd = 0, nEven = 0;
	for (int i = 0; i < length(l); i++) {
		if (p[i] % 2 == 0) {
			odd[nOdd] = p[i];
			nOdd++;
		}
		else {
			even[nEven] = p[i];
			nEven++;
		}
	}
	cout << "Odd: " << nOdd << " && " << "Even: " << nEven << endl;
}
void randomData(list& l,int seed) {
	srand(seed);
	Node* node;
	int n = 5 + rand() % 101;
	node = createNode(n);
	addtail(l, node);
}