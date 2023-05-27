#include"college.h"
int student::getAverage() {
	return this->average;
}
long long student::getID() {
	return this->ID;
}
int VB2sv::getmarkRange() {
	return this->markRange;
}
int Undergraduate::getmarkThesis() {
	return this->markThesis;
}
int student::getcredits() {
	return this->credits;
}
void student::showOFF() {
	cout << "\nID : " << this->ID;
	cout << "\nFull name : " << this->fullname;
	cout << "\nCredits : " << this->credits;
	cout << "\nAddress : " << this->address;
	cout << "\nAverage : " << this->average;
}
void VB2sv::showoff() {
	this->showOFF();
	cout << "\nMark range : " << this->markRange<<"\n";
}
void VB2sv::randomInf(VB2sv& A, int seed) {
	srand(seed);
	A.ID = rand() % 2001 + 22521276;
	string ArrName[10] = { "Tai","Thai","Tan","Son","Thang","Lam","Quyen","Sang","Thoang","Quang" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrN = rand() % 10;
	int indexArrSN = rand() % 10;
	A.fullname = ArrSurname[indexArrSN] + " " + ArrName[indexArrN];
	A.credits = 50 + rand() % 50;
	string ArrDistric[8] = { "Q1","Q2","Q3","Q4","Q5","Q7","Thu Duc","Go vap" };
	string ArrCity[5] = { "TP HCM","TP Nha Trang","TP Vung Tau","Ha Noi","TP Da Lat" };
	int indexdistric = rand() % 8;
	int indexcity = rand() % 5;
	A.address = ArrDistric[indexdistric] + " " + ArrCity[indexcity];
	A.average = 3 + rand() % 6;
	A.markRange = 3 + rand() % 6;
}
void Undergraduate::showoff() {
	this->showOFF();
	cout << "\nName thesis : " << this->NameThesis;
	cout << "\nMark thesis : " << this->markThesis<<"\n";
}
void Undergraduate::randomInf(Undergraduate& A, int seed) {
	srand(seed);
	A.ID = rand() % 2001 + 22525276;
	string ArrName[10] = { "Tai","Thai","Tan","Son","Thang","Lam","Quyen","Sang","Thoang","Quang" };
	string ArrSurname[10] = { "Le","Nguyen","Tran","Ho","Vo","Dinh","Cao","Ly","Vuong","Nhat" };
	int indexArrN = rand() % 10;
	int indexArrSN = rand() % 10;
	A.fullname = ArrSurname[indexArrSN] + " " + ArrName[indexArrN];
	A.credits = 50 + rand() % 50;
	string ArrDistric[8] = { "Q1","Q2","Q3","Q4","Q5","Q7","Thu Duc","Go vap" };
	string ArrCity[5] = { "TP HCM","TP Nha Trang","TP Vung Tau","Ha Noi","TP Da Lat" };
	int indexdistric = rand() % 8;
	int indexcity = rand() % 5;
	A.address = ArrDistric[indexdistric] + " " + ArrCity[indexcity];
	A.average = 3 + rand() % 6;
	string ArrThesis[10] = { "Operating system","Multi-user","Alphanumeric data","Broad classification","Cluster controller","OSI","Remote Access","Microprocessor","Gateway""Chief source of information" };
	int indexthesis = rand() % 10;
	A.NameThesis = ArrThesis[indexthesis];
	A.markThesis = 3 + rand() % 6;
}
void college::setupCollege(college& A) {
	for (int i = 0; i < member; i++) {
		VB2sv m;
		Undergraduate n;
		m.randomInf(m, i);
		vb2.push_back(m);
		n.randomInf(n, i);
		sv.push_back(n);
	}
	cout <<"\n\t\t" << vb2.size() << " && " << sv.size()<<"\n";
}
void college::InfStudent(college A) {
	int mode;
	cout << "\n\t==select option==\n";
	cout << "\n enter 1 : inf VB2 students";
	cout << "\n enter 2 : inf Undergraduate students";
	cout << "\n enter 3 : inf VB2 && Undergraduate students\n";
	cout << "enter : ";
	cin >> mode;
	switch (mode)
	{
	case 1: {
		for (int i = 0; i < A.vb2.size(); i++) {
			A.vb2[i].showoff();
		}
		break;
	}
	case 2: {
		for (int i = 0; i < A.sv.size(); i++) {
			A.sv[i].showoff();
		}
		break;
	}
	case 3: {
		cout << "\n\t VB2 student\n";
		for (int i = 0; i < A.vb2.size(); i++) {
			A.vb2[i].showOFF();
		}
		cout << "\n\t Undergraduate student\n";
		for (int i = 0; i < A.sv.size(); i++) {
			A.sv[i].showOFF();
		}
	}
	default:
		break;
	}
}
void college::searchID(college A,long long id) {
	int i = 0, j = 0;
	int control=0;
	while (i < A.vb2.size()) {
		if (A.vb2[i].getID() == id) {
		//	cout << "\n He is : ";
			A.vb2[i].showOFF();
			control = 1;
			break;
		}
		i++;
	}
	if (control == 0) {
		while (j < A.sv.size()) {
			if (A.sv[j].getID() == id) {
			//	cout << "\n He is : ";
				A.sv[j].showOFF();
				break;
			}
			j++;
		}
	}
}
void college::graduation(college A) {
	vector<long long> Graduated;
	vector<long long> nonGraduated;
	for (int i = 0; i < A.vb2.size(); i++) {
		if (A.vb2[i].getcredits() >= 84 && A.vb2[i].getAverage() >= 5 && A.vb2[i].getmarkRange() >= 5) {
			Graduated.push_back(A.vb2[i].getID());
		}
		else {
			nonGraduated.push_back(A.vb2[i].getID());
		}
	}
	for (int j = 0; j < A.sv.size(); j++) {
		if (A.sv[j].getcredits() >= 120 && A.sv[j].getAverage() >= 5 && A.sv[j].getmarkThesis() >= 5) {
			Graduated.push_back(A.sv[j].getID());
		}
		else {
			nonGraduated.push_back(A.sv[j].getID());
		}
	}
	cout << "\n" << Graduated.size() << " && " << nonGraduated.size() << "\n";
	int mode;
	cout << "\n\t==select option==\n";
	cout << "\n enter 1 : graduated student";
	cout << "\n enter 2 : non-graduated student\n";
	cout << "enter : ";
	cin >> mode;
	switch (mode)
	{
	case 1: {
		cout << "\n\t===========Graduated student============\n";
		for (int i = 0; i < Graduated.size(); i++) {
			A.searchID(A, Graduated[i]);
			cout << endl;
		}
		break;
	}
	case 2: {
		cout << "\n\t==========non-graduaed student==========\n";
		for (int j = 0; j < nonGraduated.size(); j++) {
			A.searchID(A, nonGraduated[j]);
			cout << endl;
		}
		break;
	}
	default:
		break;
	}
}
void college::minAverage(college A) {
	int min = 0;
	for (int i = 0; i < A.vb2.size(); i++) {
		if (A.vb2[i].getAverage() < A.vb2[min].getAverage()) min = i;
	}
	cout << "\n\t min Average <VB2> is :\n";
	A.searchID(A, A.vb2[min].getID());
}
void college::maxAverage(college A) {
	int maxsv = 0;
	for (int i = 0; i < A.sv.size(); i++) {
		if (A.sv[i].getAverage() > A.sv[maxsv].getAverage()) maxsv = i;
  }
	int maxvb2 = 0;
	for (int i = 0; i < A.vb2.size(); i++) {
		if (A.vb2[i].getAverage() > A.vb2[maxvb2].getAverage()) maxvb2 = i;
	}
	cout << "\n\t max Average <ALL> is :\n";
	if (A.sv[maxsv].getAverage() > A.vb2[maxvb2].getAverage()) A.searchID(A, A.sv[maxsv].getID());
	else A.searchID(A, A.vb2[maxvb2].getID());
}