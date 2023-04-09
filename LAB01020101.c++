#include<iostream>
#include<math.h>
#include<time.h>
#define size 5
using namespace std;
class fraction {
private:
	int numerator;
	int denominator;
public:
	fraction(int tu=0,int mau=0)
		:numerator(tu),denominator(mau)
	{}
	void input(fraction &A);
	void show(fraction);
	fraction simplifying_fraction(fraction &A);
	fraction compare_fractions(fraction, fraction);
	void operation_fractions(fraction, fraction);
	void cpy_fractions(fraction A, fraction& B);
	void get_fraction(fraction &A,int);
	fraction max(fraction A[]);
};
void fraction::get_fraction(fraction& A,int seed) {
	srand(seed);
	A.numerator = rand() % 100;
	A.denominator = rand() % 200;
}
void fraction::input(fraction& A) {
	cin >> A.numerator;
	cin >> A.denominator;
}
void fraction::show(fraction A) {
	if (A.numerator == 0) cout << "0"<<"\n";
	else if (A.numerator % A.denominator == 0) cout << A.numerator / A.denominator<<"\n";
	else if (A.numerator < 0 && A.denominator < 0) cout << abs(A.numerator) << "/" << abs(A.denominator)<<"\n";
	else if (A.numerator > 0 && A.denominator < 0) cout << "-" << A.numerator << "/" << abs(A.denominator)<<"\n";
	else cout << A.numerator << "/" << A.denominator<<"\n";
		
}
fraction fraction::simplifying_fraction(fraction& A) {
	int a, b;
	a = abs(A.numerator);
	b = abs(A.denominator);
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	A.numerator /= a;
	A.denominator /= b;
	return A;
}
fraction fraction::compare_fractions(fraction A, fraction B) {
	float decimal01 = float(A.numerator) / A.denominator;
	float decimal02 = float(B.numerator) / B.denominator;
		if (decimal01 > decimal02) {
		//	cout << "the bigger fraction: ";
			return A;
		}
		else {
		//	cout << "the bigger fraction: ";
			return B;
		}
}
void fraction::cpy_fractions(fraction A, fraction& B) {
	B.numerator = A.numerator;
	B.denominator = A.denominator;
}
void fraction::operation_fractions(fraction A, fraction B) {
	fraction C(numerator, denominator);//cong
	cout << "Cong: " ;
	C.numerator = A.numerator * B.denominator + B.numerator * A.denominator;
	C.denominator = A.denominator * B.denominator;
	C.simplifying_fraction(C);
	C.show(C);
	//tru
	cout << "Tru: ";
	C.numerator = A.numerator * B.denominator - B.numerator * A.denominator;
	C.denominator = A.denominator * B.denominator;
	C.simplifying_fraction(C);
	C.show(C);
	//nhan 
	cout << "Nhan: ";
	C.numerator = A.numerator * B.numerator;
	C.denominator = A.denominator * B.denominator;
	C.simplifying_fraction(C);
	C.show(C);
	//chia
	cout << "Chia: ";
	C.numerator = A.numerator * B.denominator;
	C.denominator = A.denominator * B.numerator;
	C.simplifying_fraction(C);
	C.show(C);
}
fraction fraction::max(fraction A[]) {
	fraction max;
	max.cpy_fractions(A[0], max);
	for (int i = 0; i < size; i++) {
		if ((A[i], max).compare_fractions(A[i], max).numerator!=max.numerator) cpy_fractions(A[i], max);
	}
	return max;
}
int main() {
	//Cau 1: khoi tao phan so
	fraction A(4, 6);
	fraction B(25,30);
	cout << "Cau 2: Xuat phan so\n";
	A.show(A);
	B.show(B);
	/*
	input:
	+ fraction A(numerator = 4,denominator = 6)
	+ fraction B(numerator = 25,denominator = 30)
	output:
	4/6
	25/30
	*/
	cout << "Cau 3: Rut gon phan so\n";
	A.simplifying_fraction(A);
	B.simplifying_fraction(B);
	A.show(A);
	A.show(B);
	/*
	input:
	+ fraction A(numerator = 4,denominator = 6)
	+ fraction B(numerator = 25,denominator = 30)
	output:
	simplifying fraction
	2/3
	5/6
	*/
	cout << "Cau 4: So sanh phan so\n";
	(A,B).compare_fractions(A, B).show((A, B).compare_fractions(A, B));
	/*
	input:
	+ fraction A(numerator = 2,denominator = 3)
	+ fraction B(numerator = 5,denominator = 6)
	output:
	5/6
	*/
	cout << "Cau 5,6,7,8: Cong Tru Nhan Chia\n";
	(A, B).operation_fractions(A, B);
	/*
	input:
	+ fraction A(numerator = 2,denominator = 3)
	+ fraction B(numerator = 5,denominator = 6)
	output:
	cong: 3/2
	tru: -1/6
	nhan: 5/9
	chia: 4/5
	*/
	cout << "Cau 9 : Sao chep hai phan so\n";
	fraction C;
	(A, C).cpy_fractions(A, C);
	C.show(C);
	/*
	input:
	+ fraction A(numerator = 2,denominator = 3)
	+ fraction C(numerator = 0,denominator = 0)
	output:
//	(copy A for C)
//	fraction C(numerator = 2,denominator = 3)
	2/3
	*/
	cout << "Cau 10: tim phan so lon nhat trong nhieu phan so\n";
	fraction* Arr = new fraction[size];
	for (int i = 0; i < size; i++) {
		Arr[i].get_fraction(Arr[i], i);
		Arr[i].show(Arr[i]);
	}
	cout << "max\n";
	Arr->max(Arr).show(Arr->max(Arr));
	/*
	input:
	38/119
    41/67
    45/16
    48/196
    51/145
	output:
	45/16
	*/
	return 0;
}