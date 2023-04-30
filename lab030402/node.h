#pragma once
#include"Header.h"
struct Node {
	int data;
	Node* next;
};
struct list {
	Node* head;
	Node* tail;
};
Node* createNode(int initdata);
void createlist(list& l);
void addhead(list& l, Node* node);
void addtail(list& l, Node* node);
void InsertAfterQ(list& l, Node* p, Node* q);
int removehead(list& l, int &x);
int removeAfterQ(list& l, Node* q, int& x);
int removeXs(list& l, int x);
void printList(list l);
Node* search(list l, int x);
int length(list l);
void OddEvenCheck(list l);
Node* getNode(list l, int index);
//void OddEven(list l);
void randomData(list& l,int seed);

