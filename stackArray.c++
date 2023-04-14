//Stack Array 1 row
#include <iostream>
#include<time.h>
#define max 10
using namespace std;
struct stack {
	int a[max];
	int t;// t is index save pos of last value in array
};
void createStack(stack& s) {
	s.t = -1;
}
int isEmpty(stack s) {
	if (s.t == -1) return 1;
	else return 0;
}
int isFull(stack s) {
	if (s.t >= max) return 1;
	else return 0;
}
int push(stack& s, int x) {
	if (isFull(s) == 0) {
		s.t++;
		s.a[s.t] = x;
		return 1;
	}
	return 0;
}
int pop(stack& s, int& x) {
	// int x is variable save value after delete call
	if (isEmpty(s) == 0) {
		x == s.a[s.t];
		s.t--;
		return 1;
	}
	return 0;
}
int top(stack s) {
	return s.a[s.t];
}
void print (stack s) {
	for (int i = 0; i < max; i++) {
		cout << top(s) << " ";	
		s.t--;
	}
}
int main() {
	stack ss;
	createStack(ss);
	int x;
	srand(time(NULL));
	for (int i = 0; i < max; i++) {
		x = rand() % 100;
		push(ss, x);
	}
	print(ss);
	//cout <<"++\n" << ss.t;
	return 0;
}