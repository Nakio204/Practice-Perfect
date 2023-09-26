#include <iostream>
using namespace std;

int *nhap(int *a, int &n) {
	cout << "Nhap so luong phan tu: "; cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++) {
		cout << "a[" << i + 1 << "] = ";
		cin >> *(a + i);
	}
	return a;
}

void xuat(int *a, int n) {
	cout << "Mang vua nhap la:";
	for(int i = 0; i < n; i++) {
		cout << " " << *(a + i);
	}
}

int main(){
	int *a, n;
	a = nhap(a, n);
	xuat(a, n);

	return 0;
}