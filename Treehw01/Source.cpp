#include"Header.h"
#include"Tree.h"
int main() {
	list link;
	tree myTree;
	createTree(myTree);
	createList(link);
	Node* node;
	int member,value;
	cout << "enter numbers of Tree: ";
	cin >> member;
	for (int i = 0; i < member; i++) {
		cin >> value;
		node = createNode(value);
		addtail(link, node);
	}
	input(myTree, link);
	int mode;
	cout << "\n select mode:... \n";
	cout << "enter:\n 1: Cau 1 print\n 2: Cau 2 search\n 3: Cau 3 delete\n 4: Cau 4 sum <Node>\n 5: Cau 5 roots have 2 branch\n 6: Cau 6 roots have only branch";
	cout<<"\n 7: Cau 7 roots have only branch <right>\n 8: Cau 8 numbers of leaf\n 9: Cau 9 height of tree\n";
	cin >> mode;
	switch (mode)
	{
	case 1:
	{
		cout << "\n=======cau 1=====\n";
			cout << "enter: 1 LNR\t2 LRN\t3 NLR\t4 NRL\t5 RNL\t6 RLN \n";
			int modeC1;
			cin >> modeC1;
			switch (modeC1)
			{
			case 1:
			{
				LNR(myTree);
				break;
			}
			case 2:
			{
				LRN(myTree);
				break;
			}
			case 3:
			{
				NLR(myTree);
				break;
			}
			case 4:
			{
				NRL(myTree);
				break;
			}
			case 5:
			{
				RNL(myTree);
				break;
			}
			case 6: {
				RLN(myTree);
				break;
			}
			default:
				break;
			}
			break;
		}
	case 2:
	{
		cout << "\n=======cau 2=====\n";
		int count;
		cout << "\nenter number wanna search: ";
		cin >> count;
		nonNode* searchNum = search(myTree, count);
		if (searchNum == NULL) cout << "\nKhong tim Duoc..";
		else cout << "\nTim Duoc " << count << " trong myTree !";
		break;
	}
	case 3:
	{
		cout << "\n=======cau 3=====\n";
		int key;
		cout << "\nenter number wanna delete: ";
		cin >> key;
		remove(myTree, key);
		nonNode* searchNum = search(myTree, key);
		if (searchNum == NULL) cout << "\nxoa thanh cong";
		else cout << "\nxoa that bai ";
		break;
	}
	case 4: {
		cout << "\n=======cau 4=====\n";
		cout << sum(myTree);
		break;
	}
	case 5: {
		int count = 0;
		cout << "\n=======cau 5=====\n";
		cout << branch2s(myTree,count);
		break;
	}
	case 6: {
		int count = 0;
		cout << "\n=======cau 6=====\n";
		cout << branch1s(myTree, count);
		break;
	}
	case 7: {
		int count = 0;
		cout << "\n=======cau 7=====\n";
		cout << branch1sRight(myTree, count);
		break;
	}
	case 8: {
		int count = 0;
		cout << "\n=======cau 8=====\n";
		cout << leaf(myTree, count);
		break;
	}
	case 9: {
		cout << "\n=======cau 9=====\n";
		cout << tree_height(myTree);
	}
	default:
		break;
	}
	return 0;
}