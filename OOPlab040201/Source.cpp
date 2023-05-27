#include"Header.h"
#include"college.h"
int main() {
	college UIT;
	UIT.setupCollege(UIT);
	int mode;
	cout << "\t===select mode==\n";
	cout << "\n enter 1: cau 2";
	cout << "\n enter 2: cau 3,4,5";
	cout << "\n enter 3: cau 6";
	cout << "\n enter 4: cau 7\n";
	cout << "enter : ";
	cin >> mode;
	switch (mode)
	{
	case 1: {
		UIT.InfStudent(UIT);
		break;
	}
	case 2: {
		UIT.graduation(UIT);
		break;
	}
	case 3: {
		UIT.minAverage(UIT);
		break;
	}
	case 4: {
		UIT.maxAverage(UIT);
		break;
	}
	default:
		break;
	}
	return 0;
}