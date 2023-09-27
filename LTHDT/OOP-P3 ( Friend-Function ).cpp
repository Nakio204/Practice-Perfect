#include <bits/stdc++.h>
using namespace std;

class SinhVien; // Pre - declaration

class GiaoVien {
	private:
		string Khoa;
	public:
		void Update(SinhVien &);
};

class SinhVien {
	friend class GiaoVien;
	
	private:
	    string id, ten, ns;
	    double gpa;
	    static int dem;
	public:
	    SinhVien();
	    SinhVien(string, string, string, double);
	    
	    // Ham ban ko phai member, ko phai ham cua class SinhVien
	    // Ham ban co the truy cap vao thuoc tinh, phuong thuc PRIVATE cua class SinhVien
	    friend void ChuanHoaTen(SinhVien &); 
	
	    void Nhap();
	    void Xuat();
};

int SinhVien::dem = 0;

SinhVien::SinhVien() {
    this->id = this->ten = this->ns = "";
    this->gpa = 0;
}

SinhVien::SinhVien(string id, string ten, string ns, double gpa) {
    this->id = id;
    this->ten = ten;
    this->ns = ns;
    this->gpa = gpa;
}

void SinhVien::Nhap() {
    ++dem;
    this->id = "SV" + string(3 - to_string(dem).length(), '0') + to_string(dem);
    cout << "Nhap ten: "; getline(cin, this->ten);
    cout << "Nhap ngay sinh: "; cin >> this->ns;
    cout << "Nhap diem trung binh: "; cin >> this->gpa;
    cin.ignore();
}

void SinhVien::Xuat() {
    cout << this->id << " " << this->ten << " " << this->ns << " " << fixed << setprecision(2) << this->gpa << endl;
}

void ChuanHoaTen(SinhVien &a) {
	string res = "";
	stringstream ss(a.ten);
	string token;
	while(ss >> token) {
		res += toupper(token[0]);
		for(int i = 1; i < token.length(); i++) {
			res += tolower(token[i]);
		}
		res += " ";
	}
	res.erase(res.length() - 1);
	a.ten = res;
}

void GiaoVien::Update(SinhVien &a) {
	a.gpa = 3.98;
}

int main() {
    SinhVien x;
    x.Nhap();
	GiaoVien y;
	y.Update(x);
	ChuanHoaTen(x);
	x.Xuat();

    return 0;
}
