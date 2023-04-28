#include"Header.h"
#include"Time.h"
int main() {
	Time A, B(12, 18, 40);
	cin >> A;
	cout << A;
	Time C = A + B;
	cout << endl << C;
	Time D = C - A;
	cout << endl << D;
	D = D + 15;
	cout << endl << D;
	D = D - 11;
	cout << endl << D;
	/*D=D++;
	cout << endl << D;
	D=D--;
	cout << endl << D;*/
	return 0;
}
