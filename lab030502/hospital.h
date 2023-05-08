#pragma once
#include"Header.h"
class doctor {
private:
	long long idDoctor;
	string fullname;
	patient* arrCustom = new patient[customer];
	int nCustomer;
	long long Fees;
	long long Salary;
	long long baseSalary;
public:
	void randomInf(doctor& A, int seed);
	void setSalary(doctor& A);
	friend class patient;
};
class patient {
private:
	long long idPatient;
	string fullname;
	long long idDoctor;
	long long bills;
	int AboutTime;
	long long medicinFee;
public:
	void randomInf(patient& A, int seed);
	void setBills(patient& A);
	friend class doctor;
};
class hospital {
private:
	doctor* ArrDr = new doctor[member];
	patient* ArrPt = new patient[customer];
public:
	void SetupHospital(doctor[], patient[]);
	void highestBalance(doctor[]);
	void searchID(doctor[], int, long long);
	void searchID(patient[], int, long long);
};