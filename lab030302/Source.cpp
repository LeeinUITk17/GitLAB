#include"employee.h"
#include"Header.h"
int main() {
	company UIT;
	//cau 1 tao du lieu nhan vien, cau 3 tinh luong nhan vien
	/*
	input: company UIT
	output: create information for company UIT 
	call void company::setupCompany(company& A)
	call void randomInf(office& A, int seed);
	call void randomInf(factory& A, int seed);
	call void setSalary(office& A);
	call void setSalary(factory& A);
	call void bonus(office& A);
	call void bonus(factory& A);
	*/
	UIT.setupCompany(UIT);
	cout << "cau 2: xuat du lieu nhan vien company UIT\n";
	/*
	input: company UIT
	output: show information of company 
	call void InfEmployee(company);
	*/
	UIT.InfEmployee(UIT);
	long long id;
	cin >> id;
	cout << "\n cau 4: tim ma nhan vien theo ID\n";
	/*
	input: company UIT, long long id
	output:
	information of employee have this ID...
	call void searchID(company, long long id);
	call void showoff(office A); || void showoff(factory A);
	*/
	UIT.searchID(UIT, id);
	cout << "\n cau 5: update luong co ban\n";
	/*
	input: company UIT,long long id, long long <new> BaseSalary
	output:
	replace base salary of employee have this ID..
	call void setSalary(office& A); || call void setSalary(factory& A);
	call void showoff(office A); || void showoff(factory A);
	*/
	UIT.updateSalary(UIT, id, 5000000);
	cout << "\n cau 8: tim 10 nhan vien co luong cao nhat\n ";
	/*
	input: company UIT;
	output:
    show 10 employees have bill highest from them...
	call void selectionSort(company& A);
	call void find10sBill(company A);
	*/
	UIT.find10sBill(UIT);
	cout << "\n cau 6 : tim nhan vien co luong cao nhat\n";
	/*
	input: company UIT
	output:
	show employee have max bill..
	call void maxBill(company A);<call after called void selectionSort(company& A); >
	*/
	UIT.maxBill(UIT);
	cout << "\n cau 7: tim nhan vien ban duoc so san pham thap nhat\n";
	/*
	input: compant UIT
	output:
	show employee have min products..
	call void minProduct(company A);
	*/
	UIT.minProduct(UIT);
	return 0;
}