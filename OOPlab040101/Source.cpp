#include"Header.h"
#include"employee.h"
int main() {
	company A;
	A.setupCompany(A);
	int mode;
	cout << "\t===select mode==\n";
	cout << "\n enter 1: cau 2, cau 3";
	cout << "\n enter 2: cau 4";
	cout << "\n enter 3: cau 5";
	cout << "\n enter 4: cau 6";
	cout << "\n enter 5: cau 7";
	cout << "\n enter 6: cau 8\n";
	cin >> mode;
	switch (mode)
	{
	case 1: {
		A.Infmember(A);
		break;
	}
	case 2: {
		long long id, newBase, idupdate;
		cout << "enter ID : ";
		cin >> id;
		A.searchID(A, id);
		break;
	}
	case 3: {
		long long newBase, idupdate;
		A.updateBaseS(A, idupdate, newBase);
		cout << "\n>> check <<\n";
		A.searchID(A, idupdate);
		break;
	}
	case 4: {
		A.maxBill(A);
		break;
	}
	case 5: {
		A.minProduct(A);
		break;
	}
	case 6: {
		A.Bill10s(A);
		break;
	}
	default:
		break;
	}
	return 0;
}