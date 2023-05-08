#include"hospital.h"
void doctor::randomInf(doctor& A, int seed) {
	srand(seed);
	long long idrandom = rand() % 10001 + 22521276;
	A.idDoctor = idrandom;
	string ArrName[10] = { "Tai","Thai","Tan","Son","Thang","Lam","Quyen","Sang","Thoang","Quang" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrN = rand() % 10;
	int indexArrSN = rand() % 10;
	A.fullname = ArrSurname[indexArrSN] + " " + ArrName[indexArrN];
	A.Fees = 500000 + (rand() % 10) * 1000000;
	A.baseSalary = 8000000 + (rand() % 10) * 1000000;
}
void doctor::setSalary(doctor& A) {
	
}
void patient::randomInf(patient& A, int seed) {
	srand(seed);
	long long idrandom = rand() % 1000000 + 12521276;
	A.idPatient = idrandom;
	string ArrName[10] = { "Thuong","Thu","Tam","Suong","Thuy","Lam","Quyen","Sang","Thi","Quynh" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrN = rand() % 10;
	int indexArrSN = rand() % 10;
	A.fullname = ArrSurname[indexArrSN] + " " + ArrName[indexArrN];
	A.AboutTime = 1 + rand() % 30;
	A.medicinFee = 100000 + (rand() % 20) * 100000;
}
void patient::setBills(patient& A) {

}
void hospital::SetupHospital(doctor[], patient[]) {
	for (int i = 0; i < member; i++) {
		ArrDr[i].randomInf(ArrDr[i], i);
	}
	for (int i = 0; i < customer; i++) {
		ArrPt[i].randomInf(ArrPt[i], i);
	}
}
void highestBalance(doctor[]);
void searchID(doctor[], int, long long);
void searchID(patient[], int, long long);