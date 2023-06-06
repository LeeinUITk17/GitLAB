#include<iostream>
using namespace std;
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
nonNode* createnonNode(int initdata) {
	nonNode* node = new nonNode;
	node->data = initdata;
	node->frequency = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void addNode(tree& root, nonNode* node) {
	if (root) {
		if (root->data == node->data) {
			root->frequency++;
			return;
		}
		if (node->data < root->data) addNode(root->left, node);
		else addNode(root->right, node);
	}
	else {
		root = node;
	}
}
void printTree(tree root) {
	if (root) {
		printTree(root->left);
		cout << root->data << " " << root->frequency << "\n";
		printTree(root->right);
	}
}
void input(tree& root) {
	int value;
	do {
		cin >> value;
		if (value == 0) break;
		nonNode* node = createnonNode(value);
		addNode(root, node);
	} while (value != 0);
}
//void rootTolist(tree root, list& l) {
//	if (root) {
//		Node* node = createNode(root->data);
//		addtail(l, node);
//		rootTolist(root->left, l);
//		rootTolist(root->right, l);
//	}
//}
//void Frequency(list link, tree root) {
//	list newlink;
//	createlist(newlink);
//	rootTolist(root, newlink);
//	//printlist(newlink);
//	//cout << "\n\t check\n";
//	for (Node* node1s = newlink.head; node1s != NULL; node1s = node1s->next) {
//		int flag = 0;
//		for (Node* node2s = link.head; node2s != NULL; node2s = node2s->next) {
//			//cout << "\n\t>>" << node1s->data << " & " << node2s->data << "\n";
//			if (node1s->data == node2s->data) flag++;
//		}
//		node1s->data = flag;
//	}
//	//printlist(newlink);
//	list frelink;
//	createlist(frelink);
//	rootTolist(root, frelink);
//	tree newTree;
//	createTree(newTree);
//	Node* n = frelink.head;
//	Node* m = newlink.head;
//	while (n != NULL) {
//		nonNode* rp = createnonNode(n->data, m->data);
//		addNode(newTree, rp);
//		n = n->next;
//		m = m->next;
//	}
//	printTree(newTree);
//}
//void input(list& l) {
//	tree root;
//	createTree(root);
//	int value;
//	do {
//		cin >> value;
//		if (value == 0) break;
//		Node* node = createNode(value);
//		addtail(l, node);
//	} while (value != 0);
//	sortlist(l);
//	Node* node = l.head;
//	while (node != NULL) {
//		nonNode* rp = createnonNode(node->data, 0);
//		addNode(root, rp);
//		node = node->next;
//	}
//	Frequency(l, root);
//}
int main() {
	tree myTree;
	createTree(myTree);
	input(myTree);
	printTree(myTree);
	return 0;
} 