#include <bits/stdc++.h>
using namespace std;

class Phieu;

class Sinhvien {
	private:
		string id, name, lop, khoa;
	public:
		void Nhap() {
			fflush(stdin);
			cout << "Ma sinh vien: "; getline(cin, this->id);
			cout << "Ten sinh vien: "; getline(cin, this->name);
			cout << "Lop: "; getline(cin, this->lop);
			cout << "Khoa: "; getline(cin, this->khoa);
		}
		void Xuat() {
			cout << "\nMa sinh vien: " << this->id << setw(25) << "Ten sinh vien: " << this->name << endl;
			cout << "Lop: " << this->lop << setw(23) << "Khoa: " << this->khoa << endl;
		}
};

class Monhoc {
	private:
		string ten;
		int trinh;
		float diem;
	public:
		void Nhap() {
			fflush(stdin);
			cout << "Ten mon: "; getline(cin, this->ten);
			cout << "So trinh: "; cin >> this->trinh;
			cout << "Diem: "; cin >> this->diem;
		}
		void Xuat() {
			cout << this->ten << "\t\t\t" << this->trinh << "\t\t" << this->diem << endl;
		}
		int getTrinh() {
			return this->trinh;
		}
		float getDiem() {
			return this->diem;
		}
		string getTen() {
			return this->ten;
		}
		friend void xuatTrinh(Phieu a);
		friend void chen(Phieu &a);
		friend void xoa(Phieu &a);
};

class Phieu {
	private:
		Sinhvien x;
		Monhoc y[20];
		int n;
	public:
		void Nhap() {
			x.Nhap();
			cout << "Nhap so luong mon hoc: "; cin >> this->n;
			for(int i = 0; i < n; i++) {
				y[i].Nhap();
			}
		}
		void Xuat() {
			cout << "=======================PHIEU BAO DIEM=====================\n";
			x.Xuat();
			cout << "\nBang diem:\n";
			cout << "   Ten mon" << setw(27) << "So trinh" << setw(15) << "Diem\n"; 
			for(int i = 0; i < n; i++) {
				y[i].Xuat();
			}
			int sumTrinh = 0;
			float sumDiem = 0.0;
			for(int i = 0; i < n; i++) {
				sumTrinh += y[i].getTrinh();
				sumDiem += y[i].getDiem() * y[i].getTrinh();
			}
			cout << setw(47) << "Diem trung binh: " << fixed << setprecision(2) << sumDiem / sumTrinh << endl;
		}
		friend void xuatTrinh(Phieu a);
		friend void chen(Phieu &a);
		friend void xoa(Phieu &a);
};

void xuatTrinh(Phieu a) {
	for(int i = 0; i < a.n; i++) {
		if(a.y[i].getTrinh() > 3) a.y[i].Xuat();
	}
}

void chen(Phieu &a) {
	int k;
	do {
		cout << "Nhap vi tri can chen: "; cin >> k;
	} while(k < 0 || k > a.n);
	Monhoc New;
	cout << "Nhap thong tin mon moi:\n";
	New.Nhap();
	for(int i = a.n; i > k; i--) {
		a.y[i] = a.y[i - 1];
	}
	a.y[k] = New;
	a.n++;
}

void xoa(Phieu &a) {
	int k;
	do {
		cout << "Nhap vi tri can xoa: "; cin >> k;
	} while(k < 0 || k > a.n);
	for(int i = k; i < a.n; i++) {
		a.y[i] = a.y[i + 1];
	}
	a.n--;
}

int main() {
	Phieu x;
	x.Nhap();
	x.Xuat();
	xuatTrinh(x);
	chen(x);
	x.Xuat();
	xoa(x);
	x.Xuat();

	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	return 0;
}