#include"mixed.h"
//-----fraction number-------
ostream& operator<<(ostream& os, const fraction& ps) {
	os << ps.numerator << "/" << ps.denominator;
	return os;
}
istream& operator>>(istream& in, fraction& ps) {
	in >> ps.numerator;
	in >> ps.denominator;
	return in;
}
void fraction::changeNumerator(int num) {
	this->numerator = num;
}
void fraction::changeDenominator(int num) {
	this->denominator = num;
}
int fraction::getNumberator() {
	return this->numerator;
}
int fraction::getDenominator() {
	return this->denominator;
}
fraction fraction::compareFrac(fraction A, fraction B) {
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
fraction fraction::simplifyingFrac(fraction& A) {
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
//-----mixed number-------
ostream& operator<<(ostream& os, const mixed& hs) {
	os << hs.primeNumber << " & " << hs.frac;
	return os;
}
istream& operator>> (istream& in,  mixed& hs) {
	in >> hs.primeNumber;
	in >> hs.frac;
	return in;
 }
fraction mixed::MixedTofraction(mixed a) {
	fraction b;
	b.changeNumerator(a.primeNumber * a.frac.getDenominator() + a.frac.getNumberator());
	b.changeDenominator(a.frac.getDenominator());
	return b;
}
mixed mixed::FractionToMixed(fraction a) {
	mixed b;
	if (a.getNumberator() % a.getDenominator() != 0) {
		b.primeNumber = ((a.getNumberator()-(a.getNumberator() % a.getDenominator()))/a.getDenominator());
		b.frac.changeNumerator(a.getNumberator() - b.primeNumber * a.getDenominator());
		b.frac.changeDenominator(a.getDenominator());
	}
	else {
		cout << "can not transfer fraction to mixed number !";
		return b;
	}
	return b;
}
void mixed::compare(mixed A, mixed B) {
	fraction a = A.MixedTofraction(A);
	fraction b = B.MixedTofraction(B);
	cout << A.FractionToMixed(a.compareFrac(a, b));
}
mixed operator+(mixed a, mixed b) {
	fraction m=a.MixedTofraction(a);
	fraction n = b.MixedTofraction(b);
	fraction p;
	p.changeNumerator(m.getNumberator() * n.getDenominator() + n.getNumberator() * n.getDenominator());
	p.changeDenominator(m.getDenominator() * n.getDenominator());
	p.simplifyingFrac(p);
	mixed d=a.FractionToMixed(p);
	return d;
}
mixed operator-(mixed a, mixed b) {
	fraction m = a.MixedTofraction(a);
	fraction n = b.MixedTofraction(b);
	fraction p;
	p.changeNumerator(m.getNumberator() * n.getDenominator() - n.getNumberator() * n.getDenominator());
	p.changeDenominator(m.getDenominator() * n.getDenominator());
	p.simplifyingFrac(p);
	mixed d = a.FractionToMixed(p);
	return d;
}
mixed operator*(mixed a, mixed b) {
	fraction m = a.MixedTofraction(a);
	fraction n = b.MixedTofraction(b);
	fraction p;
	p.changeNumerator(m.getNumberator() * n.getNumberator());
	p.changeDenominator(m.getDenominator() * n.getDenominator());
	p.simplifyingFrac(p);
	mixed d = a.FractionToMixed(p);
	return d;
}
mixed operator/(mixed a, mixed b) {
	fraction m = a.MixedTofraction(a);
	fraction n = b.MixedTofraction(b);
	fraction p;
	p.changeNumerator(m.getNumberator() * n.getDenominator());
	p.changeDenominator(m.getDenominator() * n.getNumberator());
	p.simplifyingFrac(p);
	mixed d = a.FractionToMixed(p);
	return d;
}
void mixed::operation(mixed A, mixed B) {
	cout << "\nAddition: ";
	cout << A + B;
	cout << "\nSubtraction: ";
	cout << A - B;
	cout << "\nMultiplication: ";
	cout << A * B;
	cout << "\nDivision: ";
	cout << A / B;
}