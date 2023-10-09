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
    return a.getSl() > b.getSl();
}


int main() {
    int n; cin >> n; cin.ignore();
    vector<DoanhNghiep> a(n);
    
    for(DoanhNghiep &x : a) x.Nhap();
    sort(a.begin(), a.end(), cmp);
    for(DoanhNghiep x : a) x.Xuat();

    return 0;
}