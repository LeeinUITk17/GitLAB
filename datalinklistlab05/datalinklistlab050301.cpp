/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include

###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -
struct Node {
	string data;
	string nondata;
	Node* left;
	Node* right;
};
Node* createNode(string initdata, string initnondata) {
	Node* node = new Node;
	node->data = initdata;
	node->nondata = initnondata;
	node->left = NULL;
	node->right = NULL;
	return node;
}
typedef Node* tree;
void createTree(tree& root) {
	root = NULL;
}
void addNode(tree& root, Node* node) {
	if (root) {
		//cout <<"\n\t>>" << root->data[0] << "<<\n";
		if (root->nondata > node->nondata) addNode(root->left, node);
		else addNode(root->right, node);
	}
	else {
		root = node;
	}
}
void printTree(tree root) {
	if (root) {
		cout << root->data << " " << root->nondata<<" ";
		printTree(root->left);
		printTree(root->right);
	}
}
void input(tree& root, int m) {
	string Data;
	string nonData;
	for (int i = 0; i < m; i++) {
		cin >> Data >> nonData;
		Node* node = createNode(Data, nonData);
		addNode(root, node);
	}
}
struct nonNode {
	string data;
	nonNode* next;
};
nonNode* createnonNode(string initdata) {
	nonNode* node = new nonNode;
	node->data = initdata;
	node->next = NULL;
	return node;
}
struct list {
	nonNode* head;
	nonNode* tail;
};
void createlist(list& l) {
	l.head = NULL;
	l.tail = NULL;
}
void addtail(list& l, nonNode* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	else {
		l.tail->next = node;
		l.tail = node;
	}
}
void inputList(list& l, int n) {
	string value;
	for (int i = 0; i < n; i++) {
		cin >> value;
		nonNode* node = createnonNode(value);
		addtail(l, node);
	}
}
void printlist(list l) {
	nonNode* node = l.head;
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}
void search(tree root, string key) {
	while (root != NULL) {
		if (root->nondata == key) break;
		if (root->nondata > key) root = root->left;
		else root = root->right;
	}
	if (root == NULL) cout << "eh ";
	else cout << root->data << " ";
}
void searchMethod(tree root, list link) {
	nonNode* node = link.head;
	while (node != NULL) {
			search(root, node->data);
			node = node->next;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	tree myTree;
	createTree(myTree);
	input(myTree, m);
	//printTree(myTree);
	list link;
	createlist(link);
	inputList(link, n);
	searchMethod(myTree, link);
	return 0;
}