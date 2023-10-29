#include<bits/stdc++.h>
using namespace std;

class SANPHAM {
	protected:
		string ten;
		int nam, gia;
	public:
		SANPHAM() {
			ten = "";
			nam = gia = 0;
		}
		SANPHAM(string ten, int nam, int gia) {
			this->ten = ten;
			this->nam = nam;
			this->gia = gia;
		}
		virtual void Nhap() {
			cout << "Ten san pham: ";cin.ignore(); getline(cin, ten);
			cout << "Nam san xuat: "; cin >> nam;
			cout << "Gia san pham: "; cin >> gia;
		}
		virtual void Xuat() {
			cout << ten << "-" << gia << "-" << nam;
		}
		virtual int tinhThanhtien() {
			return 0;
		}
		virtual int tinhLai(){
			return 0;
		}
};

class HOADON : public SANPHAM {
	protected:
		int soluong, giaban;
		int chenhLech = 0;
	public:
		HOADON() : SANPHAM() {
			soluong = giaban = 0;
		}
		HOADON(string ten, int nam, int gia, int sl, int giaban) : SANPHAM(ten, nam, gia) {
			this->soluong = sl;
			this->giaban = giaban;
		}
		void Nhap() {
			SANPHAM::Nhap();
			cout << "So luong ban: "; cin >> soluong;
			cout << "Gia ban: "; cin >> giaban;
			chenhLech = giaban - gia;
		}
		int tinhThanhtien() {
			return this->soluong * this->giaban;
		}
		int tinhLai() {
			return this->chenhLech * this->soluong;
		}
		void Xuat() {
			SANPHAM::Xuat();
			cout << "-" << soluong << "-" << giaban << "-" << tinhThanhtien() << "-" << tinhLai() << endl;		
		}
};

bool cmp(SANPHAM *a, SANPHAM *b) {
	return a->tinhLai() > b->tinhLai();
}

int main() {
	int n;
	cout << "Nhap danh sach san pham: "; cin >> n;
	vector<SANPHAM *> ds;
	
	for(int i = 0; i < n; i++) {
		SANPHAM *sanpham = new HOADON();
		sanpham->Nhap();
		ds.push_back(sanpham);
	}
	cout << "\nTruoc khi sap xep\n";
	for(int i = 0; i < n; i++) {
		cout << i <<". ";
		ds[i]->Xuat();
	}
	sort(ds.begin(), ds.end(), cmp);
	cout << "\nSau khi sap xep\n";
	for(int i = 0; i < n; i++) {
		cout << i <<". ";
		ds[i]->Xuat();
	}
	
	return 0;
}