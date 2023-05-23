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
void createList(list& l);
void addhead(list& l, Node* node);
void addtail(list& l, Node* node);
void printList(list l);
struct nonNode {
	int data;
	nonNode* left;
	nonNode* right;
};
typedef nonNode* tree;
nonNode* createNonNode(int initdata);
void createTree(tree& root);
void addNode(tree& root, nonNode* node);
int tree_height(nonNode* root);
void input(tree& root, list link);
void LNR(tree root);
void LRN(tree root);
void NLR(tree root);
void NRL(tree root);
void RNL(tree root);
void RLN(tree root);
nonNode* search(nonNode* root, int key);
void searchStandFor(tree& Huy, tree& pTM);
void remove(tree& root, int key);
int sum(tree root);
int branch2s(tree root,int &count);
int branch1s(tree root, int& count);
int branch1sRight(tree root, int& count);
int leaf(tree root,int&count);
