#include <bits/stdc++.h>
using namespace std;

class DoanhNghiep {
    private:
        string id, name;
        int soluong;
    public:
        DoanhNghiep() {
            this->id = this->name = "";
            this->soluong = 0;
        }
        ~DoanhNghiep() {};
        void setId(string ma) {
            this->id = ma;
        }
        string getId() {
            return this->id;
        }
        void setName(string ten) {
            this->name = ten;
        }
        string getName() {
            return this->name;
        }
        void setSl(int sl) {
            this->soluong = sl;
        }
        int getSl() {
            return this->soluong;
        }
        void Nhap() {
            getline(cin, this->id);
            getline(cin, this->name);
            cin >> this->soluong;
            cin.ignore();
        }
        void Xuat() {
            cout << this->id << " " << this->name << " " << this->soluong << endl;
        }

};

bool cmp(DoanhNghiep a, DoanhNghiep b) {
    if(a.getSl() != b.getSl()) return a.getSl() > b.getSl();
    return a.getId() < b.getId();
}


int main() {
    int n; cin >> n; cin.ignore();
    vector<DoanhNghiep> dn(n);
    
    for(DoanhNghiep &x : dn) x.Nhap();
    sort(dn.begin(), dn.end(), cmp);

    int q; cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << "DANH SACH DOANH NGHIEP NHAN TU " << a << " DEN " << b << " SINHVIEN:\n";
        
        for(DoanhNghiep i : dn) {
            if(i.getSl() >= a && i.getSl() <= b) i.Xuat();    
        }
    }


    return 0;
}