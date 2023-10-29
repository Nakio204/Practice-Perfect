#include <iostream>
#include <vector>
using namespace std;

class VIENCHUC {
	private:
		string id, name, date;
		int HSL;
	public:
		VIENCHUC() {id = name = date = ""; HSL = 0;}
		VIENCHUC(string id, string name, string date, int HSL) {this->id = id;this->name = name;this->date = date;this->HSL = HSL;}
		~VIENCHUC() {}
		void setId(string id) {
			this->id = id;
		}
		void setName(string name) {
			this->name = name;
		}
		void setDate(string date) {
			this->date = date;
		}
		void setHSL(long int hsl) {
			this->HSL = hsl;
		}
		string getId() {
			return this->id;
		}
		string getName() {
			return this->name;
		}
		string getDate() {
			return this->date;
		}
		int getHSL() {
			return this->HSL;
		}
		virtual void Nhap() {
			cout << "ID: "; getline(cin, this->id);
			cout << "Name: "; getline(cin, this->name);
			cout << "Date: "; getline(cin, this->date);
			cout << "He so luong: "; cin >> this->HSL;
		}
		virtual void Xuat() {
			cout << id << "-" << name << "-" << date << "-" << HSL;
		}
		virtual long int tinhLuong() = 0;
};

class CBHANHCHINH : public VIENCHUC {
	private:
		string chucdanh;
		int phucap1;
	public:
		CBHANHCHINH(){chucdanh = ""; phucap1 = 0;}
		CBHANHCHINH(string cd, int pc1) {chucdanh = cd; phucap1 = pc1;}
		void Nhap() {
			VIENCHUC::Nhap();
			cin.ignore();
			cout << "Chuc danh: "; getline(cin, chucdanh);
			cout << "Phu cap trua: "; cin >> phucap1;
		}
		void Xuat() {
			VIENCHUC::Xuat();
			cout << "-" << chucdanh << "-" << phucap1 << endl;
		}
		long int tinhLuong() override {
			return getHSL() * 2000000 + phucap1;
		}
};

class GIAOVIEN : public VIENCHUC{
	private:
		string monday, trinhdo;
		int thamnien;
	public:
		GIAOVIEN() {monday = trinhdo = "";thamnien = 0;}
		GIAOVIEN(string md, string td, int tn) {monday = md;trinhdo = td;thamnien = tn;}
		void Nhap() {
			VIENCHUC::Nhap();
			cin.ignore();
			cout << "Mon day: "; getline(cin, this->monday);
			cout << "Trinh do: "; getline(cin, this->trinhdo);
			cout << "Tham nien: "; cin >> this->thamnien;
		}
		void Xuat() {
			VIENCHUC::Xuat();
			cout << "-" << monday << "-" << trinhdo << "-" << thamnien << endl; 
		}
		long int tinhLuong() override {
			return getHSL() * 2000000 * (130 + thamnien)/100.0;
		}
};

int main() {
    vector<VIENCHUC *> vienChucList;
    int n;
    cout << "Nhap so luong vien chuc: "; cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\n0. CAN BO HANH CHINH\n1. GIAO VIEN\nMoi nhap lua chon: ";
        int type;
        cin >> type; cin.ignore();

        if (type == 0) {
            cout << "Nhap thong tin CBHC" << endl;
            VIENCHUC* vc = new CBHANHCHINH();
            vc->Nhap();
            vienChucList.push_back(vc);
        }
        else if (type == 1) {
            cout << "Nhap thong tin GV" << endl;
            VIENCHUC* vc1 = new GIAOVIEN();
            vc1->Nhap();
            vienChucList.push_back(vc1);
        }
    }

    cout << "\nDanh sach vien chuc" << endl;
    for (int i = 0; i < n; i++) {
        vienChucList[i]->Xuat(); 
    }
	cout << endl;
    long int maxSalary = vienChucList[0]->tinhLuong();
    int indx = 0;
    for (int i = 1; i < n; i++) {
        if (vienChucList[i]->tinhLuong() > maxSalary) {
            maxSalary = vienChucList[i]->tinhLuong();
            indx = i;
        }
    }

    cout << "Vien chuc co luong cao nhat la: \n";
    vienChucList[indx]->Xuat();

    for (int i = 0; i < vienChucList.size(); i++) {
        delete vienChucList[i];
    }
	
	ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    return 0;
}
