#include"Header.h"
#include"node.h"
int main() {
	list link;
	//cau 1: tao danh sach
	/*
	input: list link
	output: create list
	call void createlist(list& l);
	*/
	createlist(link);
	cout << "cau 3: theo du lieu vao cuoi danh sach\n ";
	/*
	input: list link, int seed <i>
	output: create data for link
	call void randomData(list& l,int seed);
    call void addtail(list& l, Node* node);
	call Node* createNode(int initdata);
	*/
	for (int i = 0; i < size; i++) {
		randomData(link, i);
	}
	cout << "\ncau 4: xuat danh sach hien tai\n";
	/*
	input: list link
	output show list 
	call void printList(list l);
	*/
	printList(link);
	int m = 5;
	Node*nodem = createNode(m);
	cout << "\ncau 2: them du lieu vao dau danh sach\n";
	/*
	input: list link, Node*node
	output: add node to list
	call void addhead(list& l, Node* node);
	call Node* createNode(int initdata);
	*/
	addhead(link, nodem);
	printList(link);
	cout << "\ncau 5: tinh do dai danh sach \n";
	/*
	input: list link
	output: length<int>
	call int length(list l);
	*/
	cout << length(link);
	cout << "\n cau 6: tim gia tri co trong danh sach hay khong\n";
	/*
	input: list link, int <parameter need look for>
	output: 1 true || 0 false
	call Node* search(list l, int x);
	*/
	Node* searchNode = search(link, 5);
	if (searchNode != NULL) cout << "\n1\n";
	else cout<<"\n0\n";
	int k = 4;
	Node*nodek = createNode(k);
	cout << "\ncau 7: chen mot gia tri x sau gia tri y trong danh sach\n";
	/*
	input: list link, node's x, node's y
	output: insert x after y
	call void InsertAfterQ(list& l, Node* p, Node* q);
	*/
	InsertAfterQ(link, nodek, nodem);
	printList(link);
	int x;
	removehead(link, x);
	printList(link);
	cout << "\n cau 9: xoa mot phan tu\n";// em su dung 2 cach removehead && removeXs
	/*
	<removeXs>
	input: list link, int x
	output: delete node has data is x
	call int removeXs(list& l, int x);
	*/
	 removeXs(link, k);
	printList(link);
	cout << "\n cau 8: dem so luong gia tri chan, le trong danh sach\n";
	/*
	input: list link
	output: numbers of odd number && numbers of even number
	call void OddEvenCheck(list l);
    call Node* getNode(list l, int index);
	*/
	OddEvenCheck(link);
	return 0;
}