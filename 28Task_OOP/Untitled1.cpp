#include <iostream>
#include <iomanip>
using namespace std;
using ll = long long;

//ll gcd(ll a, ll b) {
//	if(b == 0) return a;
//	return gcd(b, a % b);
//}
//
//class PhanSo {
//	private:
//		ll tu, mau;
//	public:
//		PhanSo() {this->tu = 1; this->mau = 1;}
//		PhanSo(ll t, ll m) {this->tu = t;this->mau = m;}
//		~PhanSo() {}
//		friend istream & operator >> (istream &, PhanSo &);
//		friend ostream & operator << (ostream &, PhanSo);
//		friend PhanSo operator + (PhanSo, PhanSo);
//		void rutgon();
//};
//
//istream & operator >> (istream &in, PhanSo &a) {
//	in >> a.tu >> a.mau;
//	return in;
//}
//
//ostream & operator << (ostream &out, PhanSo a) {
//	out << a.tu << "/" << a.mau << endl;
//	return out; 
//}
//
//void PhanSo::rutgon() {
//	ll g = gcd(tu, mau);
//	tu /= g;
//	mau /= g;
//}
//
//PhanSo operator +(PhanSo a, PhanSo b) {
//	PhanSo res;
//	res.tu = a.tu * b.mau + b.tu * a.mau;
//	res.mau = a.mau * b.mau;
//	ll g = gcd(res.tu, res.mau);
//	res.tu /= g;
//	res.mau /= g;
//	return res;
//}
//
//int main() {
//	PhanSo p(1, 1), q(1, 1);
//	cin >> p >> q;
//	cout << p + q;
//	
//	return 0;
//}

class SinhVien {
	private:
		string id, name, lop, date;
		float gpa;
	public:
		SinhVien() {this->name = this->lop = this->date = "";this->gpa = 0.0;}
		SinhVien(string name, string lop, string date, float gpa) {
			this->name = name;
			this->lop = lop;
			this->date = date;
			this->gpa = gpa;
		}
		friend void Nhap(SinhVien &);
		friend void Xuat(SinhVien);
};

void Nhap(SinhVien &a){
	a.id = "B20DCCN001";
	getline(cin, a.name);
	getline(cin, a.lop);
	getline(cin, a.date);
	cin >> a.gpa;
	if(a.date[2] != '/') a.date.insert(0, "0");
	if(a.date[5] != '/') a.date.insert(3, "0"); 
}

void Xuat(SinhVien a) {
	cout << a.id << " " << a.name << " " << a.lop << " " << a.date << " " << fixed << setprecision(2) << a.gpa;
}

#define a() a
int main() {
	SinhVien a();
	Nhap(a);
	Xuat(a);
	
	
	return 0;
}