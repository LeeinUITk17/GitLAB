#include<iostream>
#include<math.h>
#include<time.h>
#define size 10
using namespace std;
class fraction {
private:
	int numerator;
	int denominator;
public:
	fraction(int tu=0,int mau=0)
		:numerator(tu),denominator(mau)
	{}
	friend istream& operator>>(istream& in, fraction& A);
	friend ostream& operator<<(ostream& on, fraction& A);
	fraction operator+(const fraction& A);
	fraction operator-(const fraction& A);
	fraction operator*(const fraction& A);
	fraction operator/(const fraction& A);
	fraction operator==(const fraction& A);
    fraction operator!=(const fraction& A);
	bool operator>(const fraction& A);
	bool operator<(const fraction& A);
	void simplfying(fraction& A);
	void max(fraction A[]);
	fraction compare(fraction, fraction);
	void randomMode(fraction& A,int);
	void ArrMode(fraction A[]);
};
istream& operator>>(istream& in, fraction& A) {
	in >> A.numerator;
//	cout << endl;
	in >> A.denominator;
	return in;
}
ostream& operator<<(ostream& on, fraction& A) {
	if (A.numerator == 0) on << "0";
	else if (A.numerator % A.denominator == 0) on << A.numerator / A.denominator;
	else if (A.numerator < 0 && A.denominator < 0) on << abs(A.numerator) << "/" << abs(A.denominator);
	else if (A.numerator > 0 && A.denominator < 0) on << "-" << A.numerator << "/" << abs(A.denominator);
	else on << A.numerator << "/" << A.denominator;
	return on;
}
fraction fraction::operator!=(const fraction& A) {
	fraction res;
	res.numerator = -A.numerator;
	res.denominator = A.denominator;
	return res;
}
fraction fraction::operator+(const fraction& A) {
	fraction res;
	res.numerator = numerator * A.denominator + A.numerator * denominator;
	res.denominator = denominator * A.denominator;
	return res;
}
fraction fraction::operator-(const fraction& A) {
	fraction res;
	res.numerator = numerator * A.denominator - A.numerator * denominator;
	res.denominator = denominator * A.denominator;
	return res;
}
fraction fraction::operator*(const fraction& A) {
	fraction res;
	res.numerator = numerator * A.numerator;
	res.denominator = denominator * A.denominator;
	return res;
}
fraction fraction::operator/(const fraction& A) {
	fraction res;
	res.numerator = numerator * A.denominator;
	res.denominator = denominator * A.numerator;
	return res;
}
fraction fraction::operator==(const fraction& A) {
	fraction res;
	res.numerator = A.numerator;
	res.denominator = A.denominator;
	return res;
}
bool fraction::operator<(const fraction& A) {//A<B return true else false
	return (numerator * A.denominator) < (A.numerator * denominator) ? true : false;
}
bool fraction::operator>(const fraction& A) {//A>B return true else false
	return (numerator * A.denominator) > (A.numerator * denominator) ? true : false;
}
void fraction::simplfying(fraction& A) {
	int a, b;
	a = abs(A.numerator);
	b = abs(A.denominator);
	while (a != b) {
		if (a > b)a -= b;
		else b -= a;
	}
	A.numerator = A.numerator / a;
	A.denominator = A.denominator / a;
}
fraction fraction::compare(fraction A, fraction B) {//A<=B return B else return A
	if (A < B == true) return B;
	else if (A<B == false && A>B == false) return B;// A=B return B
	else return A;
}
void fraction::max(fraction A[]) {
	fraction max = A[0];
	for (int i = 0; i < size; i++) {// operator == is copy fraction
		max = compare(max, A[i]);
	}
	cout <<"Cau 12 tim phan so lon nhat " << max << "\n";
}
void fraction::randomMode(fraction& A, int seed) {
	srand(seed);
	A.numerator = 1 + rand() % 101;
	A.denominator = 1 + rand() % 101;
	A.simplfying(A);
}
void fraction::ArrMode(fraction A[]) {
	for (int i = 0; i < size; i++) {
		A[i].randomMode(A[i], i);
	}
	for (int i = 0; i < size; i++) {
		cout << A[i] << " ";
	}
}
int main() {
	//Cau 1 khoi tao phan so
	fraction A;
	cout << "Cau 2 Nhap phan so bang cin \n";
	/*
	input: numerator & denominator ex (2 4) 
	output: A.numerator=2
	        A.denominator=4 // call istream& operator>>(istream& in, fraction &A);
	*/
	cin >> A;
	cout << "Cau 4 rut gon phan so da nhap\n";
	/*
	input: fraction A ( 2/4 )
	ouput: 
	A.numurator=1
	A.denominator=2 // used void simplfying(fraction &A);
	*/
	A.simplfying(A);
	//Cau 3 xuat phan so bang cout <<
	/*
	input: fraction A (2/4)
	output: 2/4 //call ostream& operator<<(ostream& on, fraction& A);
	*/
	cout << A<<"\n";
	fraction B;
	cin >> B;
	B.simplfying(B);
	cout << B<<"\n";
	//B != B;
	B.simplfying(B);
	cout << B << "\n";
	fraction C;
	C=A + B;
	C.simplfying(C);
	cout<<"Cau 7 cong hai phan so " << C << "\n";
	C = A - B;
	C.simplfying(C);
	cout <<"Cau 8 tru hai phan so " << C << "\n";
	C = A * B;
	C.simplfying(C);
	cout <<"Cau 9 nhan hai phan so " << C << "\n";
	C = A / B;
	C.simplfying(C);
	cout <<"Cau 10 chia hai phan so " << C << "\n";
	C = A;
	cout <<"Cau 11 sao chep hai phan so " << C<<"\n";
	fraction* Arr = new fraction[size];
	Arr->ArrMode(Arr);
	cout << "\n";
	Arr->max(Arr);
	return 0;
}