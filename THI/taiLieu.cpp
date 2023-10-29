#include <bits/stdc++.h>
using namespace std;

class taiLieu {
	private:
		string ten;
		int nam, gia;
	public:
		taiLieu(){
			ten = "";
			nam = gia = 0;
		}
		taiLieu(string te, int nam, int gia) {
			this->ten = te;
			this->nam = nam;
			this->gia = gia;
		}
		virtual void Nhap() {
			cin.ignore();
			cout << "Nhap ten tai lieu: "; getline(cin, ten);
			cout << "Nam san xuat: "; cin >> nam;
			cout << "Gia tai lieu: "; cin >> gia;
		}
		virtual void Xuat() {
			cout << ten << "-" << nam << "-" << gia;
		}
		virtual int thanhTien() {
			return 0;
		}
};

class sach : public taiLieu  {
	private:
		int soluong, giaban;
	public:
		sach() : taiLieu() {
			soluong = giaban = 0;
		} 
		sach(string ten, int nam, int gia, int soluong, int giaban) : taiLieu(ten, nam, gia) {
			this->soluong = soluong;
			this->giaban = giaban;
		}
		void Nhap() {
			taiLieu::Nhap();
			cout << "Nhap so luong: "; cin >> soluong;
			cout << "Gia ban: "; cin >> giaban;
		}
		int thanhTien() {
			return this->soluong * this->giaban;
		}
		void Xuat() {
			taiLieu::Xuat();
			cout << "-" << soluong << "-" << giaban << "-" << thanhTien() << endl;
		}
};

bool cmp(taiLieu a, taiLieu b) {
	return a.thanhTien() < b.thanhTien();
}

int main() {
	sach ds[100];
	int n;
	cout << "Nhap N phan tu: "; cin >> n;
	for(int i = 0; i < n; i++) {
		ds[i].Nhap();
	}cout << endl;
	for(int i = 0; i < n; i++) {
		cout << i << ". ";
		ds[i].Xuat();
	}
	
	sort(ds, ds + n, cmp);
	
	cout << "\nSau khi sap xep theo thanh tien tang dan" << endl;
	for(int i = 0; i < n; i++) {
		cout << i << ". ";
		ds[i].Xuat();
	}
	
	int maxIndx = 0;
	int maxsl = ds[0].thanhTien();
	for(int i = 1; i < n; i++) {
		if(ds[i].thanhTien() > maxsl) {
			maxsl = ds[i].thanhTien();
			maxIndx = i;
		} 
	}
	cout << "\nThong tin tai lieu co so luong ban nhieu nhat: \n";
	ds[maxIndx].Xuat();
	
	return 0;
}