#include<bits/stdc++.h>
using namespace std;

class Nguoi {
	private:
		string ten;
		int namsinh;
	public:
		Nguoi() {
			ten = "";
			namsinh = 0;
		}
		Nguoi(string ten, int nam) {
			this->ten = ten;
			this->namsinh = nam;
		}
		int getNamsinh() {
			return this->namsinh;
		}
		virtual void Nhap() {
			cin.ignore();
			cout << "Ten benh nhan: "; getline(cin, this->ten);
			cout << "Nam sinh: "; cin >> namsinh;
		}
		virtual void Xuat() {
			cout << ten << "-" << namsinh;
		}
		virtual int thanhTien() {
			return 0;
		}
		virtual int tuoiHientai() {
			return 2023 - Nguoi::getNamsinh();
		}
};

class BENH_NHAN : public Nguoi {
	private:
		string tenbenh;
		int songay, vienphi;
	public:
		BENH_NHAN() : Nguoi() {
			tenbenh  = "";
			songay = vienphi = 0;
		}
		BENH_NHAN(string ten, int nam, string tenbenh, int ngay, int gia) : Nguoi(ten, nam) {
			this->tenbenh = tenbenh;
			this->songay = ngay;
			this->vienphi  = gia;
		}
		void Nhap() {
			Nguoi::Nhap();
			cin.ignore();
			cout << "Benh an: "; getline(cin, tenbenh);
			cout << "So ngay nam vien: "; cin >> songay;
			cout << "Vien phi: "; cin >> vienphi;
		}
		int tuoiHientai() {
			return 2023 - Nguoi::getNamsinh();
		}
		int thanhTien() {
			return this->songay * this->vienphi;
		}
		void Xuat() {
			Nguoi::Xuat();
			cout << "-" << tuoiHientai() << "-" << tenbenh << "-" << songay << "-" << vienphi << "-" << thanhTien() << endl;
		}
};

int main() {
	BENH_NHAN ds[100];
	int n;
	do {
		cout << "Nhap so luong benh nhan: ";
		cin >> n;
		if(n <=0 || n > 100) cout << "So luong khong hop le! Nhap lai." << endl;
	} while(n <= 0 || n > 100);
	
	for(int i = 0; i < n; i++) {
		ds[i].Nhap();
	}
	cout << "\nDanh sach benh nhan" << endl;
	for(int i = 0; i < n; i++) {
		cout << i << ". ";
		ds[i].Xuat();
	}
	cout << "\nDanh sach benh nhan >= 20 tuoi" << endl;
	for(int i = 0; i < n; i++) {
		if(ds[i].tuoiHientai() >= 20) {
			cout << i << ". ";
			ds[i].Xuat();			
		}
	}
	int vp = ds[0].thanhTien();
	int indx = 0;
	for(int i = 1; i < n; i++) {
		if(ds[i].thanhTien() > vp) {
			vp = ds[i].thanhTien();
			indx = i;
		}
	}
	cout << "\nBenh nhan co vien phi cao nhat: " << endl;
	ds[indx].Xuat();
	
	
	return 0;
}