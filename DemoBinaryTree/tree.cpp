#include"tree.h"
Node* createNode(int initdata) {
	Node* node = new Node;
	node->data = initdata;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void createTree(tree& root) {
	root = NULL;
}
void destroyTree(tree& root) {
	if (root) {
		destroyTree(root->left);
		destroyTree(root->right);
		delete root;
	}
}
void addNode(tree& root, Node* node) {
	if (root) {
		if (root->data == node->data) return;
		if (root->data < node->data) addNode(root->left, node);
		else addNode(root->right, node);
	}
	else root = node;
}
Node* findNode(tree root, int x) {
	if (root) {
		if (root->data == x) return root;
		if (x < root->data) {
			return findNode(root->left, x);
		}
		else findNode(root->right, x);
	}
	return NULL;
}
void printTree(tree root) {
	if (root) {
		printTree(root->left);
		cout << root->data << " ";
		printTree(root->right);
	}
}
void NLR(tree root) {
	if (root) {
		//xu ly nut goc <root>
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(tree root) {
	if (root) {
		LNR(root->left);
		//xu ly nut goc <root>
		LNR(root->right);
	}
}
void LRN(tree root) {
	if (root) {
		LRN(root->left);
		LRN(root->right);
		//xu ly nut goc <root>
	}
}
//p is node replace, Tree is tree handle <delete node>
void findandReplaceLeft(tree& p, tree& Tree) {
	if (Tree->left) {
		findandReplaceLeft(p, Tree->left);
	}
	else {
		p->data = Tree->data;//copy data
		p = Tree;//delete this tree node <delete tree left>
		Tree = Tree->right;//connect to tree right
	}
}
//p is node replace, Tree is tree handle <delete node>
void findandReplaceRight(tree& p, tree& Tree) {
	if (Tree->right) {
		findandReplaceRight(p, Tree->right);
	}
	else {
		p->data = Tree->data;//copy data
		p = Tree;//delete this tree node<delete tree right>
		Tree = Tree->left;//connect to tree left
	}
}
void randominf(tree& root,int seed) {
	srand(seed);
	Node* node;
	int n= 10 + rand() % 1001;
		node=createNode(n);
		addNode(root, node);
}