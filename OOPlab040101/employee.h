#pragma once
#include"Header.h"
class employee {
protected:
	long long ID;
	string fullname;
	long long BaseS;
	long long Salary;
public:
	virtual void showOff();
	long long getID();
	void replaceBaseS(long long newBase);
	long long getSalary();
};
class office :public employee {
private:
	int workingDay;
public:
	void randomInf(office& A,int seed);
	void setSalary(office& A);
	void showoff();
};
class factory :public employee {
private:
	int products;
public:
	void randomInf(factory& A, int seed);
	void setSalary(factory& A);
	void showoff();
	int getProduct();
};
class company {
private:
	vector<office> OFemployee;
	vector<factory> FCemployee;
public:
	void setupCompany(company &A);
	void Infmember(company&A);
	void searchID(company A, long long id);
	void updateBaseS(company& A, long long& id,long long &newBase);
	void maxBill(company A);
	void minProduct(company A);
	void Bill10s(company A);
};