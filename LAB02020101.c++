#include<iostream>
#include<cmath>
using namespace std;
class coordinate {
private:
	float abscissa;
	float ordinate;
public:
	coordinate(float tung=0,float hoanh=0)
		:ordinate(tung),abscissa(hoanh)
	{}
	void input(coordinate& A);
	void show(coordinate);
	void setCoordinate(coordinate &A,float,float);
	int getAbscissa(coordinate);
	int getOrdinate(coordinate);
	void moveCoordinate(coordinate& A,coordinate);
	float distanceCoordinate(coordinate, coordinate);
	coordinate midpoint(coordinate,coordinate);
	void deletePoint(coordinate& A);
	void cpyCoordinate(coordinate, coordinate& B);
};
void coordinate::cpyCoordinate(coordinate A, coordinate& B) {
	B.ordinate = A.ordinate;
	B.abscissa = A.abscissa;
}
void coordinate::deletePoint(coordinate& A) {
	A.ordinate = 0;
	A.abscissa = 0;
}
coordinate coordinate::midpoint(coordinate A,coordinate B) {
	coordinate point;
	point.ordinate = (float)(A.ordinate + B.ordinate) / 2;
	point.abscissa = (float)(A.abscissa + B.abscissa) / 2;
	return point;
}
void coordinate::input(coordinate& A) {
	cin >> A.ordinate >> A.ordinate;
}
void coordinate::show(coordinate A) {
	cout << "Ordinate: " << A.ordinate << endl;
	cout << "Abscissa: " << A.abscissa << endl;
}
void coordinate::setCoordinate(coordinate& A,float ordinateSS,float abscissaSS) {
	A.ordinate = ordinateSS;
	A.abscissa = abscissaSS;
}
int coordinate::getAbscissa(coordinate A) {
	return A.abscissa;
}
int coordinate::getOrdinate(coordinate A) {
	return A.ordinate;
}
void coordinate::moveCoordinate(coordinate& A, coordinate vector) {
	A.ordinate += vector.ordinate;
	A.abscissa += vector.abscissa;
}
float coordinate::distanceCoordinate(coordinate A, coordinate B) {
	float distanceOrdinate,distanceAbscissa;
	if (A.ordinate >= B.ordinate) distanceOrdinate = (A.ordinate - B.ordinate);
	else distanceOrdinate = (B.ordinate - A.ordinate);
	if (A.abscissa >= B.abscissa) distanceAbscissa = (A.abscissa - B.abscissa);
	else distanceAbscissa = (B.abscissa - A.abscissa);
	return sqrt(pow(distanceAbscissa, 2) + pow(distanceOrdinate, 2));
}
int main() {
	//Cau 1: khoi tao toa do diem
	coordinate A(2, 3);
	coordinate B(5, 6);
	cout << "Cau 2: Xuat toa do diem\n";
	A.show(A);
	B.show(B);
	/*
	input:
	A(2,3),B(5,6)
	output:
Ordinate: 2
Abscissa: 3
Ordinate: 5
Abscissa: 6
	*/
	cout << "Cau 3: lay tung do,hoanh do\n";
	cout << A.getOrdinate(A) << " & " << A.getAbscissa(A);
	/*
	input:
	A(2,3);
	output:
	2 & 3
	*/
	cout << "\nCau 4: thay doi tung do,hoanh do\n";
	/*
	input:
	A(2,3),4,5
	ouput:
	//A(4,5)
	Ordinate: 2
    Abscissa: 3
	*/
	A.setCoordinate(A, 4, 5);
	A.show(A);
	cout << "Cau 5: di chuyen den toa do\n";
	/*
	input:
	A(4,5),vector(-2,-2);
	output:
	//A(2,3)
	Ordinate: 2
	Abscissa: 3
	*/
	coordinate vector(-2, -2);
	A.moveCoordinate(A, vector);
	A.show(A);
	cout << "Cau 6: khoang canh hai diem\n";
	cout<<(A, B).distanceCoordinate(A, B)<<"\n";
	/*
	input:
	A(2,3),B(5,6);
	output:
	3.16228
	*/
	cout << "Cau 7: tim toa do trung diem\n";
	(A, B).midpoint(A, B).show((A, B).midpoint(A, B));
	cout << "Cau 8: xoa toa do\n";
	coordinate C(7, 8);
	C.deletePoint(C);
	C.show(C);
	/*
	input:
	C(7,8);
	output:
	//C(0,0);
	Ordinate: 0
	Abscissa: 0
	*/
	cout << "Cau 9: sao chep toa do\n";
	coordinate D;
	D.cpyCoordinate(A, D);
	D.show(D);
	/*
	input:
	D(0,0);
	ouput:
	//D(2,3);
	Ordinate: 2
	Abscissa: 3
	*/
   return 0;
}