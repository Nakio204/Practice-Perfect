#include <bits/stdc++.h>
using namespace std;

class NSX {
	private:
		string tenNsx, diaChi;
	public:
		string getTen1() {
			return this->tenNsx;
		}
		void setTen1(string ten) {
			ten = this->tenNsx;
		}
		string getDiachi() {
			return this->diaChi;
		}
		void setDiachi(string dc) {
			dc = this->diaChi;
		}
		void NHAP();
		void XUAT();
		friend class Hang;
};
class Date {
	private:
		int D, M, Y;
	public:
		void NHAP();
		void XUAT();
		friend class tivi;
};
class Hang {
	protected:
		string Tenhang;
		NSX x;
		float Dongia;
	public:
		void NHAP();
		void XUAT();
		Hang();
};
class tivi : public Hang {
	private:
		float Kichthuoc;
		Date NgayNhap;
	public:
		void NHAP();
		void XUAT();
		tivi();
};

void NSX::NHAP() {
	cout << "Ten: "; getline(cin, this->tenNsx);
	cout << "Dia chi: "; getline(cin, this->diaChi);
}
void NSX::XUAT(){
	cout << "NSX: " << this->tenNsx << endl;
	cout << "Dia chi: " << this->diaChi;
}

void Date::NHAP() {
	cout << "Day: "; cin >> this->D;
	cout << "Month: "; cin >> this->M;
	cout << "Year: "; cin >> this->Y;
}
void Date::XUAT() {
	cout << "Date: " << this->D << "/" << this->M << "/" << this->Y;
}

void Hang::NHAP() {
	cout << "Nhap ten hang: "; getline(cin, this->Tenhang);
	cout << "Nhap NSX: \n"; x.NHAP();
	cout << "Nhap gia: "; cin >> this->Dongia;
}
void Hang::XUAT() {
	cout << "Ten hang: " << this->Tenhang << endl;
	x.XUAT(); cout << endl;
	cout << "Don gia: " << this->Dongia << endl;
}

Hang::Hang() {
	this->Tenhang = "TV4K";
	x.tenNsx = "SONY";
	x.diaChi = "Ha Nam";
	this->Dongia = 450;
}

void tivi::NHAP(){
	Hang::NHAP();
	cout << "Kich thuoc tivi: "; cin >> this->Kichthuoc;
	NgayNhap.NHAP();
}
void tivi::XUAT(){
	Hang::XUAT();
	cout << "Kthuoc: " << this->Kichthuoc << endl;
	NgayNhap.XUAT();
}
tivi::tivi() {
	this->Kichthuoc = 32;
	NgayNhap.D = 1;
	NgayNhap.M = 1;
	NgayNhap.Y = 2012;
}

int main() {
	tivi x;
	x.NHAP();
	cout << endl;
	x.XUAT();
	
	
	return 0;
}