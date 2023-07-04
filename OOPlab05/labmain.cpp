#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 0, int m = 0, int y = 0)
        : day(d), month(m), year(y) {}

    void showDate() {
        cout << day << "/" << month << "/" << year;
    }

    void randomInfo(int seed) {
        srand(seed);
        day = rand() % 30 + 1;
        month = rand() % 12 + 1;
        year = 1980 + rand() % 40;
    }
};

class Human {
private:
    string fullName;
    Date birthDate;
    long long ID;
    string address;

public:
    Human(string name = "", Date birth = Date(), long long id = 0, string addr = "")
        : fullName(name), birthDate(birth), ID(id), address(addr) {}

    void showHuman() {
        cout << "Full Name: " << fullName << endl;
        cout << "Birth Date: ";
        birthDate.showDate();
        cout << endl;
        cout << "ID: " << ID << endl;
        cout << "Address: " << address << endl;
    }

    void randomInfo(int seed) {
        srand(seed);
        string names[10] = { "John", "Alice", "Michael", "Emma", "William", "Olivia", "James", "Sophia", "Benjamin", "Ava" };
        string surnames[10] = { "Smith", "Johnson", "Williams", "Brown", "Jones", "Miller", "Davis", "Garcia", "Wilson", "Taylor" };

        int nameIndex = rand() % 10;
        int surnameIndex = rand() % 10;

        fullName = surnames[surnameIndex] + " " + names[nameIndex];
        birthDate.randomInfo(seed);
        ID = 10000000000 + rand() % 1000000000;
        address = "Street " + to_string(rand() % 100) + ", City";
    }
};

class Certificate {
protected:
    Human owner;
    int plot;
    int maps;
    string plotAddress;
    float area;
    Date dateOfIssue;
    long long rentalRate;
    long long tax;

public:
    Certificate(Human own, int p = 0, int m = 0, string addr = "", float ar = 0, Date doi = Date(), long long rate = 0)
        : owner(own), plot(p), maps(m), plotAddress(addr), area(ar), dateOfIssue(doi), rentalRate(rate), tax(0) {}

    void setTax() {
        tax = area * rentalRate;
    }

    void showCertificate() {
        cout << "Owner Information:" << endl;
        owner.showHuman();
        cout << "Plot: " << plot << endl;
        cout << "Maps: " << maps << endl;
        cout << "Plot Address: " << plotAddress << endl;
        cout << "Area: " << area << endl;
        cout << "Date of Issue: ";
        dateOfIssue.showDate();
        cout << endl;
        cout << "Tax: " << tax << endl;
        cout << "Rental Rate: " << rentalRate << endl;
    }
};

class ResidentialLand : public Certificate {
public:
    ResidentialLand(Human own, int p = 0, int m = 0, string addr = "", float ar = 0, Date doi = Date(), long long rate = 0)
        : Certificate(own, p, m, addr, ar, doi, rate) {}

    void show() {
        cout << "Residential Land Certificate" << endl;
        showCertificate();
    }
};

class FarmLand : public Certificate {
private:
    Date leaseTerm;

public:
    FarmLand(Human own, int p = 0, int m = 0, string addr = "", float ar = 0, Date doi = Date(), long long rate = 0, Date lease = Date())
        : Certificate(own, p, m, addr, ar, doi, rate), leaseTerm(lease) {}

    void show() {
        cout << "Farm Land Certificate" << endl;
        showCertificate();
        cout << "Lease Term: ";
        leaseTerm.showDate();
        cout << endl;
    }
};

class Land {
private:
    vector<Certificate*> certificates;

public:
    ~Land() {
        for (Certificate* cert : certificates) {
            delete cert;
        }
    }

    void addCertificate(Certificate* cert) {
        certificates.push_back(cert);
    }

    void showAllCertificates() {
        for (Certificate* cert : certificates) {
            cert->show();
            cout << endl;
        }
    }
};

int main() {
    srand(time(0));

    Land land;

    // Create 10 ResidentialLand objects
    for (int i = 0; i < 10; ++i) {
        Human owner;
        owner.randomInfo(i);

        ResidentialLand* residentialLand = new ResidentialLand(owner, i + 1, i + 1, "Address " + to_string(i + 1), (i + 1) * 100.0, Date(), 5000);
        residentialLand->setTax();

        land.addCertificate(residentialLand);
    }

    // Create 10 FarmLand objects
    for (int i = 0; i < 10; ++i) {
        Human owner;
        owner.randomInfo(i + 10);

        FarmLand* farmLand = new FarmLand(owner, i + 1, i + 1, "Address " + to_string(i + 1), (i + 1) * 100.0, Date(), 10000, Date());

        farmLand->setTax();
        land.addCertificate(farmLand);
    }

    land.showAllCertificates();

    return 0;
}
