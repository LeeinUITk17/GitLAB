#include"employee.h"
void office::bonus(office& A) {
	if (A.Salary > 10000000) {
		A.Salary += (A.Salary * 0.1);
	}
}
void office::setSalary(office& A) {
	A.Salary = A.baseSalary + A.workingday * 250000;
	A.bonus(A);
}
void office::randomInf(office& A, int seed) {
	srand(seed);
	long long rID = 22521200 + rand() % 1001;
    string ArrName[10]= { "Tai","Thai","Tan","Son","Thang","Lam","Quyen","Sang","Thoang","Quang" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrName = rand() % 10;
	int indexArrSurname = rand() % 10;
	A.fullname = ArrSurname[indexArrSurname] + " " + ArrName[indexArrName];
	A.baseSalary = (rand() % 15) * 1000000 + 2500000;
	//A.product = 100 + rand() % 100;
	A.workingday = 15 + rand() % 15;
	A.setSalary(A);
}
void office::showoff(office A) {
	cout << "\nID: " << A.ID;
	cout << "\nfullname: " << A.fullname;
	cout << "\nBase salary: " << A.baseSalary;
	cout << "\nWorking day: " << A.workingday;
	cout << "\nSalary: " << A.Salary;
}
void factory::bonus(factory& A) {
	if (A.Salary > 10000000) {
		A.Salary += (A.Salary * 0.1);
	}
}
void factory::setSalary(factory& A) {
	A.Salary = A.baseSalary + A.products * 175000;
	A.bonus(A);
}
void factory::randomInf(factory& A, int seed) {
	srand(seed);
	long long rID = 22522200 + rand() % 1001;
	string ArrName[10] = { "Tai","Thai","Tan","Son","Thang","Lam","Quyen","Sang","Thoang","Quang" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrName = rand() % 10;
	int indexArrSurname = rand() % 10;
	A.fullname = ArrSurname[indexArrSurname] + " " + ArrName[indexArrName];
	A.baseSalary = (rand() % 15) * 1000000 + 2500000;
	//A.product = 100 + rand() % 100;
	A.products = 100+rand()%300;
	A.setSalary(A);
}
void factory::showoff(factory A) {
	cout << "\nID: " << A.ID;
	cout << "\nfullname: " << A.fullname;
	cout << "\nBase salary: " << A.baseSalary;
	cout << "\nProducts: " << A.products;
	cout << "\nSalary: " << A.Salary;
}
void swapPof(office& A, office& B) {
	office temp = A;
	A = B;
	B = temp;
}
void swapPfc(factory& A, factory& B) {
	factory temp = A;
	A = B;
	B = temp;
}
void company::selectionSort(company& A) {
	int min;
	for (int i = 0; i < resources; i++) {
		min = i;
		for (int j = i + 1; j < resources; j++) {
			if (memberOf[j].Salary < memberOf[min].Salary) min = j;
		}
		swapPof(memberOf[i], memberOf[min]);
	}
	for (int i = 0; i < resources; i++) {
		min = i;
		for (int j = i + 1; j < resources; j++) {
			if (memberFc[j].Salary < memberFc[min].Salary) min = j;
		}
		swapPfc(memberFc[i], memberFc[min]);
	}
}
void company::find10sBill(company A) {
	A.selectionSort(A);
	for (int i = resources - 5; i < resources; i++) {
		memberFc[i].showoff(memberFc[i]);
	}
	for (int i = resources - 5; i < resources; i++) {
		memberOf[i].showoff(memberOf[i]);
	}
}
void company::setupCompany(company& A) {
	//int n = resources / 2;
	for (int i = 0; i < resources; i++) {
		memberOf[i].randomInf(memberOf[i], i);
	}
	for (int i = 0; i < resources; i++) {
		memberFc[i].randomInf(memberFc[i], i);
	}
}
void company::searchID(company A, long long id) {
	for (int i = 0; i < resources; i++) {
		if (memberFc[i].ID == id) {
			memberFc[i].showoff(memberFc[i]);
			break;
		}
		else if (memberOf[i].ID == id) {
			memberOf[i].showoff(memberOf[i]);
			break;
		}
	}
}
void company::updateSalary(company& A, long long id, long long Bsalary) {
	for (int i = 0; i < resources; i++) {
		if (memberFc[i].ID == id) {
			memberFc[i].baseSalary=Bsalary;
			memberFc[i].setSalary(memberFc[i]);
			memberFc[i].showoff(memberFc[i]);
			break;
		}
		else if (memberOf[i].ID == id) {
			memberOf[i].baseSalary = Bsalary;
			memberOf[i].setSalary(memberOf[i]);
			memberOf[i].showoff(memberOf[i]);
			break;
		}
	}
}
void company::maxBill(company A) {
	//call after called find10sBill(...)
	int n = resources - 1;
	if (memberFc[n].Salary < memberOf[n].Salary) {
		memberOf[n].showoff(memberOf[n]);
	}
	else memberFc[n].showoff(memberFc[n]);
}
void company::minProduct(company A) {
	int min = 0;
	for (int i = 0; i < resources; i++) {
		if (memberFc[min].products < memberFc[i].products) min = i;
	}
	memberFc[min].showoff(memberFc[min]);
}
void company::InfEmployee(company A) {
	for (int i = 0; i < resources; i++) {
		memberFc[i].showoff(memberFc[i]);
		memberOf[i].showoff(memberOf[i]);
	}
}
