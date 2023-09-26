#include <iostream>

using namespace std;

class VanDongVien{
	private:
		string hoten, monthidau;
		int tuoi;
		float cannang, chieucao;
	public:
		void nhap();
		void xuat();		
};

void VanDongVien::nhap(){
	cout << "Ho ten: "; getline(cin, hoten);
	cout << "Tuoi: "; cin >> tuoi; cin.ignore();
	cout << "Mon thi dau: ";getline(cin, monthidau);
	cout << "Can nang: "; cin >> cannang;
	cout << "Chieu cao: "; cin >> chieucao;	
	cin.ignore();
}

void VanDongVien::xuat(){
	cout << hoten << "\t" << tuoi << "\t" << monthidau << "\t\t" << cannang << "\t\t" << chieucao << endl ;
}

int main(){
	VanDongVien a[1000];
	
	int n;
	cout << "Nhap so luong: "; cin >> n;
	cin.ignore();
	
	for(int i = 0; i < n; i++) {
		a[i].nhap();
	}
	
	cout << "Ho ten\t" << "Tuoi\t" << "Mon thi dau\t" << "Can nang\t" << "Chieu cao" << endl;
	for(int i = 0; i < n; i++) {
		a[i].xuat();
	}
		
	return 0;
}