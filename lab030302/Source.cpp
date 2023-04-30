#include"employee.h"
#include"Header.h"
int main() {
	company UIT;
	UIT.setupCompany(UIT);
	UIT.InfEmployee(UIT);
	long long id;
	cin >> id;
	UIT.searchID(UIT, id);
	UIT.updateSalary(UIT, id, 5000000);
	UIT.find10sBill(UIT);
	UIT.maxBill(UIT);
	UIT.minProduct(UIT);
	return 0;
}