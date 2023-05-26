#include"employee.h"
long long employee::getID() {
	return this->ID;
}
long long employee::getSalary() {
	return this->Salary;
}
void employee::replaceBaseS(long long newBase) {
	this->BaseS = newBase;
}
void employee::showOff() {
	cout << "\nID : " << this->ID;
	cout << "\nFullName : " << this->fullname;
	cout << "\nBase Salary : " << this->BaseS;
	cout << "\nSalary : " << this->Salary ;
}
void office::setSalary(office& A) {
	A.Salary = A.BaseS + A.workingDay * 250000;
	if (A.workingDay < 15) {
		A.Salary += ((A.Salary *20)/100);
	}
}
void office::randomInf(office& A, int seed) {
	srand(seed);
	A.ID = rand() % 1001 + 22521276;
	string ArrName[10] = { "Tai","Thai","Tan","Son","Thang","Lam","Quyen","Sang","Thoang","Quang" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrN = rand() % 10;
	int indexArrSN = rand() % 10;
	A.fullname = ArrSurname[indexArrSN] + " " + ArrName[indexArrN];
	A.BaseS = 5000000+(rand()%10)*1000000;
	A.workingDay = 10 + rand() % 12;
	A.setSalary(A);
}
void office::showoff() {
	this->showOff();
	cout << "\nWorking Days : " << this->workingDay << "\n";
}
void factory::setSalary(factory& A) {
	A.Salary = A.BaseS + A.products * 175000;
	if (A.products < 10) A.Salary += ((A.Salary * 30)/100);
	if (A.Salary > 10000000) A.Salary += ((A.Salary * 10)/100);
}
void factory::randomInf(factory& A, int seed) {
	srand(seed);
	A.ID = rand() % 1001 + 22525276;
	string ArrName[10] = { "Tai","Thai","Tan","Son","Thang","Lam","Quyen","Sang","Thoang","Quang" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrN = rand() % 10;
	int indexArrSN = rand() % 10;
	A.fullname = ArrSurname[indexArrSN] + " " + ArrName[indexArrN];
	A.BaseS = 5000000 + (rand() % 10) * 1000000;
	A.products = 5 + rand() % 10;
	A.setSalary(A);
}
void factory::showoff() {
	this->showOff();
	cout << "\nProducts : " << this->products << "\n";
}
void company::setupCompany(company&A) {
	for (int i = 0; i < member;i++) {
		office C;
		C.randomInf(C,i);
		A.OFemployee.push_back(C);
		factory B;
		B.randomInf(B, i);
		A.FCemployee.push_back(B);
	}
	cout <<"\n" << A.OFemployee.size() << " <> " << A.FCemployee.size() << "\n";
}
void company::Infmember(company &A) {
	cout << "\n enter 1 show Inf office employees..";
	cout << "\n enter 2 show Inf factory employees..";
	cout << "\n enter 3 show Inf a both employees..";
	cout << "\n\tselect mode. !\n";
	int mode;
	cin >> mode;
	switch (mode)
	{
	case 1:
	{
		for (int i = 0; i < member; i++) {
			A.OFemployee[i].showoff();
		}
		break;
	}
	case 2: {
		for (int i = 0; i < member; i++) {
			A.FCemployee[i].showoff();
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < member; i++) {
			cout << "\n >>factory employee:";
			A.FCemployee[i].showoff();
			cout << "\n >> office employee:";
			A.OFemployee[i].showoff();
		}
		break;
	}
	default:
		break;
	}
}
void company::searchID(company A, long long id) {
	int i = 0;
	while (i < member) {
		if (A.OFemployee[i].getID() == id) {
			cout << "\nHe is : ";
			A.OFemployee[i].showOff();
			break;
		}
		if (A.FCemployee[i].getID() == id) {
			cout << "\nHe is : ";
			A.FCemployee[i].showOff();
			break;
		}
		i++;
	}
}
void company::updateBaseS(company& A, long long& id,long long &newBase) {
	cout << "\nenter New Base Salary: ";
	cin >> newBase;
	cout << endl;
	cout << "enter ID : ";
	cin >> id;
	int i = 0;
	while (i < member) {
		if (A.OFemployee[i].getID() == id) {
			A.OFemployee[i].replaceBaseS(newBase);
			A.OFemployee[i].setSalary(A.OFemployee[i]);
			break;
		}
		if (A.FCemployee[i].getID() == id) {
			A.FCemployee[i].replaceBaseS(newBase);
			A.FCemployee[i].setSalary(A.FCemployee[i]);
			break;
		}
		i++;
	}
}
void company::maxBill(company A) {
	long long maxof = A.OFemployee[0].getSalary();
	long long maxfc = A.FCemployee[0].getSalary();
	long long idmaxof, idmaxfc;
	for (int i = 0; i < A.OFemployee.size(); i++) {
		if (A.OFemployee[i].getSalary() > maxof) {
			maxof = A.OFemployee[i].getSalary();
			idmaxof = A.OFemployee[i].getID();
		}
	}
	for (int j = 0; j < A.FCemployee.size(); j++) {
		if (A.FCemployee[j].getSalary() > maxfc) {
			maxfc = A.FCemployee[j].getSalary();
			idmaxfc = A.FCemployee[j].getID();
		}
	}
	if (maxof > maxfc) {
		A.searchID(A, idmaxof);
	}
	else A.searchID(A, idmaxfc);
}
int factory::getProduct() {
	return this->products;
}
void company::minProduct(company A) {
	int min = A.FCemployee[0].getProduct();
	int idminfc;
	for (int i = 0; i < A.FCemployee.size(); i++) {
		if (A.FCemployee[i].getProduct() < min) {
			min = A.FCemployee[i].getProduct();
			idminfc = A.FCemployee[i].getID();
		}
	}
	A.searchID(A, idminfc);
}
struct Node {
	long long SalBill;
	long long idData;
		Node* next;
};
struct list {
	Node* head;
	Node* tail;
};
Node* createNode(long long billda, long long idda) {
	Node* node = new Node;
	node->SalBill = billda;
	node->idData = idda;
	node->next = NULL;
	return node;
}
void createlist(list& l) {
	l.head = NULL;
	l.tail = NULL;
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
Node* getNode(list l, int index) {
	Node* node = l.head;
	int i = 0;
	while (node != NULL && i != index) {
		i++;
		node = node->next;
	}
	if (node != NULL && i == index) {
		return node;
	}
	return NULL;
}
void swap(long long& a, long long& b) {
	int temp = a;
	a = b;
	b = temp;
}
void selectionSort(vector<long long> &Salry) {
	int max;
	for (int i = 0; i < Salry.size(); i++) {
		max = i;
		for (int j = i + 1; j < Salry.size(); j++) {
			if (Salry[j] > Salry[max]) max = j;
		}
		swap(Salry[i], Salry[max]);
	}
}
long long getidda(list l,long long billda) {
	Node* node = l.head;
	while (node != NULL && node->SalBill != billda) {
		node = node->next;
	}
	return node->idData;
}
void printlist(list l) {
	if (l.head != NULL) {
		Node* node = l.head;
		while (node != NULL) {
			cout << node->SalBill << "<>"<<node->idData<<" ";
			node = node->next;
		}
	}
}
void company::Bill10s(company A) {
	list linkBill;
	createlist(linkBill);
	for (int i = 0; i < A.OFemployee.size(); i++) {
		Node* node = createNode(A.OFemployee[i].getSalary(), A.OFemployee[i].getID());
		addtail(linkBill, node);
	}
	for (int i = 0; i < A.FCemployee.size(); i++) {
		Node* node = createNode(A.FCemployee[i].getSalary(), A.FCemployee[i].getID());
		addtail(linkBill, node);
	}
	vector<long long> Salry;
	Node* node = linkBill.head;
	while (node != NULL) {
		Salry.push_back(node->SalBill);
		node = node->next;
	}
	selectionSort(Salry);
	//printlist(linkBill);
	for (int i = 0; i < 10; i++) {
		A.searchID(A, getidda(linkBill, Salry[i]));
	}
}