#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

class PhanSo {
    private:
        long long tu, mau;
    public:
        PhanSo(long long, long long);
        friend istream & operator >> (istream &, PhanSo &);
        friend ostream & operator << (ostream &, PhanSo);
        void rutgon();
        friend PhanSo operator + (PhanSo, PhanSo);
};

PhanSo::PhanSo(long long tu, long long mau) {
    this->tu = tu;
    this->mau = mau;
}

istream & operator >> (istream &in, PhanSo &a) {
    in >> a.tu;
    in >> a.mau;
    return in;
}

ostream & operator << (ostream &out, PhanSo a) {
    if(a.tu == 0 && a.mau != 0) out << "0";
    else if(a.tu == 0 && a.mau == 0) out << "Error!";
    else if(a.tu == 1 && a.mau == 1) out << "1";
    else if(a.tu != 1 && a.mau == 1) out << a.tu;
    else out << a.tu << "/" << a.mau;
    return out;
}

void PhanSo::rutgon() {
    long long res = gcd(this->tu, this->mau);
    this->tu /= res;
    this->mau /= res;
}

PhanSo operator + (PhanSo a, PhanSo b) {
    PhanSo res(1, 1);
    res.tu = a.tu * b.mau + b.tu * a.mau;
    res.mau = a.mau * b.mau;
    res.rutgon();
    return res;
}

int main() {
    PhanSo p(1, 1), q(1, 1);
    cin >> p >> q;
    cout << p + q;

    return 0;
}