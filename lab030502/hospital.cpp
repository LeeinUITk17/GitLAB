#include"hospital.h"
long long* arrdr = new long long[member];
long long* arrpt = new long long[customer];
int ndr = 0, npt = 0;
void doctor::setSalary(doctor& A) {
	A.Salary = A.baseSalary + A.Fees;
}
void doctor::randomInf(doctor& A, int seed) {
	srand(seed);
	long long idrandom = rand() % 10001 + 22521276;
	A.idDoctor = idrandom;
	/*A.idPatient = arrpt[seed];*/
	string ArrName[10] = { "Tai","Thai","Tan","Son","Thang","Lam","Quyen","Sang","Thoang","Quang" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrN = rand() % 10;
	int indexArrSN = rand() % 10;
	A.fullname = ArrSurname[indexArrSN] + " " + ArrName[indexArrN];
	A.Fees = 500000 + (rand() % 10) * 1000000;
	A.baseSalary = 8000000 + (rand() % 10) * 1000000;
	A.setSalary(A);
}
long long doctor::getID(doctor A) {
	return A.idDoctor;
}
long long doctor::drIDpt(doctor A) {
	return A.idPatient;
}
void doctor::assignID(doctor& A, int index) {
	A.idPatient = arrpt[index];
}
void doctor::showOff(doctor A) {
	cout << "\n--Doctor--\n";
	cout << "ID: " << A.idDoctor << "\n";
	cout << "Fullname: " << A.fullname << "\n";
	cout << "Fees: " << A.Fees << "\n";
	cout << "Base salary: " << A.baseSalary << "\n";
	cout << "Salary: " << A.Salary << "\n";
	cout << "ID patient: " << A.idPatient << "\n";
}
void patient::setBills(patient& A) {
	A.bills = A.AboutTime * feeDay + A.medicinFee;
}
void patient::randomInf(patient& A, int seed) {
	srand(seed);
	long long idrandom = rand() % 1000000 + 12521276;
	A.idPatient = idrandom;
	/*A.idDoctor = arrdr[seed];*/
	string ArrName[10] = { "Thuong","Thu","Tam","Suong","Thuy","Lam","Quyen","Sang","Thi","Quynh" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrN = rand() % 10;
	int indexArrSN = rand() % 10;
	A.fullname = ArrSurname[indexArrSN] + " " + ArrName[indexArrN];
	A.AboutTime = 1 + rand() % 30;
	A.medicinFee = 100000 + (rand() % 20) * 100000;
	A.setBills(A);
}
long long patient::getID(patient A) {
	return A.idPatient;
}
long long patient::ptIDdr(patient A) {
	return A.idDoctor;
}
void patient::assignID(patient& A, int index) {
	A.idDoctor = arrdr[index];
}
void patient::showOff(patient A) {
	cout << "\n--Patient--\n";
	cout << "ID: " << A.idPatient << "\n";
	cout << "Fullname: " << A.fullname << "\n";
	cout << "About times<day> : " << A.AboutTime << "\n";
	cout << "medicin fees: " << A.medicinFee << "\n";
	cout << "Bill: " << A.bills << "\n";
	cout << "ID doctor: " << A.idDoctor << "\n";
}
void fix(long long arr[], int n, long long brr[], int m) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m; i++) {
		cout << brr[i] << " ";
	}
}
void hospital::SetupHospital(hospital& A) {
	for (int i = 0; i < member; i++) {
		ArrDr[i].randomInf(ArrDr[i], i);
		arrdr[ndr] = ArrDr[i].getID(ArrDr[i]);
		ndr++;
	}
	for (int i = 0; i < customer; i++) {
		ArrPt[i].randomInf(ArrPt[i], i);
		arrpt[npt] = ArrPt[i].getID(ArrPt[i]);
		npt++;
	}
	fix(arrdr, member, arrpt, customer);
	for (int i = 0; i < member; i++) ArrDr[i].assignID(ArrDr[i], i);
	for (int i = 0; i < customer; i++) ArrPt[i].assignID(ArrPt[i], i);;
}
void hospital::showMode(hospital A) {
	cout << "\n---show Mode---\n";
	cout << "enter 1 show doctor Inf..\n";
	cout << "enter 2 show patient Inf..\n";
	cout << "enter 3 show all Inf..\n";
	int mode;
	cout << "select once mode\n";
	cin >> mode;
	switch (mode) {
	case 1:
	{
		for (int i = 0; i < member; i++) {
			ArrDr[i].showOff(ArrDr[i]);
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < customer; i++) {
			ArrPt[i].showOff(ArrPt[i]);
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < member; i++) {
			ArrDr[i].showOff(ArrDr[i]);
		}
		for (int i = 0; i < customer; i++) {
			ArrPt[i].showOff(ArrPt[i]);
		}
		break;
	}
	default: break;
	}
}
void hospital::searchID(hospital A) {
	long long id;
	int mode;
	cout << "\n---search mode---\n";
	cout << "enter 1 to search doctor and his patient.. \n";
	cout << "enter 2 to search patient and his doctor.. \n";
	cin >> mode;
	switch (mode) {
	case 1:
	{
		cin >> id;
		int i,j;
		for ( i = 0; i < member; i++) {
			if (ArrDr[i].getID(ArrDr[i]) == id) {
				ArrDr[i].showOff(ArrDr[i]);
				break;
			}
		}
		for (j = 0; j < customer; j++) {
			if (ArrPt[j].getID(ArrPt[j]) == ArrDr[i].drIDpt(ArrDr[i])) {
				ArrPt[j].showOff(ArrPt[j]);
				break;
			}
		}
		break;
	}
	case 2:
	{
		cin >> id;
		int i, j;
		for (i = 0; i < customer; i++) {
			if (ArrPt[i].getID(ArrPt[i]) == id) {
				ArrPt[i].showOff(ArrPt[i]);
				break;
			}
		}
		for (j = 0; j < member; j++) {
			if (ArrDr[j].getID(ArrDr[j]) == ArrPt[i].ptIDdr(ArrPt[i])) {
				ArrDr[j].showOff(ArrDr[j]);
			}
		}
		break;
	}
	default: break;
	}
}
long long patient::getBills(patient A) {
	return A.bills;
}
void hospital::highestFees(hospital A) {
	int max = 0;
	for (int i = 0; i < customer; i++) {
		if (ArrPt[i].getBills(ArrPt[i]) > ArrPt[max].getBills(ArrPt[max])) max = i;
	}
	for (int i = 0; i < member; i++) {
		if (ArrDr[i].getID(ArrDr[i]) == ArrPt[max].ptIDdr(ArrPt[max])) {
			ArrDr[i].showOff(ArrDr[i]);
			cout << "\nBill of his patient is " << ArrPt[max].getBills(ArrPt[max]) << " VND \n";
		}
	}
}