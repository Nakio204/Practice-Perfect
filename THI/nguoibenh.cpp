#include <bits/stdc++.h>
using namespace std;

class nguoibenh {
	private:
		string ten, dc;
		int namsinh;
	public:
		nguoibenh() {
			ten = dc = "";
			namsinh = 0;
		}
		nguoibenh(string ten, string dc, int nam) {
			this->ten = ten;
			this->dc = dc;
			this->namsinh = nam;
		}
		void setTen(string ten) {
			this->ten = ten;
		}
		void setDc(string dc) {
			this->dc = dc;
		}
		void setNam(int nam) {
			this->namsinh = nam;
		}
		string getTen() {
			return this->ten;
		}
		string getDc() {
			return this->dc;
		}
		int getNam() {
			return this->namsinh;
		}
		virtual void Nhap() {
			cin.ignore();
			cout << "Ten nguoi benh: ";getline(cin, ten);
			cout << "Dia chi: "; getline(cin, dc);
			cout << "Nam sinh: "; cin >> namsinh;
		}
		virtual void Xuat() {
			cout << ten << "-" << dc << "-" << namsinh;
		}
		virtual int getVp() {
			return 0;
		}
		virtual int tinhTuoi() {
			return 2023 - getNam();
		}
};

class benhan : public nguoibenh {
	private:
		string id, tenbenh;
		int vienphi;
	public:
		benhan() : nguoibenh() {
			id = tenbenh = "";
			vienphi = 0;
		}
		benhan(string ten, string dc, int nam, string id, string name, int vp) : nguoibenh(ten, dc, nam) {
			this->id = id;
			this->tenbenh = name;
			this->vienphi = vp;
		}
		void setId(string id) {
			this->id = id;
		}
		void setTenbenh(string ten) {
			this->tenbenh = ten;
		}
		void setVienphi(int vp) {
			this->vienphi = vp;
		}
		string getId() {
			return this->id;
		}
		string getTenbenh() {
			return this->tenbenh;
		}
		int getVp() {
			return this->vienphi;
		}
		void Nhap() {
			nguoibenh::Nhap();
			cin.ignore();
			cout << "Ma benh an: "; getline(cin, id);
			cout << "Ten benh an: "; getline(cin, tenbenh);
			cout << "Vien phi: "; cin >> vienphi;
		}
		int tinhTuoi() {
			return 2023 - nguoibenh::getNam();
		}		
		void Xuat() {
			nguoibenh::Xuat();
			cout << "-" << tinhTuoi() << "-" << id << "-" << tenbenh << "-" << vienphi << endl;
		}
};

bool cmp(nguoibenh *a, nguoibenh *b) {
	return a->getVp() > b->getVp();
}

int main() {
	int n;
	cout << "Nhap danh sach benh nhan: "; cin >> n;
	vector<nguoibenh *> ds;
	
	for(int i = 0; i < n; i++) {
		nguoibenh *nguoibenh = new benhan();
		nguoibenh->Nhap();
		ds.push_back(nguoibenh);
	}
	sort(ds.begin(), ds.end(), cmp);
	cout << "\nDanh sach benh nhan:" << endl;
	for(int i = 0; i < n; i++) {
		ds[i]->Xuat();
	}
	cout << "\nDanh sach benh nhan nho hon 10 tuoi:" << endl;
	for(int i = 0; i < n; i++) {
		if(ds[i]->tinhTuoi() < 10) ds[i]->Xuat();
	}
	int maxTuoi = ds[0]->tinhTuoi();
	int indx = 0;
	for(int i = 1; i < n; i++) {
		if(ds[i]->tinhTuoi() > maxTuoi) {
			maxTuoi = ds[i]->tinhTuoi();
			indx = i;
		}
	}
	cout << "\nBenh nhan co tuoi nhieu nhat:" << endl;
	ds[indx]->Xuat();
	
	return 0;
}