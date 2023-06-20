#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<typeinfo>
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
                long long tempdata = node1s->data;
                long long tempiddata = node1s->indexdata;
                node1s->data = node2s->data;
                node1s->indexdata = node2s->indexdata;
                node2s->data = tempdata;
                node2s->indexdata = tempiddata;
            }
        }
    }
}
class employee {
protected:
    long long ID;
    string fullname;
    long long baseSalary;
    long long Salary;

public:
    employee(long long id = 0, string ten = " ", long long luongcb = 0)
        : ID(id), fullname(ten), baseSalary(luongcb), Salary(0)
    {}

    ~employee() {}

    long long getID() {
        return this->ID;
    }

    string getName() {
        return this->fullname;
    }

    long long getBaseSalary() {
        return this->baseSalary;
    }

    long long getSalary() {
        return this->Salary;
    }
    void changeBaseSalary(long long newBase) {
        this->baseSalary = newBase;
    }
    virtual void setSalary() = 0;

    void randomInf(int seed) {
        srand(seed);
        this->ID = rand() % 1001 + 22521276;
        string ArrName[10] = { "Tai", "Thai", "Tan", "Son", "Thang", "Lam", "Quyen", "Sang", "Thoang", "Quang" };
        string ArrSurname[10] = { "Le", "Nguyen", "Tran", "Ho", "Vo", "Dinh", "Cao", "Ly", "Vuong", "Nhat" };
        int indexArrN = rand() % 10;
        int indexArrSN = rand() % 10;
        this->fullname = ArrSurname[indexArrSN] + " " + ArrName[indexArrN];
        this->baseSalary = 5000000 + (rand() % 10) * 1000000;
    }

    void showoff() {
        cout << "ID: " << this->ID << "\n";
        cout << "FullName: " << this->fullname << "\n";
        cout << "Base Salary: " << this->baseSalary << "\n";
        cout << "Salary: " << this->Salary << "\n";
    }
    virtual void show() = 0;
};

class office : public employee {
private:
    int workingday;

public:
    office(long long id = 0, string ten = " ", long long luongcb = 0, int ngaylamviec = 0)
        : employee(id, ten, luongcb), workingday(ngaylamviec)
    {}

    ~office() {}

    void setSalary() {
        this->Salary = this->baseSalary + this->workingday * 250000;
        if (this->workingday < 15) {
            this->Salary += (this->Salary * 0.3);
        }
    }

    void randomInf(int seed) {
        this->workingday = 10 + rand() % 12;
        employee::randomInf(seed);
        this->setSalary();
    }

    void show() {
        employee::showoff();
        cout << "Working days: " << this->workingday << "\n";
    }
};

class factory : public employee {
private:
    int products;

public:
    factory(long long id = 0, string ten = " ", long long luongcb = 0, int sanpham = 0)
        : employee(id, ten, luongcb), products(sanpham)
    {}

    ~factory() {}

    void setSalary() {
        this->Salary = this->baseSalary + this->products * 175000;
        if (this->baseSalary > 10000000) {
            this->Salary += (this->Salary * 0.1);
        }
        if (this->products < 10) {
            this->Salary += (this->Salary * 0.1);
        }
    }

    void randomInf(int seed) {
        this->products = 5 + rand() % 15;
        employee::randomInf(seed);
        this->setSalary();
    }

    void show() {
        employee::showoff();
        cout << "Products: " << this->products << "\n";
    }
    long long getProduct() {
        return this->products;
    }
};

class company{
private:
    vector<employee*> member;

public:
    ~company() {
        for (int i = 0; i < member.size(); i++) {
            delete member[i];
        }
    }

    void setupCompany() {
        for (int i = 0; i < 10; i++) {
            office* off = new office();
            off->randomInf(i);
            member.push_back(off);
        }

        for (int i = 0; i < 10; i++) {
            factory* fac = new factory();
            fac->randomInf(i);
            member.push_back(fac);
        }
    }

    void showInf() {
        for (int i = 0; i < member.size(); i++) {
            member[i]->showoff();
            cout << "\n";
        }
    }
    employee* searchID(long long id) {
        for (int i = 0; i < member.size(); i++) {
            if (member[i]->getID() == id) {
                return member[i];
            }
        }
        cout << "\n\tNot found..\n";
        return NULL;
    }
    employee* updateBase(long long &newBase) {
        long long id;
        cout << "\n\t enter ID: ";
        cin >> id;
        cout << "\n\t enter new Base Salary: ";
        cin >> newBase;
        for (int i = 0; i < member.size(); i++) {
            if (member[i]->getID() == id) {
                member[i]->changeBaseSalary(newBase);
                member[i]->setSalary();
                return member[i];
            }
        }
        cout << "\n\t error update fail..\n";
        return NULL;
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
    factory* lowestValue() {
        vector<factory*> fcmember;
        for (int i = 0; i < member.size(); i++) {
            factory* fac = dynamic_cast<factory*>(member[i]);
            if (fac != NULL) {
                fcmember.push_back(fac);
            }
        }
        int min = 0;
        for (int i = 0; i < fcmember.size(); i++) {
            if (fcmember[i]->getProduct() < fcmember[min]->getProduct()) {
                min = i;
            }
        }
        return fcmember[min];
    }
    void bill10sMax() {
        list link;
        createlist(link);
        for(int i=0;i<member.size();i++){
            Node* node = createNode(member[i]->getSalary(), member[i]->getID());
            addtail(link, node);
        }
        sortlist(link);
        Node* rp = link.head;
        for (int i = 0; i < 10; i++) {
            cout << "\n";
            searchID(rp->indexdata)->show();
            cout << "\n";
            rp = rp->next;
        }
    }
};

int main() {
    srand(time(0)); // Seed the random number generator

    company UIT;
    UIT.setupCompany();
    UIT.showInf();
    long long id;
    cout << "\n\t enter ID: ";
    cin >> id;
    employee *equal1s = UIT.searchID(id);
    if (equal1s != NULL) {
        equal1s->show();
    }
    long long newBase;
    employee* equal2s = UIT.updateBase(newBase);
    if (equal2s != NULL) {
        equal2s->show();
    }
    UIT.maxBill()->show();
    UIT.lowestValue()->show();
    UIT.bill10sMax();
    return 0;
}
