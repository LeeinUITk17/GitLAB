#include<iostream>
using namespace std;
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
void createlist(list& l) {
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
Node* search(list& l, int x) {
	Node* node = l.head;
	while (node != NULL && node->data != x) {
		node = node->next;
	}
	if (node != NULL)return node;
	else return NULL;
}
struct nonNode {
	int data;
	nonNode* left;
	nonNode* right;
};
typedef nonNode* tree;
nonNode* createnonNode(int initdata) {
	nonNode* node = new nonNode;
	node->data = initdata;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void createTree(tree& root) {
	root = NULL;
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
void input(tree& root, list link) {
	Node* node = link.head;
	nonNode* xm;
	while (node != NULL) {
		xm = createnonNode(node->data);
		addNode(root,xm);
		node = node->next;
	}
}
void findkey(tree root,int key,list&link) {
	if (root) {
		if (root->data == key) {
			Node* node = createNode(root->data);
			addtail(link, node);
		}
		else if (key < root->data) {
			Node* node = createNode(root->data);
			addtail(link, node);
			findkey(root->left, key, link);
		}
		else {
			Node* node = createNode(root->data);
			addtail(link, node);
			findkey(root->right, key, link);
		}
	}
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
void PrintTree(tree root)// print tree using LNR
{
	if (root)
	{
		cout << root->data << ' ';
		PrintTree(root->left);
		PrintTree(root->right);
	}
}
void findRoot(list link1, list link2) {
	Node* node1 = link1.head;
	Node* node2 = link2.head;
	while (node1 == node2) {
		node1 = node1->next;
		node2 = node2->next;
	}
	cout << node1->data;
}
int valueReplace(list l,int origin) {
	int value=origin;
	Node* p = l.head;
	while (p != NULL) {
		if (p->data > origin) {
			value += p->data;
		}
		p = p->next;
	}
	return value;
}
void SortList(list& l)
{
	for (Node* pTmp = l.head; pTmp != NULL; pTmp = pTmp->next)
	{
		for (Node* pTmp2 = pTmp->next; pTmp2 != NULL; pTmp2 = pTmp2->next)
		{
			if (pTmp->data < pTmp2->data) 
			{
				int tmp = pTmp->data;
				pTmp->data = pTmp2->data;
				pTmp2->data = tmp;
			}
		}
	}
}
void inputList(tree root, list& l) {
	if (root) {
		Node* node = createNode(root->data);
		addtail(l, node);
		inputList(root->left, l);
		inputList(root->right, l);
	}
}
void replace(tree root, list &newlink) {
	inputList(root, newlink);
	Node* node = newlink.head;
	list nonlink;
	createlist(nonlink);
	while (node != NULL) {
		Node* rp = createNode(valueReplace(newlink, node->data));
		addtail(nonlink, rp);
		node = node->next;
	}
	SortList(nonlink);
	printList(nonlink);
}
nonNode* findAncestor(tree root, int v1, int v2) {
	if (root == nullptr) return nullptr;


	if (root->data == v1 || root->data == v2)
		return root;

	nonNode* left = findAncestor(root->left, v1, v2);
	nonNode* right = findAncestor(root->right, v1, v2);


	if (left != nullptr && right != nullptr) {
		return root;
	}

	return (left != nullptr) ? left : right;
}
int main() {
	list link;
	tree myTree;
	createTree(myTree);
	createlist(link);
	int n;
	cin >> n;
	int value;
	for (int i = 0; i < n; i++) {
		cin >> value;
		Node* node = createNode(value);
		addtail(link, node);
	}
	input(myTree, link);
	list newlink;
	createlist(newlink);
	replace(myTree, newlink);
	return 0;
}