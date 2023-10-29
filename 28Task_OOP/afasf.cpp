#include <iostream>

using namespace std;

class PhanSo{
	private:
		int tu, mau;
	public:
		PhanSo(){
			this->tu = 0;
			this->mau = 1;
		}
		PhanSo(int t, int m){
			tu = t;
			mau = m;
		}
		void nhap();
		void xuat();
		
		PhanSo operator + (PhanSo &);
		friend PhanSo operator - (PhanSo &, PhanSo &);		
};

void PhanSo::nhap(){
	cin >> this->tu;
	cin >> this->mau;
}

void PhanSo::xuat(){
	cout << this->tu << "/" << this->mau;
}

PhanSo PhanSo::operator + (PhanSo &b){
	PhanSo tong;
	tong.tu = this->tu * b.mau + b.tu * this->mau;
	tong.mau = this->mau * b.mau;
	return tong;
}

PhanSo operator - (PhanSo &a,PhanSo &b){
	PhanSo hieu;
	hieu.tu = a.tu * b.mau - b.tu * a.mau;
	hieu.mau = a.mau * b.mau;
	return hieu;
}

int main(){
	PhanSo a, b;
	a.nhap();
	b.nhap();
	PhanSo c = a + b;
	cout << "Tong hai phan so: "; c.xuat();
	
	PhanSo d = a - b;
	cout << "\nHieu hai phan so: "; d.xuat();
	
	
	
	return 0;
}