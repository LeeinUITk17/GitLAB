#include<iostream>
#include<time.h>
#include<math.h>
#define ones 1
using namespace std;
class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h=0,int p=0,int s=0)
		:hour(h),minute(p),second(s)
	{}
	friend istream& operator>>(istream& in, Time& A);
	friend ostream& operator<<(ostream& on, Time& A);
	Time operator+(const Time& A);
	Time operator-(const Time& A);
	Time operator+(const int ss);
	Time operator-(const int ss);
	Time operator++(int ss);
	Time operator--(int ss);
	Time operator=(const Time& A);
};
istream& operator>>(istream& in, Time& A) {
	do {
		in >> A.hour;
	} while (A.hour <0 || A.hour > 23);
	do {
		in >> A.minute;
	} while (A.minute<0 || A.minute > 59);
	do {
		in >> A.second;
	} while (A.second < 0 || A.second > 59);
	return in;
}
ostream& operator<<(ostream& on, Time& A) {
	on << A.hour << ":" << A.minute << ":" << A.second;
	return on;
}
Time Time::operator=(const Time& A) {
	Time res;
	res.second = A.second;
	res.minute = A.minute;
	res.hour = A.hour;
	return res;
}
Time Time::operator+(const Time& A) {
	Time res;
	res.second = second + A.second;
	res.minute = minute + A.minute;
	res.hour = hour + A.hour;
	if (second > 59) {
		res.second -= 59;
		res.minute += 1;
	}
	if (minute > 59) {
		res.minute -= 59;
		res.hour += 1;
	}
	if (hour > 23) {
		res.hour -= 23;
	}
	return res;
}
Time Time::operator-(const Time& A) {
	Time res;
	res.second = second - A.second;
	res.minute = minute - A.minute;
	res.hour = hour - A.hour;
	if (second < 0) {
		res.second += 60;
		res.minute -= 1;
	}
	if (minute < 0) {
		res.minute += 60;
		res.hour -= 1;
	}
	if (hour < 0) {
		res.hour += 24;
	}
	return res;
}
Time Time::operator+(const int ss) {
	Time res;
	res.second = second + ss;
	if (second > 59) {
		res.second -= 59;
		res.minute += 1;
	}
	if (minute > 59) {
		res.minute -= 59;
		res.hour += 1;
	}
	if (hour > 23) {
		res.hour -= 23;
	}
	return res;
}
Time Time::operator-(const int ss) {
	Time res;
	res.second = second - ss;
	if (second < 0) {
		res.second += 60;
		res.minute -= 1;
	}
	if (minute < 0) {
		res.minute += 60;
		res.hour -= 1;
	}
	if (hour < 0) {
		res.hour += 24;
	}
	return res;
}
Time Time::operator++(int ss) {
	ss = ones;
	Time res;
	res.second += ss;
	if (second > 59) {
		res.second -= 59;
		res.minute += 1;
	}
	if (minute > 59) {
		res.minute -= 59;
		res.hour += 1;
	}
	if (hour > 23) {
		res.hour -= 23;
	}
	return res;
}
Time Time::operator--(int ss) {
	ss = ones;
	Time res;
	res.second -= ss;
	if (second < 0) {
		res.second += 60;
		res.minute -= 1;
	}
	if (minute < 0) {
		res.minute += 60;
		res.hour -= 1;
	}
	if (hour < 0) {
		res.hour += 24;
	}
	return res;
}
int main() {
	Time a,b(2,48,59);
	cout << "cau1\n";
	cin >> a;
	cout << "cau2\n";
	cout << a;
	Time c = (a + b);
	cout << "\ncau4:+\n";
	cout << c;
	Time d =(c - a);
	cout << "\ncau4:-\n";
	cout << d;
	b = (b + 10);
	cout << "\ncau3:+\n";
	cout << b;
	b =(b - 15);
	cout << "\ncau3:-\n";
	cout << b;
	b++;
	cout << "\ncau5:++\n";
	cout << b;
	b--;
	cout << "\ncau5:--\n";
	cout << b;
	return 0;
}