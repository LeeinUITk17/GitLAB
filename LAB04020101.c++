#include<iostream>
#include<time.h>
#include<cmath>
#include<math.h>
#define pi 3.14
using namespace std;
int seed=3;
class coordinate {
private:
	int ordinate;
	int abscissa;
public:
	coordinate(int tung=0,int hoanh=0)
		:ordinate(tung),abscissa(hoanh)
	{}
	void createCoordinate(coordinate& A,int &seed);
	void showCoordinate(coordinate);
	int distanceCoordinate(coordinate, coordinate);
};
int coordinate::distanceCoordinate(coordinate A, coordinate B) {
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
void coordinate::createCoordinate(coordinate& A,int &seed) {
	srand(seed);
	A.ordinate = rand() % 10 + 1;
	A.abscissa = rand() % 15 + 1;
	seed++;
}
class Circle {
private:
	coordinate O;
	int radius;
public:
	void createCircle(Circle& A);
	void showCircle(Circle);
	void perimeterCircle(Circle);
	void AreaCircle(Circle);
	void Enlarge(Circle& A,int percent);
	void ZoomOut(Circle& A, int percent);
	void Intersection(Circle, Circle);
};
void Circle::createCircle(Circle& A) {
	A.O.createCoordinate(A.O,seed);
	srand(seed);
	A.radius = rand() % 15+1;
}
void Circle::showCircle(Circle A) {
	A.O.showCoordinate(A.O);
	cout <<"Radius: " << A.radius << "\n";
}
void Circle::perimeterCircle(Circle A) {
	float perimeter;
	perimeter = 2 * pi * A.radius;
	cout << "\nPerimeter: " << perimeter<<"\n";
}
void Circle::AreaCircle(Circle A) {
	float area;
	area = pi * A.radius * A.radius;
	cout << "Area: " << area<<"\n";
}
void Circle::Enlarge(Circle& A,int percent) {
	float percentSS = percent * 0.01+1;
	A.radius *= percentSS;
}
void Circle::ZoomOut(Circle& A, int percent) {
	float percentSS = 1-percent * 0.01;
	A.radius *= percentSS;
}
void Circle::Intersection(Circle A, Circle B) {
	cout <<"distance A.O & B.O :" << (A.O, B.O).distanceCoordinate(A.O, B.O) << "\n";
	if ((A.O, B.O).distanceCoordinate(A.O, B.O) > (A.radius + B.radius)) cout << "Khong giao nhau";
	else cout << "giao nhau";
}
int main() {
	Circle As;
	As.createCircle(As);
	As.showCircle(As);
	As.perimeterCircle(As);
	As.AreaCircle(As);
	As.Enlarge(As, 40 );
	As.showCircle(As);
	As.ZoomOut(As, 40);
	As.showCircle(As);
	Circle Bs;
	cout << "\n-()-\n";
	Bs.createCircle(Bs);
	Bs.showCircle(Bs);
	(As, Bs).Intersection(As, Bs);
	return 0;
}