
#include <iostream>
using namespace std;
struct Node {  
	long data;
	Node* next;
};
struct list {
	Node* head;
	Node* tail;
};
Node* createNode(long initdata) {
	Node* node = new Node;
	node->data = initdata;
	node->next = NULL;
	return node;
}
void createList(list& l) {
	l.head = NULL;
	l.tail = NULL;
}
void addhead(list& l, Node* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	node->next = l.head;
	l.head = node;
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
int removeHead(list& l, long& x) {
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
int removeAfterQ(list& l, Node* q, long& x) {
	if (q != NULL) {
		Node* p = q->next;
		if (p != NULL) {
			if (l.tail == p) l.tail = q;
			q->next = p->next;
			delete p;
			return 1;
		}
		return 0;
	}
	return 0;
}
int removeXs(list& l, long x) {
	Node* p = l.head;
	Node* q = NULL;
	while (p != NULL && p->data != x) {
		q = p;
		p = p->next;
	}
	if (p == NULL) return 0;
	if (q != NULL) removeAfterQ(l, q, x);
	else removeHead(l, x);
	return 1;
}
int length(list l) {
	int count = 0;
	Node* p = l.head;
	while (p!= NULL) {
		count++;
		p = p->next;
	}
	return count;
}
Node* search(list l, long x) {
	Node* node = l.head;
	while (node != NULL && node->data != x) {
		node = node->next;
	}
	if (node != NULL) return node;
	return NULL;
}
int checkSearch(list l, long x) {
	Node* searchlist = search(l, x);
	if (searchlist != NULL) return 1;
	else return 0;
}
void InputValue(list& l) {
	Node* node;
	int x;
	do {
		cin >> x;
		if (x == 0) break;
		node = createNode(x);
		addtail(l, node);
	} while (x != 0);
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
void controlMode(list& l) {
	int control;
	Node* node;
	long x;
	do {
		cin >> control;
		if (control == 0) break;
		cin >> x;
		node = createNode(x);
		switch (control)
		{
		case 1: addhead(l, node);
			break;
		case 2: addtail(l, node);
			break;
		case 3:
			do {
				removeXs(l, x);
			} while (checkSearch(l, x) == 1);
			break;
		}
	} while (control != 0);
}
int main() {
	list link;
	createList(link);
	InputValue(link);
	if (link.head != NULL) {
		controlMode(link);
		printlist(link);
	}
	else return NULL;
	return 0;
}