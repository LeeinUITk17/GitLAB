#include"Tree.h"
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
nonNode* createNonNode(int initdata) {
	nonNode* p = new nonNode;
	p->data = initdata;
	p->left = NULL;
	p->right = NULL;
	return p;
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
int tree_height(nonNode* root) {
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
	nonNode* xm;
	while (node != NULL) {
		xm = createNonNode(node->data);
		addNode(root, xm);
		node = node->next;
	}
}
void LNR(tree root)
{
	if (root)
	{
		LNR(root->left);
		cout << root->data << ' ';
		LNR(root->right);
	}
}
void LRN(tree root) {
	if (root)
	{
		LNR(root->left);
		LNR(root->right);
		cout << root->data << ' ';
	}
}
void NLR(tree root) {
	if (root)
	{
		cout << root->data << ' ';
		LNR(root->left);
		LNR(root->right);
	}
}
void NRL(tree root) {
	if (root)
	{
		cout << root->data << ' ';
		LNR(root->right);
		LNR(root->left);
	}
}
void RNL(tree root) {
	if (root)
	{
		LNR(root->right);
		cout << root->data << ' ';
		LNR(root->left);
	}
}
void RLN(tree root) {
	if (root)
	{
		LNR(root->right);
		LNR(root->left);
		cout << root->data << ' ';
	}
}
nonNode* search(nonNode* root, int key) {
	if (root == NULL || root->data == key) {
		return root;
	}
	if (root->data < key) return search(root->right, key);
	return search(root->left, key);
}
void searchStandFor(tree& pHuy, tree& pTM) {
	if (pTM->left != NULL) searchStandFor(pHuy, pTM->left);
	else {
		pHuy->data = pTM->data;
		pHuy = pTM;
		pTM = pTM->right;
	}
}
void remove(tree& root, int key) {
	if (root != NULL) {
		if (key < root->data) remove(root->left, key);
		else if (key > root->data) remove(root->right, key);
		else {
			nonNode* pHuy = root;
			if (root->left == NULL) root = root->right;
			else if (root->right == NULL) root = root->left;
			else searchStandFor(pHuy, root->right);
			delete pHuy;
		}
	}
}
int sum(tree root)
{
	if (root == NULL) return 0;
	//cout << "\n<>" << sum(root->left) + sum(root->right) + root->data << "\n";
	return sum(root->left) + sum(root->right) + root->data;
}
int branch2s(tree root,int &count) {
	if (root) {
		if (root->left != NULL && root->right != NULL) count++;
		branch2s(root->left,count);
		branch2s(root->right,count);
	}
	return count;
}
int branch1s(tree root, int& count) {
	if (root) {
		if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL)) count++;
		branch1s(root->left, count);
		branch1s(root->right, count);
	}
	return count;
}
int branch1sRight(tree root, int& count) {
	if (root) {
		if ((root->left == NULL && root->right != NULL)) count++;
		branch1s(root->left, count);
		branch1s(root->right, count);
	}
	return count;
}
int leaf(tree root,int &count) {
	if (root) {
		if ((root->left == NULL && root->right == NULL)) count++;
		branch1s(root->left, count);
		branch1s(root->right, count);
	}
	return count;
}