#include <bits/stdc++.h>
using namespace std;

class NhanSu {
    private:
        int age;
        string id, name;
    public:
        void nhap() {
            cout << "Nhap ID: "; getline(cin, this->id);
            cout << "Nhap ten: "; getline(cin, this->name);
            cout << "Nhap tuoi: "; cin >> this->age;
        }
        void xuat() {
            cout << this->id << "-" << this->name << "-" << this->age;
        }
        // Lon hon 58 thi du dieu kien ve huu
        bool vehuu() {
            if(this->age >= 58) return true;
            return false;
        }
        string getName() {
            return this->name;
        }
};

class CongNhan : public NhanSu {
    private:
        int const mucluong = 180000;
        int ngaycong;
        string taynghe;
    public:
        void nhap() {
            NhanSu::nhap();
            cout << "Nhap so ngay cong: "; cin >> this->ngaycong;
            cin.ignore();
            cout << "Tay nghe: "; getline(cin, this->taynghe);
        }
        int tinhLuong() {
            return this->ngaycong * this->mucluong;
        }
        void xuat() {
            NhanSu::xuat();
            cout << "-" << this->ngaycong << "-" << this->mucluong << endl;
        }
};

class CanBo : public NhanSu {
    private:
        int const heSoluong = 1800000;
        float phucap; // dao dong tu 1.8 - 5.6
        string chuyenmon, trinhdo;
    public:
        void nhap(){
            NhanSu::nhap();
            cout << "Nhap phu cap: "; cin >> this->phucap;
            cin.ignore();
            cout << "Chuyen mon: "; getline(cin, this->chuyenmon);
            cout << "Trinh do: "; getline(cin, this->trinhdo);
        }
        int tienLuong() {
            return this->heSoluong * this->phucap;
        }
        void xuat() {
            NhanSu::xuat();
            cout << "-" << this->chuyenmon << "-" << this->trinhdo << endl;
        }
};



int main() {
    int cn, cb;
    cout << "Nhap so luong cong nhan: "; 
    cin >> cn; cin.ignore();

    vector<CongNhan> cnhan(cn);
    for(int i = 0; i < cn; i++) {
        cout << "------STT: " << i+1 << "------\n";
        cnhan[i].nhap();
    }
    cout << "Nhap so luong can bo: ";
    cin >> cb; cin.ignore();
    vector<CanBo> cbo(cb);
    for(int i = 0; i < cb; i++) {
        cout << "------STT: " << i+1 << "------\n";
        cbo[i].nhap();
    }
    cout << "CONG NHAN:" << endl;
    for(int i = 0; i < cn; i++) {
        cnhan[i].xuat();
    }
    cout << "CAN BO:" << endl;
    for(int i = 0; i < cb; i++) {
        cbo[i].xuat();
    }

    int dem = 0;
    cout << "\nCong nhan da du dieu kien ve huu:" << endl;
    for(int i = 0; i < cn; i++) {
        if(cnhan[i].vehuu()) {
            dem++;
            cnhan[i].xuat();
        } 
    }
    if(dem == 0) cout << "Khong co cong nhan du dieu kien!" << endl;

    int cnt = 0;
    cout << "\nCan bo chua du dieu kien ve huu:" << endl;
    for(int i = 0; i < cb; i++) {
        if(!(cbo[i].vehuu())) {
            cnt++;
            cbo[i].xuat();
        }
    }
    if(cnt == 0) cout << "Khong co can bo du dieu kien!";

    int maxCN = cnhan[0].tinhLuong();
    int indx_max = 0;
    for(int i = 0; i < cn; i++) {
        if(cnhan[i].tinhLuong() > maxCN) {
            maxCN = cnhan[i].tinhLuong();
            indx_max = i;
        } 
    }
    cout << "Cong nhan luong cao nhat: " << cnhan[indx_max].getName() << " voi so luong: " << cnhan[indx_max].tinhLuong() << endl;

    int minCB = cbo[0].tienLuong();
    int indx_min = 0;
    for(int i = 0; i < cb; i++) {
        if(cbo[i].tienLuong() < minCB) {
            minCB = cbo[i].tienLuong();
            indx_min = i;
        } 
    }
    cout << "Can bo luong thap nhat: " << cbo[indx_min].getName() << " voi so luong: " << cbo[indx_min].tienLuong() << endl;

    return 0;
}