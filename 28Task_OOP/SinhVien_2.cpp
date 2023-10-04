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
        friend istream & operator >> (istream &, SinhVien &);
        friend ostream & operator << (ostream &, SinhVien);
};

istream & operator >> (istream &in, SinhVien &a) {
    a.id = "B20DCCN001";
    getline(in, a.name);
    getline(in, a.lop);
    in >> a.date;
    in >> a.gpa;
    if(a.date[0] != '0') a.date.insert(0, "0");
    if(a.date[3] != '0') a.date.insert(3, "0");
    return in;
}

ostream & operator << (ostream &out, SinhVien a) {
    out << a.id << " " << a.name << " " << a.lop << " " << a.date << " " << fixed << setprecision(2) << a.gpa << endl;
    return out;
}

#define a() a

int main() {
    SinhVien a();
    cin >> a;
    cout << a;

    return 0;
}