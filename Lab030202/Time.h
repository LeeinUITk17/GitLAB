#pragma once
#include"Header.h"
class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time(int h=0, int p=0, int s=0)
		:hour(h), minute(p), second(s)
	{}
	friend istream& operator>>(istream& in, Time& A);
	friend ostream& operator<<(ostream& on, Time& A);
	Time operator+(Time const& A);
	Time operator-(Time const& A);
	Time operator+(int const& ss);
	Time operator-(int const& ss);
	Time operator++(int);
	Time operator--(int);
	void setaddition(Time& A);
	void setsubtraction(Time& A);
};