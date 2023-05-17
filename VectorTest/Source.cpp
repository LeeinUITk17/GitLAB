#include"Header.h"
#include"source.h"
int main() {
	cout << "\n===============Vector attribute=============\n";
	cout << "\nenter 1: modifiers test..\n";
	cout << "\nenter 2: capacity test..\n";
	cout << "\nenter 3: iterators test..\n";
	cout << "\nenter 4: element access test..\n";
	int mode;
	cout << "enter your select : ";
	cin >> mode;
	switch (mode)
	{
	case 1: 
	{
		modifiers();
		break;
	}
	case 2:
	{
		capacity();
		break;
	}
	case 3:
	{
		iterators();
		break;
	}
	case 4:
	{
		element_Access();
		break;
	}
	default:
		break;
	}
	return 0;
}