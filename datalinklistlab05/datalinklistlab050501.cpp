/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[
]
template
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
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
struct list {
	Node* head;
	Node* tail;
};
void createlist(list& l) {
	l.head = NULL;
	l.tail = NULL;
}
void addtail(list& link, Node* node) {
	if (link.head == NULL) {
		link.head = node;
		link.tail = node;
	}
	else {
		link.tail->next = node;
		link.tail = node;
	}
}
struct nonNode {
	int data;
	int frequency;
	nonNode* left;
	nonNode* right;
};
typedef nonNode* tree;
void createTree(tree& root) {
	root = NULL;
}
nonNode* createnonNode(int initdata,int data) {
	nonNode* node = new nonNode;
	node->data = initdata;
	node->frequency = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void addNode(tree& root, nonNode* node) {
	if (root) {
		if (root->data == node->data) return;
		if (node->data < root->data) addNode(root->left, node);
		else addNode(root->right, node);
	}
	else {
		root = node;
	}
}
void sortlist(list& l) {
	for (Node* node = l.head; node != NULL; node = node->next) {
		for (Node* node2s = node->next; node2s != NULL; node2s = node2s->next) {
			if (node->data > node2s->data) {
				int temp = node->data;
				node->data = node2s->data;
				node2s->data = temp;
			}
		}
	}
}
void printlist(list link) {
	Node* node = link.head;
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}
void printTree(tree root) {
	if (root) {
		cout << root->data << " "<<root->frequency<<"\n";
		printTree(root->left);
		printTree(root->right);
	}
}
void rootTolist(tree root, list& l) {
	if (root) {
		Node* node = createNode(root->data);
		addtail(l, node);
		rootTolist(root->left,l);
		rootTolist(root->right, l);
	}
}
void Frequency(list link, tree &root) {
	list newlink;
	createlist(newlink);
	rootTolist(root,newlink);
	//printlist(newlink);
	//cout << "\n\t check\n";
	for (Node* node1s = newlink.head; node1s != NULL; node1s = node1s->next) {
		int flag = 0;
		for (Node* node2s = link.head; node2s != NULL; node2s = node2s->next) {
			//cout << "\n\t>>" << node1s->data << " & " << node2s->data << "\n";
			if (node1s->data == node2s->data) flag++;
		}
		node1s->data = flag;
	}
	//printlist(newlink);
	list frelink;
	createlist(frelink);
	rootTolist(root, frelink);
	tree newTree;
	createTree(newTree);
	Node* n = frelink.head;
	Node* m = newlink.head;
	while (n != NULL&&m!=NULL) {
		nonNode* rm = createnonNode(n->data, m->data);
		addNode(newTree, rm);
		n = n->next;
		m = m->next;
	}
	printTree(newTree);
}
void input(list& l) {
	tree root;
	createTree(root);
	int value;
	do {
		cin >> value;
		if (value == 0) break;
		Node* node = createNode(value);
		addtail(l, node);
	} while (value != 0);
	sortlist(l);
	Node* node = l.head;
	while (node != NULL) {
		nonNode* rp = createnonNode(node->data,0);
		addNode(root, rp);
		node = node->next;
	}
	Frequency(l, root);
}
int main() {
	list link;
	createlist(link);
	printlist(link);
	/*cout << "\n\t Tree\n";
	printTree(myTree);*/
	input(link);
	return 0;
}