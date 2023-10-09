#include <bits/stdc++.h>
using namespace std;

class SinhVien {
    private:
        string ma, ten, lop, email;
    public:
        SinhVien() {
            this->ma = this->ten = this->lop = this->email = "";
        }
        ~SinhVien() {};
        string getMa() {
            return this->ma;
        }
        void setMa(string ma) {
            ma = this->ma;
        }
        string getTen() {
            return this->ten;
        }
        void setTen(string ten) {
            ten = this->ten;
        }
        string getLop() {
            return this->lop;
        }
        void setLop(string lop) {
            lop = this->lop;
        }
        string getEmail() {
            return this->email;
        }
        void setEmail(string email) {
            email = this->email;
        }
        friend istream & operator >> (istream &, SinhVien &);
        friend ostream & operator << (ostream &, SinhVien);
        bool operator < (SinhVien);
};

istream & operator >> (istream &in, SinhVien &a) {
    cout << "Ma: "; getline(in, a.ma);
    cout << "Ten: "; getline(in, a.ten);
    cout << "Lop: " ; getline(in, a.lop);
    cout << "Email: "; getline(in, a.email);
    return in;
}

ostream & operator << (ostream &out, SinhVien a) {
    out << a.ma << " " << a.ten << " " << a.lop << " " << a.email << endl;
    return out;
}

 bool SinhVien::operator < (SinhVien another) {
    return this->ma < another.ma;
}

int main() {
    vector<SinhVien> a;
    SinhVien tmp;
    while(cin >> tmp) {
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());

    for(SinhVien x : a) {
        cout << x;
    }

    return 0;
}