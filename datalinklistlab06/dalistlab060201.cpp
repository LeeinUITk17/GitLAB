#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
};
typedef Node* tree;
void createTree(tree& root) {
	root = NULL;
}
Node* createNode(int initdata) {
	Node* node = new Node;
	node->data = initdata;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void addNode(tree& root, Node* node) {
	if (root) {
		if (root->data == node->data) return;
		if (node->data < root->data) {
			addNode(root->left, node);
		}
		else {
			addNode(root->right, node);
		}
	}
	else {
		root = node;
	}
}
void FindAndReplaceleft(tree& p, tree& root) {
	if (root->left) {
		FindAndReplaceleft(p, root->left);
	}
	else {
		p->data = root->data;
		p = root;
		root = root->right;
	}
}
void deleteNode(tree& root, int key) {
	if (root) {
		if (key > root->data) {
			deleteNode(root->right, key);
		}
		else if (key < root->data) {
			deleteNode(root->left, key);
		}
		else {
			Node* p = root;
			if (!root->left) {
				root = root->right;
			}
			else if (!root->right) {
				root = root->left;
			}
			else {
				FindAndReplaceleft(p, root->right);
				delete p;
			}
		}
	}
	else {
		return;
	}
}
Node* findnode(tree root, int key) {
	if (root) {
		if (root->data == key) {
			return root;
		}
		if (key < root->data) {
			return findnode(root->left, key);
		}
		else {
			return findnode(root->right, key);
		}
	}
	return NULL;
}
void input(tree& root) {
	int mode=-1;
	int value;
	do {
		cin >> mode >> value;
		if (mode == 0) break;
		switch (mode)
		{
		case 1: {
			Node* node = createNode(value);
			addNode(root, node);
			break;
		}
		case 2: {
			Node* node = findnode(root, value);
			if (node == NULL) {
				cout << "0";
			}
			else {
				cout << "1";
			}
			break;
		}
		case 3: {
			deleteNode(root, value);
			break;
		}
		default:
			break;
		}
	} while (mode != 0);
}
int main() {
	tree myTree;
	createTree(myTree);
	input(myTree);
	return 0;
}