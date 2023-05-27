#pragma once
#include"Header.h"
class student {
protected:
	long long ID;
	string fullname;
	int credits;
	string address;
	int average;
public: 
    void showOFF();
	int getAverage();
	long long getID();
	int getcredits();
};
class VB2sv :public student {
private:
	int markRange;
public:
	void showoff();
	void randomInf(VB2sv& A, int seed);
	int getmarkRange();
};
class Undergraduate :public student {
private:
	string NameThesis;
	int markThesis;
public:
	void showoff();
	void randomInf(Undergraduate& A, int seed);
	int getmarkThesis();
};
class college {
private:
	vector<VB2sv> vb2;
	vector<Undergraduate> sv;
public:
	void setupCollege(college& A);
	void InfStudent(college A);
	void graduation(college A);
	void searchID(college A,long long id);
	void minAverage(college A);
	void maxAverage(college A);
};