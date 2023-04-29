#include"Header.h"
#include"Time.h"
int main() {
	Time A, B(12, 18, 40);
	cout << "cau 1: nhap thoi gian bang >>\n";
	/*
	input:12 5 45
	output:A(12,5,45) call istream& operator>>(istream& in, Time& A);
	*/
	cin >> A;
	cout << "cau 2: xuat thoi gian bang <<\n";
	/*
	input:A(12,5,45)
	output:12:5:45.call ostream& operator<<(ostream& on, Time& A);
	*/
	cout << A;
	Time C = A + B;
	cout << "\ncau 4:cong tru hai thoi gian <cong>";
	/*
	input:A(12,4,45) B(12,18,40)
	output:C(0,24,25) call Time operator+(Time const& A);
	*/
	cout << endl << C;
	Time D = C - A;
	cout << "\ncau 4:cog tru hai thoi gian <tru>";
	/*
	input:C(0,24,25) A(12,4,45)
	output:D(12,18,40) call Time operator-(Time const& A);
	*/
	cout << endl << D;
	D = D + 15;
	cout << "\ncau 3:cong tru so nguyen giay vao thoi gian <cong>";
	/*
	input:D((12,18,40)+15
	output: D(12,18,55) call Time operator+(int const& ss);
	*/
	cout << endl << D;
	D = D - 11;
	cout << "\ncau 3:cong tru so nguyen giay vao thoi gian <tru>";
	/*
	input: D(12,18,55)-11
	output: D(12,18,44) call Time operator-(int const& ss);
	*/
	cout << endl << D;
	D=D++;
	cout << "\ncau 5:<++>";
	/*
	input:D(12,18,44)
	output:D(12,18,45) call Time operator++(int);
	*/
	cout << endl << D;
	D=D--;
	cout << "\ncau 5:<-->";
	/*
	input:D(12,18,45)
	output:D(12,18,44) call Time operator--(int);
	*/
	cout << endl << D;
	return 0;
}
