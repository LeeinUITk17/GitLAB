#include"Header.h"
#include"hospital.h"
int main() {
	hospital huslang;
	huslang.SetupHospital(huslang);
	cout << "\ncau 3,4 : tinh tien thuoc,tien kham benh\n"; 
	/*
	input: hospital hustlang,int mode <use to select option>
	output: show Informations of patient is his bill,his  medicin fee.. 
	call void randomInf(doctor& A, int seed);
	call void randomInf(patient& A, int seed);
	call void setBills(patient& A);
	call void setSalary(doctor& A);
	call void showOff(patient A);
	call void showOff(doctor A);
	*/
	huslang.showMode(huslang);
	cout << "\ncau 1,2 : tim bac si, tim benh nhan <use menu>\n";
	/*
	input: hospital huslang, long long id, int mode<use to select option>
	ouput: show Informations of doctor & his patient
	call void searchID(hospital A);
	call void showOff(patient A);
	call void showOff(doctor A);
	*/
	huslang.searchID(huslang);
	cout << "\ncau 5: tim bac si co tien cong kham lon nhat\n";// tim bac si cua benh nhan co Bill lon nhat
	/*
	input: hospital huslang
	output: show informations of doctor and his patient's bill
	call long long getBills(patient A);
	call void showOff(doctor A);
	call long long getID(doctor A);
	call long long getID(patient A);
	*/
	huslang.highestFees(huslang);
	return 0;
}
