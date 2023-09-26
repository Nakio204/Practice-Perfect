#include <iostream>
using namespace std;

void inputList(int a[], int &n) {
	do {
		cout << "Nhap n = ";
		cin >> n;
	} while(n <= 0 || n >= 50);
	
	for(int i = 0; i < n; i++) {
		cout << "a[" << i + 1 << "] = ";
		cin >> a[i];
	}
}

void insertLast(int a[], int &n, int &x) {
	cout << "\nCho x: ";
	cin >> x;
	a[n] = x;
	n++;
	cout << "Chen x vao cuoi danh sach!\n";
	cout << "\nDanh sach:";
	for(int i = 0; i < n; i++) {
		cout << " " << a[i];
	}
}

void outputList(int a[], int n) {
	cout << "\nDanh sach:";
	for(int i = 0; i < n; i++) {
		cout << " " << a[i];
	}
}

void sapXep(int a[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[j] < a[i]) swap(a[i], a[j]);
		}
	}
	
	cout << "\n\nDanh sach sau khi sap xep:";
	for(int i = 0; i < n; i++) {
		cout << " " << a[i];
	}
}

int main() {
	int a[100], n, x;
	
	inputList(a, n);
	outputList(a, n);
	
	insertLast(a, n, x);
	
	sapXep(a, n);
	
	return 0;
}