#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;
class Time {
private: 
	int hour;
	int minute;
	int second;
public:
	Time(int h=0, int p=0, int s=0)
		:hour(h),minute(p),second(s)
	{}
	friend istream& operator>>(istream& in, Time& A);
	friend ostream& operator<<(ostream& on, Time& A);
	Time operator+(const Time& A);
	Time operator-(const Time& A);
	Time operator+(int ss);
	Time operator-(int ss);
	/*Time operator++();
	Time operator--();*/
	
};
istream& operator>>(istream& in, Time& A) {
	in >> A.hour;
	do {
		in >> A.minute;
	} while (A.minute < 1 || A.minute>59);
	do {
		in >> A.second;
	} while (A.second < 1 || A.second>59);
	return in;
}
ostream&operator<<(ostream& on,Time&A){
	on << A.hour << ":" << A.minute << ":" << A.second;
	return on;
}
//Time Time::operator++() {
//	Time res;
//	res.second = second + 1;
//	res.minute = minute;
//	res.hour = hour;
//	if (second > 59) {
//		res.second = 1;
//		res.minute += 1;
//	}
//	if (minute > 59) {
//		res.minute = 1;
//		res.hour += 1;
//	}
//	return res;
//}
//Time Time::operator--() {
//	Time res;
//	res.second = second - 1;
//	res.minute = minute;
//	res.hour = hour;
//	if (res.second < 0) {
//		res.minute -= 1;
//		res.second = abs(res.second);
//	}
//	if (res.minute < 0) {
//		res.hour -= 1;
//		res.minute = abs(res.minute);
//	}
//	if (res.hour < 0) return NULL;
//	return res;
//}
Time Time::operator+(int ss) {
	Time res;
	res.second = second + ss;
	res.minute = minute;
	res.hour = hour;
	if (res.second > 59) {
		res.second = 1;
		res.minute += 1;
	}
	if (res.minute > 59) {
		res.minute = 1;
		res.hour += 1;
	}
	return res;
}
Time Time::operator-(int ss) {
	Time res;
	res.second = second - ss;
	res.minute = minute;
	res.hour = hour;
	if (res.second < 0) {
		res.minute -= 1;
		res.second = abs(res.second);
	}
	if (res.minute < 0) {
		res.hour -= 1;
		res.minute = abs(res.minute);
	}
	if (res.hour < 0) return NULL;
	return res;
}
Time Time::operator+(const Time& A) {
	Time res;
	res.second = second + A.second;
	res.minute = minute + A.minute;
	res.hour = hour + A.hour;
	if (res.second > 59) {
		res.second = 1;
		res.minute += 1;
	}
	if (res.minute > 59) {
		res.minute = 1;
		res.hour += 1;
	}
	return res;
}
Time Time::operator-(const Time& A) {
	Time res;
	res.second = second - A.second;
	res.minute = minute - A.minute;
	res.hour = hour - A.hour;
	if (res.second < 0) {
		res.minute -= 1;
		res.second = abs(res.second);
	}
	if (res.minute < 0) {
		res.hour -= 1;
		res.minute = abs(res.minute);
	}
	if (res.hour < 0) return NULL;
	return res;
}
int main() {
	Time A;
	cin >> A;
	cout << A<<"\n";
	A + 12;
	cout << A<<"\n";
	A - 34;
	cout << A<<"\n";
	Time B;
	B = A - 101;
	Time C;
	C = A + B;
	cout << C<<"\n";
	/*C++;
	cout << C<<"\n";
	C--;
	cout << C<<"\n";*/
	return 0;
}