// overload_date.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

class Date
{
    int mo, da, yr;
public:
    Date(int d = 0, int m = 0, int y = 0)
        :da(d), mo(m), yr(y)
    {}
    friend ostream& operator<<(ostream& os, const Date& dt);
    friend istream& operator>>(istream& in, Date& dt);
    friend class birth;
    void tomorrow(Date &a);
};
ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.da << '/' << dt.mo << '/' << dt.yr;
    return os;
}
void Date::tomorrow( Date &a) {
    if (a.da == 28 && a.mo == 2) {
        a.da = 1;
        a.mo++;
    }
    else  if ((a.da == 30 && a.mo % 2 != 0) || (a.da == 31 && a.mo % 2 == 0)) {
        a.da = 1;
        a.mo++;
    }
    else a.da++;
    
}
istream& operator>>(istream& in, Date& dt) {
    in >> dt.da;
    cout << endl;
    in >> dt.mo;
    cout << endl;
    in >> dt.yr;
    return in;
}
class birth :public Date
{
private:
    Date birthDa;
public:
    birth(Date sn)
        :birthDa(sn)
    {}
    void show() { cout << birthDa; }
};
int main()
{
    Date dt;
    cin >> dt;
    //cout << dt;
    birth sn(dt);
    sn.show();
    cout << endl;
    sn.tomorrow(sn);
    return 0;
}