#include"Header.h"
#include"mixed.h"
int main() {
	mixed a;
	cout << "\n cau 2\n";
	cout << "nhap 1 hon so !! vd 5 2 3\n";
	/*
	input : 1 hon so 5 2 3 
	output: 5 & 2/3
	*/
	cin >> a;
	cout << a;
	cout << "\ncau 3\n";
	cout << "\ninput mixed is : " << a;
	cout << "\n>> " << a.MixedTofraction(a);
	/*
	intput: mixed a vd 5 & 2/3
	output: transfer mixed a to fraction vd 17/3 
	*/
	cout << "\ncau 4\n";
	cout << "nhap 1 phan so !! vd 17 3\n";
	fraction b;
	cin >> b;
	cout << "\ninput fraction is : " << b;
	cout << "\n>> " << a.FractionToMixed(b);
	/*
	intput: fraction b vd 17/3
	output: transfer fraction to mixed vd 5 & 2/3
	*/
	cout << "\nnhap 1 hon so !! vd 2 2 3\n";
	mixed c;
	cin >> c;
	cout << "\ncau 5\n";
	a.compare(a, c);
	/*
	intput: mixed a, mixed c vd 5 & 2/3 and 2 & 2/3
	output: mixed with the hightest value vd 5 & 2/3
	*/
	cout << "\ncau 6\n";
	a.operation(a, c);
	/*
	intput: mixed a, mixed c vd 5 & 2/3 and 2 & 2/3
	output:
Addition: 8 & 1/3
Subtraction: can not transfer fraction to mixed number !0 & 0/0 <when can not transfer after subtraction run...>
Multiplication: 15 & 1/9
Division: 2 & 1/8
	*/
	return 0;
}