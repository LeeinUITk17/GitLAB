#pragma once
#include<iostream>
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
