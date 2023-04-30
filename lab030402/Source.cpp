#include"Header.h"
#include"node.h"
int main() {
	list link;
	createlist(link);
	for (int i = 0; i < size; i++) {
		randomData(link, i);
	}
	printList(link);
	int m = 5;
	Node*nodem = createNode(m);
	addhead(link, nodem);
	printList(link);
	cout << length(link);
	Node* searchNode = search(link, 5);
	if (searchNode != NULL) cout << "\n1\n";
	else cout<<"\n0\n";
	int k = 4;
	Node*nodek = createNode(k);
	InsertAfterQ(link, nodek, nodem);
	printList(link);
	int x;
	removehead(link, x);
	printList(link);
	 removeXs(link, k);
	printList(link);
	OddEvenCheck(link);
	return 0;
}