#include <bits/stdc++.h>
using namespace std;

class ncc {
	private:
		string ma, ten, diachi;
	public:
		void Nhap(){
			fflush(stdin);
			cout << "Ma NCC: "; getline(cin, this->ma);
			cout << "Ten NCC: "; getline(cin, this->ten);
			cout << "Dia chi: "; getline(cin, this->diachi);
		}
		void Xuat() {
			cout << "Ma NCC: " << this->ma << setw(27) << "Ten NCC: " << this->ten << endl << "Dia chi: " << this->diachi << endl;
		}
};

class Hang{
	private:
		string ten;
		float gia;
		int sl;
		double thanhtien;
	public:
		void Nhap() {
			fflush(stdin);
			cout << "Ten don hang: "; getline(cin, this->ten);
			cout << "Don gia: "; cin >> this->gia;
			cout << "So luong: "; cin >> this->sl;
			this->thanhtien = this->sl * this->gia;
		}
		void Xuat() {
			cout << this->ten << setw(20) << this->gia << setw(20) << this->sl << setw(20) << this->thanhtien << endl; 
		}
		float getGia() {
			return this->gia;
		}
		int getSl() {
			return this->sl;
		}
		double getThanhtien() {
			return this->thanhtien;
		}
};

class Phieu {
	private:
		string maphieu, date;
		ncc x;
		Hang *y;
		int n;
	public:
		void Nhap(){
			cout << "Ma phieu: "; getline(cin, this->maphieu);
			cout << "Ngay lap: "; getline(cin, this->date);
			x.Nhap();
			cin >> n;
			y = new Hang[n];
			for(int i = 0; i < n; i++) {
				y[i].Nhap();
			}
		}
		void Xuat() {
			cout << "\nMa phieu: " << this->maphieu << setw(25) << "Ngay lap: " << this->date << endl;
			x.Xuat();
			cout << "\nTen hang" << setw(20) << "Don gia" << setw(20) << "So luong" << setw(20) << "Thanh tien\n";
			for(int i = 0; i < n; i++) {
				y[i].Xuat();
			}
			float tong = 0.0;
			for(int i = 0; i < n; i++) {
				tong += y[i].getThanhtien();
			}
			cout << setw(60) << "Cong thanh tien: " << tong << endl;
		}
};

int main() {
	Phieu x;
	x.Nhap();
	cout << "====================PHIEU NHAP HANG====================\n";
	x.Xuat();
	
		
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	return 0;
}