#include"Header.h"
#include"mixed.h"
int main() {
	mixed a;
	cin >> a;
	cout << a;
	cout << "\ninput mixed is : " << a;
	cout<<"\n>> " << a.MixedTofraction(a);
	fraction b;
	cin >> b;
	cout << "\ninput fraction is : " << b;
	cout << "\n>> " << a.FractionToMixed(b);
	mixed c;
	cin >> c;
	a.compare(a, c);
	a.operation(a,c);
	return 0;
}