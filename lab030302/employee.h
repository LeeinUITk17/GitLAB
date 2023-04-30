#pragma once
#include"Header.h"
//class employee {
//private:
//	long long ID;
//	string fullname;
//	long long baseSalary;
//	long long Salary;
//public:
//	/*employee(long long id,string ten,long long luongCB,long long luong)
//		:ID(id),fullname(ten),baseSalary(luongCB),Salary(luong)
//	{}*/
//	void updateBaseSalary(employee& A, long long Base);
//	friend class company;
//};
class office {
private:
	long long ID;
		string fullname;
		long long baseSalary;
		long long Salary;
	int workingday;
public:
	//office(long long id, string ten, long long luongCB, long long luong,int ngaylamviec)
	//	:employee(id,ten,luongCB,luong),workingday(ngaylamviec)
	//{}
	void setSalary(office& A);
	void randomInf(office& A, int seed);
	void bonus(office& A);
	void showoff(office A);
	//void updateBaseSalary(employee& A, long long);
	friend class company;
};
class factory  {
private:
	long long ID;
	string fullname;
	long long baseSalary;
	long long Salary;
	int products;
public:
	/*factory(long long id, string ten, long long luongCB, long long luong,int sp)
		:employee(id,ten,luongCB,luong),products(sp)
	{}*/
	void setSalary(factory& A);
	void randomInf(factory& A, int seed);
	void bonus(factory& A);
	void showoff(factory A);
	//void updateBaseSalary(employee& A, long long);
	friend class company;
};
class company{
private:
	office* memberOf = new office[resources];
	factory* memberFc = new factory[resources];
public:
	void setupCompany(company& A);
	void InfEmployee(company);
	void searchID(company, long long id);
	void updateSalary(company& A, long long id, long long Bsalary);
	void maxBill(company A);
	void minProduct(company A);
	void selectionSort(company& A);
	void find10sBill(company A);
};