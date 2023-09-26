#include <iostream>
using namespace std;

struct Baihat {
	int MaMH;
	string TenBH, Casi, Album;
};

Baihat *nhapBH(int &n, Baihat *m) {
	cout << "Nhap so luong bai hat: ";
	cin >> n;
	m = new Baihat[n];
	for(int i = 0; i < n; i++) {
		cout << "\nSong " << i+1 << endl;
		
		cout << "Ma bai hat: "; cin >> m[i].MaMH;
		cin.ignore();
		
		cout << "Ten bai hat: "; getline(cin, m[i].TenBH);
		
		cout << "Ca si: "; getline(cin, m[i].Casi);
		
		cout << "Album: "; getline(cin, m[i].Album);
	}
	return m;
}

void xuatBH(int n, Baihat *m) {
	cout << endl << "Danh sach bai hat vua nhap: \n";
	cout << "MaBH" << "\t" << "TenBH" << "\t" << "Ca si" << "\t" << "Album\n";
	for(int i = 0; i < n; i++) {
		cout << m[i].MaMH << "\t" << m[i].TenBH << "\t" << m[i].Casi << "\t" << m[i].Album << endl;
	}
}

void xoaBH(int &n, Baihat *&m) {
	if (n <= 0) {
		cout << "Danh sach sinh vien rong \n";
		return;
	}
	
	Baihat *temp = new Baihat[n - 1];
	
	for(int i = 1; i < n; i++) {
		temp[i - 1] = m[i];
	} 
	
	delete[] m;
	
	m = temp;
	
	n--;
}

void xuatBH2(int n, Baihat *m) {
	if(n == 0) {
		cout << "Danh sach trong\n";
		return;
	}
	cout << endl << "Danh sach bai hat sau khi xoa: \n";
	cout << "MaBH" << "\t" << "TenBH" << "\t" << "Ca si" << "\t" << "Album\n";
	for(int i = 0; i < n; i++) {
		cout << m[i].MaMH << "\t" << m[i].TenBH << "\t" << m[i].Casi << "\t" << m[i].Album << endl;
	}
}

int main() {
	int n;
	Baihat *m;
	m = nhapBH(n, m);
	xuatBH(n, m);
	
	xoaBH(n, m);
	xuatBH2(n ,m);
	
	delete[] m;
	
	return 0;
}