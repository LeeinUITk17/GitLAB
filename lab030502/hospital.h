#pragma once
#include"Header.h"
class doctor {
private:
	long long idDoctor;
	string fullname;
	/*patient* arrCustom = new patient[customer];*/
	long long idPatient;
	int nCustomer;
	long long Fees;
	long long Salary;
	long long baseSalary;
public:
	void randomInf(doctor& A, int seed);
	void setSalary(doctor& A);
	/*friend void hospital::SetupHospital(hospital& A);*/
	long long getID(doctor A);
	void showOff(doctor A);
	void assignID(doctor& A,int index);
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
	/*friend void hospital::SetupHospital(hospital& A);*/
	long long getID(patient A);
	void showOff(patient A);
	void assignID(patient& A,int index);
};
class hospital {
private:
	doctor* ArrDr = new doctor[member];
	patient* ArrPt = new patient[customer];
public:
	void SetupHospital(hospital& A);
	void highestBalance(doctor[]);
	void searchID(hospital A, long long id);
	void showMode(hospital A);
};