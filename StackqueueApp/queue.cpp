#include"Header.h"
struct queue {
	Node* head;
	Node* tail;
};
void createQueue(queue& q) {
	q.head = NULL;
	q.tail = NULL;
}
int isemptyQueue(queue q) {
	if (q.head == NULL) {
		return 1;
	}
	return 0;
}
void enqueue(queue& q, Node* node) {
	if (q.head == NULL) {
		q.head = node;
		q.tail = node;
	}
	else {
		q.tail->next = node;
		q.tail = node;
	}
}
int dequeue(queue& q) {
	if (isemptyQueue(q)) return 0;
	Node* node = q.head;
	int data = node->data;
	q.head = node->next;
	delete node;
	if (q.head == NULL) {
		q.tail = NULL;
	}
	return data;
}
int front(queue q) {
	if (isemptyQueue(q)) return 0;
	return q.head->data;
}
void destroyQueue(queue& q) {
	Node* node = q.head;
	while (node != NULL) {
		q.head = node->next;
		delete node;
		node = q.head;
	}
	q.tail = NULL;
}
void printQueue(queue q) {
	Node* node = q.head;
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}