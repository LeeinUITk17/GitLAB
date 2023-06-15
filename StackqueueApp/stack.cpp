#include"Header.h"
struct stack {
	Node* head;
};
void createStack(stack& s) {
	s.head = NULL;
}
int isemptystack(stack s) {
	if (s.head == NULL) {
		return 1;
	}
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
	if (isemptystack(s)) return 0;
	Node* node = s.head;
	int data = node->data;
	s.head = node->next;
	delete node;
	return data;
}
int top(stack s) {
	if (isemptystack(s)) {
		return 0;
	}
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