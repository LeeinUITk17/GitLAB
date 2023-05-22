#pragma once
#include"Header.h"
struct Node {
	int key;
	Node* next;
};
Node* createNode(int initdata);
typedef Node* HashTable[size];
void initHashTable(HashTable& ht);
int Hash(int k);
void addtail(Node*& list, int k);
void insertNode(HashTable& ht, int k);
void deleteHead(Node*& list);
void deleteAfterQ(Node*& q);
void deleteNode(HashTable& ht, int k);