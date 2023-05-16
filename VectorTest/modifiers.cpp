#include"source.h"
void showVector(vector<int> A) {
	cout << "\n";
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
}
void modifiers() {
	//srand(time(NULL));
	vector<int> Vector;
	for (int i = 0; i < base; i++) {
		Vector.push_back(i);
	}
	showVector(Vector);
	for (int i = 0; i < base; i++) {
		srand(i);
		Vector.push_back((int)rand()% 1001);
	}
	int n = 10;
	showVector(Vector);
	Vector.pop_back();
	showVector(Vector);
	Vector.insert(Vector.end(),n);
	showVector(Vector);
	//Vector.erase(Vector.end());
	//Vector.erase(Vector.begin(), Vector.begin());
	Vector.erase(Vector.begin());
	showVector(Vector);
	Vector.emplace(Vector.begin(),n);
	Vector.emplace_back(n);
	showVector(Vector);
	vector<int>non_Vector;
	Vector.swap(non_Vector);
	showVector(non_Vector);
	non_Vector.clear();
	showVector(non_Vector);
}
