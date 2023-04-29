#include"Time.h";
istream& operator>>(istream& in, Time& A) {
	do {
		in >> A.hour;
	} while (A.hour < 0 || A.hour>23);
	do {
		in >> A.minute;
	} while (A.minute < 0 || A.minute>59);
	do {
		in >> A.second;
	} while (A.second < 0 || A.second>59);
	return in;
}
ostream& operator<<(ostream& on, Time& A) {
	on << A.hour << ":" << A.minute << ":" << A.second << ".";
	return on;
}
void Time::setaddition(Time& A) {
	do {
		if (A.second > 59) {
			A.second -= 60;
			A.minute++;
		}
		if (A.minute > 59) {
			A.minute -= 60;
			A.hour++;
		}
		if (A.hour > 23) {
			A.hour -= 24;
		}
	} while (A.second > 59 || A.minute > 59 || A.hour > 23);
}
void Time::setsubtraction(Time& A) {
	do {
		if (A.second < 0) {
			A.second += 60;
			A.minute--;
		}
		if (A.minute < 0) {
			A.minute += 60;
			A.hour--;
		}
		if (A.hour < 0) {
			A.hour += 24;
		}
	} while (A.second < 0 || A.minute < 0 || A.hour < 0);
}
Time Time::operator+(Time const& A) {
	Time res;
	res.hour = hour + A.hour;
	res.minute = minute + A.minute;
	res.second = second + A.second;
	res.setaddition(res);
	return res;
}
Time Time::operator-(Time const& A) {
	Time res;
	res.hour = hour - A.hour;
	res.minute = minute - A.minute;
	res.second = second - A.second;
	res.setsubtraction(res);
	return res;
}
Time Time::operator+(int const&ss) {
	Time res;
	res.second = second + ss;
	res.minute = minute;
	res.hour = hour;
	res.setaddition(res);
	return res;
}
Time Time::operator-(int const&ss) {
	Time res;
	res.second = second - ss;
	res.minute = minute;
	res.hour = hour;
	res.setsubtraction(res);
	return res;
}
Time Time::operator++(int) {
	Time res = *this;
	res.second = second + 1;
	res.minute = minute;
	res.hour = hour;
	res.setaddition(res);
	return res;
}
Time Time::operator--(int) {
	Time res = *this;
	res.second = second - 1;
	res.minute = minute;
	res.hour = hour;
	res.setsubtraction(res);
	return res;
}