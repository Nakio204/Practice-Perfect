#include <bits/stdc++.h>
using namespace std;

class SinhVien {
    private:
        string id, name, lop, date;
        float gpa;
    public:
        SinhVien() {
            this->id = this->name = this->lop = this->date = "";
            this->gpa = 0.0;
        }
        SinhVien(string ten, string ns, string lop, float gpa) {
            this->name = ten;
            this->date = ns;
            this->gpa = gpa;
            this->lop = lop;
        }
        friend void nhap(SinhVien &);
        friend void in(SinhVien);
};

void nhap(SinhVien &a) {
    a.id = "2251162125";
    getline(cin, a.name);
    getline(cin, a.lop);
    cin >> a.date;
    cin >> a.gpa;
    if(a.date[2] != '/') a.date = "0" + a.date;
    if(a.date[5] != '/') a.date.insert(3, "0");
}

void in(SinhVien a) {
    cout << a.id << " " << a.name << " " << a.lop << " " << a.date << " " << fixed << setprecision(2) << a.gpa << endl;
}

#define a() a

int main() {
    SinhVien a();
    nhap(a);
    in(a);

    return 0;
}