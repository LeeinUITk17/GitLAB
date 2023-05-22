#include"Header.h"
struct Node {
	int key;
	Node* next;
};
Node* createNode(int initdata) {
	Node* node = new Node;
	node->key = initdata;
	node->next = NULL;
	return node;
}
typedef Node* HashTable[size];
void initHashTable(HashTable& ht) {
	for (int i = 0; i < size; i++) {
		ht[i] = NULL;
	}
}
int Hash(int k)
{
	return k % size;
}
void addtail(Node*& list, int k) {
	Node* newNode = createNode(k);
	if (list == NULL) {
		list = newNode;
	}
	else {
		Node* p = list;
		while (p != NULL && p->next != NULL) p = p->next;
		p->next = newNode;
	}
}
void insertNode(HashTable& ht, int k) {
	int i = Hash(k);
	addtail(ht[i], k);
}
void deleteHead(Node*& list) {
	if (list != NULL) {
		Node* p = list;
		list = list->next;
		delete p;
	}
}
void deleteAfterQ(Node*& q) {
	Node* p = q->next;
	if (p != NULL) {
		q->next = p->next;
		delete p;
	}
}
void deleteNode(HashTable& ht, int k) {
	int i = Hash(k);
	Node* p = ht[i];
	Node* q = p;
	while (p != NULL && p->key != k) {
		q = p;
		p = p->next;
	}
	if (p == NULL) cout << k << "not found..!\n";
	else if (p == ht[i]) deleteHead(ht[i]);
	else deleteAfterQ(q);
}
Node* searchNode(HashTable ht, int k) {
	int i = Hash(k);
	Node* p = ht[i];
	while (p != NULL && p->key != k) {
		p = p->next;
	}
	if (p == NULL) return NULL;
	return p;
}
void Traverse(Node* p) {
	while (p != NULL) {
		cout << p->key << " ";
		p = p->next;
	}
	cout << endl;
}
void TraverseHashTable(HashTable ht) {
	for (int i = 0; i < size; i++) {
		cout << "Bucket " << i << " : ";
		Traverse(ht[i]);
	}
}
