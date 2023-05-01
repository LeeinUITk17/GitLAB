#pragma once
#include"Header.h"
struct Node {
	int data;
	Node* left;
	Node* right;
};
typedef Node* tree;
Node* createNode(int initdata);
void createTree(tree& root);
void destroyTree(tree& root);
void addNode(tree& root, Node* node);
Node* findNode(tree root, int x);
void printTree(tree root);
void NLR(tree root);
void LNR(tree root);
void LRN(tree root);
void findandReplaceLeft(tree& p, tree& Tree);
void findandReplaceRight(tree& p, tree& Tree);
void randominf(tree& root,int seed);