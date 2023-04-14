#include<iostream>
#include<time.h>
#define size 10
using namespace std;
struct Node {
	int data;
	Node* next;
};
Node* createNode(int initdata) {
	Node* node = new Node;
	node->data = initdata;
	node->next = NULL;
	return node;
}
struct stack {
	Node* head;
};
void createStack(stack& s) {
	s.head = NULL;
}
int isEmpty(stack s) {
	if (s.head == NULL) return 1;
	return 0;
}
void push(stack& s, Node* node) {
	if (s.head == NULL) {
		s.head = node;
	}
	else {
		node->next = s.head;
		s.head = node;
	}
}
int pop(stack& s) {
	if (isEmpty(s) == 1) return 0;
	Node* node = s.head;
	int data = node->data;
	s.head = node->next;
	delete node;
	return data;
}
int top(stack s) {
	if (isEmpty(s) == 1) return 0;
	return s.head->data;
}
void destroyStack(stack& s) {
	Node* node = s.head;
	while (node != NULL) {
		s.head = node->next;
		delete node;
		node = s.head;
	}
}
void printStack(stack s) {
	Node* node = s.head;
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}
int main() {
	stack ss;
	createStack(ss);
	srand(time(NULL));
	Node* node;
	for (int i = 0; i < size; i++) {
		node = createNode(rand() % 101);
		push(ss, node);
	}
	printStack(ss);
	pop(ss);
	cout << endl;
	printStack(ss);
	cout << endl;
	destroyStack(ss);
	printStack(ss);
	return 0;
}