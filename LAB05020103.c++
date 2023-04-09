#include<iostream>
#include<time.h>
#define resources 15
#define Maxresources 200
using namespace std;
class employee {
private:
	long long ID;
	string fullname;
	long long baseSalary;
	int product;
	long long Salary;
public:
	void randomEmployee(employee& A, int);
	void setSalary(employee& A);
	void bonus(employee& A);
	void showOff(employee);
	void updateBaseSalary(employee& A, long long);
	friend class company;
};
void employee::updateBaseSalary(employee& A, long long base) {
	A.baseSalary = base;
}
void employee::showOff(employee A) {
	cout << "\nID: " << A.ID << "\n";
	cout << "FullName: " << A.fullname << "\n";
	cout << "Base Salary: " << A.baseSalary << "\n";
	cout << "Products: " << A.product << "\n";
	cout << "Salary: " << A.Salary << "\n";
}
void employee::bonus(employee& A) {
	if (A.Salary > 10000000) {
		A.Salary += (A.Salary * 0.1);
	}
}
void employee::setSalary(employee& A) {
	A.Salary = A.baseSalary + (A.product) * 175000;
	A.bonus(A);
}
void employee::randomEmployee(employee& A, int seed) {
	srand(seed);
	A.ID = 22521200 + rand() % 1000;
	string ArrName[10] = { "Tai","Thai","Tan","Son","Thang","Lam","Quyen","Sang","Thoang","Quang" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrName = rand() % 10;
	int indexArrSurname = rand() % 10;
	A.fullname = ArrSurname[indexArrSurname] + " " + ArrName[indexArrName];
	A.baseSalary = (rand() % 15) * 1000000+2500000;
	A.product = 100 + rand() % 100;
	A.setSalary(A);
}
class company {
private:
	employee* member = new employee[resources];
public:
	void SetUpCompany(company& A);
	void InfEmployee(company);
	employee searchID(company, long long IDs);
	void updateSalary(company& A, long long, long long);
	void maxBill(company A);
	void minProduct(company A);
	void find10sBill(company &A);
};
void company::SetUpCompany(company& A) {
	for (int i = 0; i < resources; i++) {
		member[i].randomEmployee(member[i], i);
	}
}
void swapPos(employee &A,employee &B) {
	employee temp = A;
	A = B;
	B = temp;
}
void company::find10sBill(company &A) {
	int min;
	for (int i = 0; i < resources; i++) {
		min = i;
		for (int j = 1 + 1; j < resources; j++) {
			if (member[j].Salary < member[min].Salary) min = j;
		}
		swapPos(member[i], member[min]);
	}
	for (int i = resources-10; i < resources; i++) {
		member[i].showOff(member[i]);
	}
}
void company::maxBill(company A) {
	employee max = member[0];
	for (int i = 0; i < resources; i++) {
		if (member[i].Salary > max.Salary) max = member[i];
	}
	max.showOff(max);
}
void company::minProduct(company A) {
	employee min = member[0];
	for (int i = 0; i < resources; i++) {
		if (member[i].product < min.product) min = member[i];
	}
	min.showOff(min);
}
void company::InfEmployee(company A) {
	for (int i = 0; i < resources; i++) {
		member[i].showOff(member[i]);
	}
}
employee company::searchID(company A, long long IDs) {
	for (int i = 0; i < resources; i++) {
		if (member[i].ID == IDs) //member[i].showOff(member[i]);
			return member[i];
	}
}
void company::updateSalary(company& A, long long ids, long long Salarys) {
	for (int i = 0; i < resources; i++) {
		if (member[i].ID == ids) {
			member[i].baseSalary = Salarys;
			member[i].setSalary(member[i]);
		}
	}
}
int main() {
	company UIT;
	//Cau 1: tao du lieu nhan vien
	UIT.SetUpCompany(UIT);
	/*
	input: company UIT
	output: //khoi tao du lieu nhan vien <company UIT>
	*/
	cout << ">> Cau 2: xuat cac nhan vien + Cau 3 : tinh luong nhan vien\n";
	UIT.InfEmployee(UIT);
	/*
	input: company UIT
	output: xuat thong tin nhan vien <company UIT> + tinh luong va save vao attribute Salary
	*/
	cout << ">> Cau 4: Tim kiem nhan vien theo ID\n";
	long long id;
	cout << "find ID: search...:";
	cin >> id;
	cout << "\n";
	UIT.searchID(UIT, id).showOff(UIT.searchID(UIT, id));
	/*
	input: long long id, company UIT
	output: xuat thong tien nhan vien <company UIT> co ID==id
	*/
	cout << ">> Cau 5: Update attibute baseSalary cho nhan vien\n";
	UIT.updateSalary(UIT, id, 5000000);
	/*
	input: long long id,company UIT
	5000000 //gia tri base salary can update 
	output: nhan vien <company UIT> co ID=id update baseSalary=5000000
	xuat thong tin nhan vien <company UIT> co ID=id sau update
	*/
	UIT.searchID(UIT, id).showOff(UIT.searchID(UIT, id));
	cout << ">> Cau 6: tim nhan vien co luong cao nhat\n";
	/*
	input: company UIT
	ouput: xuat thong tin nhan vien <company UIT> co attribute Salary max
	*/
	UIT.maxBill(UIT);
	cout << ">> Cau 7: tim nhan vien co so san pham ban duoc thap nhat\n";
	/*
	input: company UIT
	output: xuat thong tin nhan vien <company UIT> co attribute Product min
	*/
	UIT.minProduct(UIT);
	cout << ">> Cau 8: tim 10 nhan vien co luong cao nhat\n";
	/*
	input: company UIT
	output: xuat thong tin 10 nhan vien <company UIT> co attribute Salary cao nhat
	*/
	UIT.find10sBill(UIT);
	return 0;
}