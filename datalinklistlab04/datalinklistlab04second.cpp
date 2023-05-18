/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
template
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct Node {
	int data;
	Node* next;
};
struct list {
	Node* head;
	Node* tail;
};
Node* createNode(int initdata) {
	Node* node = new Node;
	node->data = initdata;
	node->next = NULL;
	return node;
}
void createList(list& l) {
	l.head = NULL;
	l.tail = NULL;
}
void addhead(list& l, Node* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	else {
		node->next = l.head;
		l.head = node;
	}
}
void addtail(list& l, Node* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	}
	else {
		l.tail->next = node;
		l.tail = node;
	}
}
Node* search(list l, int x) {
	Node* node = l.head;
	while (node != NULL && node->data != x) {
		node = node->next;
	}
	if (node != NULL) return node;
	else return NULL;
}
void insertAfterQ(list& l, Node* p, Node* q) {
	if (q != NULL) {
		p->next = q->next;
		q->next = p;
		if (l.tail == q) l.tail = p;
	}
	else addhead(l, p);
}
void printList(list l) {
	if (l.head != NULL) {
		Node* node = l.head;
		while (node != NULL) {
			cout << node->data << " ";
			node = node->next;
		}
	}
}
struct non_Node {
	int data;
	non_Node* left;
	non_Node* right;
};
typedef non_Node* tree;
non_Node* createNonNode(int initdata) {
	non_Node* p = new non_Node;
	p->data = initdata;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void createTree(tree& root) {
	root = NULL;
}
void addNode(tree& root, non_Node* node) {
	if (root) {
		if (root->data == node->data) return;
		if (node->data < root->data) addNode(root->left, node);
		else addNode(root->right, node);
	}
	else {
		root = node;
	}
}
int tree_height(non_Node* root) {
	if (!root) return 0;
	else {
		int left_height = tree_height(root->left);
		int right_height = tree_height(root->right);
		if (left_height >= right_height) return left_height + 1;
		else return right_height + 1;
	}
}
void input(tree& root, list link) {
	Node* node = link.head;
	non_Node* xm;
	while (node != NULL) {
		xm = createNonNode(node->data);
		addNode(root, xm);
		node = node->next;
	}
}
void PrintTree(tree root)// print tree using LNR
{
	if (root)
	{
		cout << root->data << ' ';
		PrintTree(root->left);
		PrintTree(root->right);
	}
}
int main() {
	list link;
	tree myTree;
	createTree(myTree);
	createList(link);
	Node* node;
	int mode=0;
	int value;
	int non_value;
	do {
		cin >> mode;
		if (mode == 3) break;
		switch (mode)
		{
		case 0: {
			cin >> value;
			if (search(link, value) == NULL) {
				node = createNode(value);
				addhead(link, node);
				break;
			}
			break;
		}
		case 1: {
			cin >> value;
			if (search(link, value) == NULL) {
				node = createNode(value);
				addtail(link, node);
				break;
			}
			break;
		}
		case 2: {
			cin >> non_value >> value;
			if (search(link, value) == NULL) {
				node = createNode(value);
				Node* non_node = search(link, non_value);
				insertAfterQ(link, node, non_node);
				break;
			}
			break;
		}
		default:
			break;
		}
		/*cout << "\n>>";
		printList(link);
		cout << "<<\n";*/
	//	cout << "\n<< " << tree_height(myTree)-1 << " >>\n";
	} while (mode != 3);
	input(myTree, link);
	cout << tree_height(myTree)-1;
	/*cout << "\n";
	PrintTree(myTree);*/
	return 0;
}