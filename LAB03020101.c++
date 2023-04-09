#include<iostream>
#include<time.h>
#include<cmath>
#include<math.h>
using namespace std;
int seed = 1;
class coordinate {
private:
	float ordinate;
	float abscissa;
public:
	coordinate(float tung=0, float hoanh=0)
		:ordinate(tung), abscissa(hoanh)
	{}
	void inputRandom(coordinate& A,int );
	void showCoordinate(coordinate);
	float distanceCoordinate(coordinate, coordinate);
};
float coordinate::distanceCoordinate(coordinate A, coordinate B) {
	float distanceOrdinate, distanceAbscissa;
	if (A.ordinate >= B.ordinate) distanceOrdinate = (A.ordinate - B.ordinate);
	else distanceOrdinate = (B.ordinate - A.ordinate);
	if (A.abscissa >= B.abscissa) distanceAbscissa = (A.abscissa - B.abscissa);
	else distanceAbscissa = (B.abscissa - A.abscissa);
	return sqrt(pow(distanceAbscissa, 2) + pow(distanceOrdinate, 2));
}
void coordinate::showCoordinate(coordinate A) {
	cout << "(" << A.ordinate << "," << A.abscissa << ")\n";
}
void coordinate::inputRandom(coordinate& A,int seed) {
	srand(seed);
	A.ordinate = rand() % 20;
	A.abscissa = rand() % 30;
}
int checkTriangle(float a, float b, float c) {
	if (a + b < c || a + c < b || b + c < a) return 0;
	return 1;
}
class triangle 
{
private:
	coordinate A;
	coordinate B;
	coordinate C;
public:
	triangle(coordinate a, coordinate b, coordinate c)
		:A(a), B(b), C(c)
	{}
	void createTriangle(triangle& A);
	void showInf(triangle );
	int setType(triangle&A);
	float getPerimeter(triangle);
	float getArea(triangle);
};
void triangle::createTriangle(triangle& As) {
	As.A.inputRandom(As.A,++seed);
	As.B.inputRandom(As.B,++seed);
	As.C.inputRandom(As.C,++seed);
}
void triangle::showInf(triangle As) {
	As.A.showCoordinate(As.A);
	As.B.showCoordinate(As.B);
	As.C.showCoordinate(As.C);
}
int triangle::setType(triangle& As) {
	float sideAB, sideAC, sideBC;
	sideAB = (As.A, As.B).distanceCoordinate(As.A, As.B);
	sideAC = (As.A, As.C).distanceCoordinate(As.A, As.C);
	sideBC = (As.B, As.C).distanceCoordinate(As.B, As.C);
	if (checkTriangle(sideAB, sideAC, sideBC) == 0) {
		createTriangle(As);
		return triangle::setType(As);
	}
	//if (pow(sideAB, 2) == pow(sideAC, 2) + pow(sideBC, 2) || pow(sideAC, 2) == pow(sideAB, 2) + pow(sideBC, 2) || pow(sideBC, 2) = pow(sideAB, 2) + pow(sideAC, 2)) return 1;
	if (sideAB * sideAB == sideAC * sideAC + sideBC * sideBC || sideAC * sideAC == sideAB * sideAB + sideBC * sideBC || sideBC * sideBC == sideAB * sideAB + sideAC * sideAC) return 1;
	else if (sideAB == sideAC && sideAB == sideBC && sideAC == sideBC) return 2;
	else if (sideAB * sideAB > sideAC * sideAC + sideBC * sideBC || sideAC * sideAC > sideAB * sideAB + sideBC * sideBC || sideBC * sideBC > sideAC * sideAC + sideAB * sideAB) return 3;
	else if (sideAB == sideAC && sideAC == sideBC) return 4;
	else return 5;
}
float triangle::getPerimeter(triangle As) {
	float sideAB, sideAC, sideBC;
	sideAB = (As.A, As.B).distanceCoordinate(As.A, As.B);
	sideAC = (As.A, As.C).distanceCoordinate(As.A, As.C);
	sideBC = (As.B, As.C).distanceCoordinate(As.B, As.C);
	return sideAB + sideAC + sideBC;
}
float triangle::getArea(triangle As) {
	float sideAB, sideAC, sideBC;
	sideAB = (As.A, As.B).distanceCoordinate(As.A, As.B);
	sideAC = (As.A, As.C).distanceCoordinate(As.A, As.C);
	sideBC = (As.B, As.C).distanceCoordinate(As.B, As.C);
	float p = (sideAB + sideAC + sideBC) / 2;
	return sqrt(p * (p - sideAB) * (p - sideAC) * (p - sideBC));
}
void typeTriangle(int n) {
	if (n == 1) cout << "Right Triangle\n";
	else if (n == 2) cout << "Isosceles Triangle\n";
	else if (n == 3) cout << "Obtuse Triangle\n";
	else if (n == 4) cout << "Equilateral Triangle\n";
	else cout << "Scalene Triangle\n";
}
int main() {
	coordinate a, b, c;
	triangle As(a,b,c);
	As.createTriangle(As);
	typeTriangle(As.setType(As));
	As.showInf(As);
	cout << As.getPerimeter(As) << "\n";
	cout << As.getArea(As) << "\n";
	system("pause");
	return 0;
}