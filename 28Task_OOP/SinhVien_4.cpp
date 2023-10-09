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
    int n, q; cin >> n;
    cin.ignore();
    vector<SinhVien> sv(n);
    for(int i = 0; i < n; i++) {
        cin >> sv[i];
    }

    cin >> q; cin.ignore();
    while(q--) {
        string s; getline(cin, s);
        cout << "DANH SACH SINH VIEN LOP " << s << ":\n";
        for(SinhVien x : sv)  {
            if(x.getLop() == s) cout << x; 
        }
    }

    return 0;
}
// 4
// B16DCCN001
// Nguyen Trong Duc Anh 
// D16CNPM1
// sv1@stu.ptit.edu.vn
// B15DCCN215
// To Ngoc Hieu
// D15CNPM3
// sv2@stu.ptit.edu.vn
// B15DCKT150
// Nguyen Ngoc Son
// D15CQKT02-B
// sv3@stu.ptit.edu.vn
// D15CQKT199
// Nguyen Trong Tung
// D16CQKT03-B
// sv4@stu.ptit.edu.vn
// 1
// D15CQKT03-B