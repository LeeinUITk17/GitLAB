#include<iostream>
#include<cstdlib>
#include<typeinfo>
#include<vector>
using namespace std;
struct Node {
	long long data;
	long long indexdata;
	Node* next;
};
struct list {
	Node* head;
	Node* tail;
};
Node* createNode(long long initdata, long long iddata) {
	Node* node = new Node;
	node->data = initdata;
	node->indexdata = iddata;
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
void sortlist(list& l) {
	for (Node* node1s = l.head; node1s != NULL; node1s = node1s->next) {
		for (Node* node2s = node1s->next; node2s != NULL; node2s = node2s->next) {
			if (node2s->data > node1s->data) {
				long long temp = node1s->data;
				long long tempid = node1s->indexdata;
				node1s->data = node2s->data;
				node1s->indexdata = node2s->indexdata;
				node2s->data = temp;
				node2s->indexdata = tempid;
			}
		}
	}
}
void printlist(list l) {
	Node* node = l.head;
	while (node != NULL) {
		cout << node->indexdata << " ";
		node = node->next;
	}
}
Node* searchNode(list l, int index) {
	Node* node = l.head;
	int i = 0;
	while (node != NULL&& i!=index) {
		node = node->next;
		i++;
	}
	if (node != NULL) return node;
	else return NULL;
}
class employee {
protected:
	long long ID;
	string fullname;
	long long baseSalary;
	long long Salary;
public:
	employee(long long id = 0, string ten = " ", long long luongcb = 0) 
		:ID(id), fullname(ten), baseSalary(luongcb), Salary(0)
	{}
	~employee() {}
	long long getID() {
		return this->ID;
	}
	string getName() {
		return this->fullname;
	}
	long long getbaseSalary() {
		return this->baseSalary;
	}
	long long getSalary() {
		return this->Salary;
	}
	void changeBaseSalary(long long newBase) {
		this->baseSalary = newBase;
	}
	virtual void setSalary() = 0;
	void showoff() {
		cout << "\nID: " << this->ID << "\n";
		cout << "Full name: " << this->fullname << "\n";
		cout << "Base Salary: " << this->baseSalary << "\n";
		cout << "Salary: " << this->Salary << "\n";
	}
	virtual void show() = 0;
};
class office :public employee {
private:
	int workinghours;
public:
	office(long long id = 0, string ten = " ", long long luongcb = 0, int ngaylamviec = 0)
		: employee(id, ten, luongcb), workinghours(ngaylamviec)
	{}

	~office() {}
	void setSalary() {
		this->Salary = this->baseSalary + this->workinghours * 220000;
		if (this->workinghours > 100) {
			this->Salary += 5000000;
		}
	}
	void show() {
		employee::showoff();
		cout << "Working hours: " << this->workinghours << "\n";
	}
};
class factory : public employee {
private:
	int products;
public:
	factory(long long id=0,string ten=" ",long long luongcb=0,int sp=0)
		:employee(id,ten,luongcb),products(sp)
	{}

	~factory() {}
	void setSalary() {
		this->Salary = this->baseSalary + this->products * 175000;
		if (this->products > 150) {
			this->Salary += (this->Salary) * 0.2;
		}
	}
	void show() {
		employee::showoff();
		cout << "Products: " << this->products << "\n";
	}
};
class manager : public employee {
private:
	float rankConst;
	long long bonus;
public:
	manager(long long id=0,string ten=" ",long long luongcb=0,float hesochucvu=0.0,long long thuong=0)
		:employee(id,ten,luongcb),rankConst(hesochucvu),bonus(thuong)
	{}

	~manager() {}
	void setSalary() {
		this->Salary = this->baseSalary * this->rankConst + this->bonus;
	}
	void show() {
		employee::showoff();
		cout << "Rank const: " << this->rankConst << "\n";
		cout << "Bonus: " << this->bonus << "\n";
	}
};
class company {
private:
	vector<employee*> member;
public:
	~company() {
		for (int i = 0; i < member.size(); i++) {
			delete member[i];
		}
	}
	void setupcompany() {
		office* arrof[3] = {
              new office(101,"Nguyen A",4500000,200),
			  new office(102,"Nguyen B",5600000,100),
			  new office(103,"Nguyen C",8900000,90)
		};
		for (int i = 0; i < 3; i++) {
			arrof[i]->setSalary();
			member.push_back(arrof[i]);
		}
		factory* arrfc[3] = {
			new factory(201,"Nguyen D",7800000,250),
			new factory(202,"Nguyen E",4500000,110),
			new factory(203,"Nguyen F",6600000,360)
		};
		for (int i = 0; i < 3; i++) {
			arrfc[i]->setSalary();
			member.push_back(arrfc[i]);
		}
		manager* arrmn[2] = {
			new manager(301,"Nguyen G",8500000,1.3,19500000),
			new manager(302,"Nguyen h",7600000,1.2,18600000)
		};
		for (int i = 0; i < 2; i++) {
			arrmn[i]->setSalary();
			member.push_back(arrmn[i]);
		}
	}
	void showInf() {
		for (int i = 0; i < member.size(); i++) {
			cout << "\n";
			member[i]->show();
			cout << "\n";
		}
	}
	employee* searchID(long long id) {
		for (int i = 0; i < member.size(); i++) {
			if (member[i]->getID() == id) {
				return member[i];
			}
		}
		return NULL;
	}
	long long AverageBill() {
		long long sum=0;
		for (int i = 0; i < member.size(); i++) {
			sum += member[i]->getSalary();
		}
		long long equal = (long long)sum / member.size();
		return equal;
	}
	employee* updateBase(long long& newBase) {
		long long id;
		cout << "\n\tenter ID: ";
		cin >> id;
		cout << "\n\tenter newBase: ";
		cin >> newBase;
		for (int i = 0; i < member.size(); i++) {
			if (member[i]->getID() == id) {
				member[i]->changeBaseSalary(newBase);
				member[i]->setSalary();
				return member[i];
			}
		}
		cout << "\nnot found..\n";
		return NULL;
	}
	employee* maxBase() {
		int max = 0;
		for (int i = 0; i < member.size(); i++) {
			if (member[i]->getbaseSalary() > member[max]->getbaseSalary()) {
				max = i;
			}
		}
		return member[max];
	}
	employee* maxBill() {
		int max = 0;
		for (int i = 0; i < member.size(); i++) {
			if (member[i]->getSalary() > member[max]->getSalary()) {
				max = i;
			}
		}
		return member[max];
	}
	void minBaseArr() {
		list link;
		createlist(link);
		for (int i = 0; i < member.size(); i++) {
			Node* node = createNode(member[i]->getbaseSalary(), member[i]->getID());
			addtail(link, node);
		}
		sortlist(link);
		//printlist(link);
		Node* np = searchNode(link, member.size() - 3);
		while (np != NULL) {
			searchID(np->indexdata)->show();
			np = np->next;
		}
	}
};
int main() {
	company UIT;
	UIT.setupcompany();
	UIT.showInf();
	cout << "\n\t>>C4<<\n";
	long long id;
	cout << "\n\tenter ID: ";
	cin >> id;
	UIT.searchID(id)->show();
	cout << "\n\t>>C5<<\n";
	cout << UIT.AverageBill();
	cout << "\n\t>>C6<<\n";
	long long newBase;
	employee* rp = UIT.updateBase(newBase);
	if (rp != NULL) {
		rp->show();
	}
	cout << "\n\t>>C7<<\n";
	UIT.maxBase()->show();
	cout << "\n\t>>C8<<\n";
	UIT.maxBill()->show();
	UIT.minBaseArr();
	return 0;
}