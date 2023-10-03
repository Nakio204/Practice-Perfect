#include <bits/stdc++.h>
using namespace std;

class SinhVien {
    private:
        string id, name;
        int age;
    public:
        void nhap();
        void xuat();
};

void SinhVien::nhap() {
    cout << "Nhap id: "; getline(cin, this->id);
    cout << "Nhap ten: "; getline(cin, this->name);
    cout << "Nhap tuoi: ";cin >> this->age;
    cin.ignore();
}

void SinhVien::xuat() {
    cout << this->id << "-" << this->name << "-" << this->age << "-";
}

class DiemTongKet : public SinhVien {
    private:
        float toan, ly, hoa;
    public:
        void nhap();
        void xuat();
        float diemTrunbinh();
        char xepLoai();
};  

void DiemTongKet::nhap() {
    SinhVien::nhap();
    cout << "Nhap diem toan: "; cin >> this->toan;
    cout << "Nhap diem ly: "; cin >> this->ly;
    cout << "Nhap diem hoa: "; cin >> this->hoa;
    cin.ignore();
}

void DiemTongKet::xuat() {
    SinhVien::xuat();
    cout<< this->toan << "-" << this->ly << "-" << this->hoa << endl;
}

float DiemTongKet::diemTrunbinh() {
    return (this->toan + this->ly + this->hoa) / 3.0;
}

char DiemTongKet::xepLoai() {
    if(diemTrunbinh() >= 8) return 'A';
    else if(diemTrunbinh() >= 7) return 'B';
    else if(diemTrunbinh() >= 6) return 'C';
    else return 'D';
}

int main() {
    int n;
    cout << "Nhap danh sach sinh vien: ";
    cin >> n; cin.ignore();

    vector<DiemTongKet> diem(n);
    for(int i = 0; i < n; i++) {
        diem[i].nhap();
    }
    for(int i = 0; i < n; i++) {
        diem[i].xuat();
    }

    cout << "======" << endl;
    for(int i = 0; i < n; i++) {
        if(diem[i].diemTrunbinh() >= 8) diem[i].xuat();
    }
    cout << endl;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(diem[i].xepLoai() == 'B') cnt++;
    }
    cout << "So luong sinh vien kha: " << cnt << endl;

    return 0;
}