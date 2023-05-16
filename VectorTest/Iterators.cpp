#include"source.h"
void showVector(vector<int> A) {
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
}
void iterators() {
	vector<int>Vector;
	for (int i=0; i < base; i++) {
		Vector.push_back(i);
	}
	showVector(Vector);
	for (auto i = Vector.begin(); i != Vector.end(); ++i) {
		cout  << *i << " ";
	}
	for (auto i = Vector.cbegin(); i != Vector.cend(); ++i) {
		cout << *i << " ";
	}
	for (auto ir = Vector.rbegin(); ir != Vector.rend(); ++ir) {
		cout << *ir << " ";
	}
	for (auto ir = Vector.crbegin(); ir != Vector.crend(); ++ir) {
		cout << *ir << " ";
	}
}