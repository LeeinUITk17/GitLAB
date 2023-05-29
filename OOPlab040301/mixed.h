#pragma once
#include"Header.h"
class fraction {
private:
	int numerator;
	int denominator;
public:
	fraction(int tu=0,int mau=0)
		:numerator(tu),denominator(mau)
	{}
	friend ostream& operator<<(ostream& os, const fraction& ps);
	friend istream& operator>>(istream& in, fraction& ps);
	int getNumberator();
	int getDenominator();
	void changeNumerator(int num);
	void changeDenominator(int num);
	fraction compareFrac(fraction A, fraction B);
	fraction simplifyingFrac(fraction& A);
};
class mixed:public fraction
{
private:
	int primeNumber;
	fraction frac;
public:
	mixed(int nguyen=0,int tu=0,int mau=0)
		:primeNumber(nguyen),fraction(tu,mau)
	{}
	friend ostream& operator<<(ostream& os, const mixed& hs);
	friend istream& operator>> (istream& in,  mixed& hs);
	friend mixed operator+(mixed a, mixed b);
	friend mixed operator-(mixed a, mixed b);
	friend mixed operator*(mixed a, mixed b);
	friend mixed operator/(mixed a, mixed b);
	fraction MixedTofraction(mixed a);
	mixed FractionToMixed(fraction a);
	void compare(mixed A, mixed B);
	void operation(mixed A,mixed B);
};
