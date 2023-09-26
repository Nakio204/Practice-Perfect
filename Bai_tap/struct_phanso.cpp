#include <iostream>
using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

PhanSo tinhTong(PhanSo a, PhanSo b) {
    PhanSo tong;
    tong.tu = a.tu * b.mau + b.tu * a.mau;
    tong.mau = a.mau * b.mau;
    return tong;
}

int UCLN(int a, int b) {
    if (b == 0) return a;
    return UCLN(b, a % b);
}

PhanSo rutGonPhanSo(PhanSo ps) {
    int gcd = UCLN(ps.tu, ps.mau);
    ps.tu /= gcd;
    ps.mau /= gcd;
    return ps;
}

int main() {
    PhanSo a, b;
    cout << "Phan so a: " << endl;
    cout << "Tu: "; cin >> a.tu;
    cout << "Mau: "; cin >> a.mau;
    cout << "Phan so b: " << endl;
    cout << "Tu: "; cin >> b.tu;
    cout << "Mau: "; cin >> b.mau;

    if (a.mau == 0 || b.mau == 0) {
        cout << "Co phan so khong hop le!";
    } else {
        PhanSo tong = tinhTong(a, b);
        tong = rutGonPhanSo(tong);
        
        if (tong.tu < 0 || tong.mau < 0) {
            cout << "Tong a + b = -" << abs(tong.tu) << "/" << abs(tong.mau);
        } else {
            cout << "Tong a + b = " << tong.tu << "/" << tong.mau;
        }
    }

    return 0;
}