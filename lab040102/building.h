#pragma once
#include"Header.h"
class employee {
public:
	enum Type{NV,NVVP,NVSX};
	virtual void showOff();
	void randomInf(employee& A,int seed);
protected:
	long long ID;
	string fullname;
	long long baseS;
	long long Salary;
	Type type = NV;
};
class office :public employee {
private:
	int workingDay;
	Type type = NVVP;
public:
	void showOff();
	void setSalary(office& A);
	void randomInf(office &A,int seed);
};
class factory :public employee {
private:
	int products;
	Type type = NVSX;
public:
	void showOff();
	void setSalary(factory& A);
	void randomInf(factory &A,int seed);
};
class company {
private:
	employee* ArrMember[member];
public:
	void setupCompany(company& A);
};