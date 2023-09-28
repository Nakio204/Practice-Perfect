#include <iostream>
#include <cmath>
using namespace std;

class SoPhuc {
    private:
        float thuc, ao;
    public:
        SoPhuc(float = 0, float = 0);
        ~SoPhuc(void);

        // Nhap xuat phai su dung ham friend
        friend istream & operator >> (istream &in, SoPhuc &a);
        friend ostream & operator << (ostream &out, SoPhuc a);

        // Cac ham khac co the su dung ham friend tuy de bai
        friend bool operator == (SoPhuc a, SoPhuc b);

        // La thanh vien cua class thi chi can 1 tham so truyen vao
        // La ham friend thi can 2
        SoPhuc operator + (SoPhuc a);
        SoPhuc operator - (SoPhuc a);
        friend SoPhuc operator * (SoPhuc a, SoPhuc b);
        friend SoPhuc operator / (SoPhuc a, SoPhuc b);
};

SoPhuc::SoPhuc(float b, float c) {
    this->thuc = b;
    this->ao = c;
}

SoPhuc::~SoPhuc(){}

istream & operator >> (istream &in, SoPhuc &a) {
    cout << "Nhap phan thuc: "; in >> a.thuc;
    cout << "Nhap phan ao: "; in >> a.ao;
    return in;
}

ostream & operator << (ostream &out, SoPhuc a) {
    if(a.thuc == 0 && a.ao == 0) out << "0";
    else if(a.thuc == 0 && a.ao != 0) out << a.ao << "i";
    else if(a.thuc != 0 && a.ao == 0) out << a.thuc;
    else out << "z = " << a.thuc << ((a.ao > 0) ? " + " : " - ") << abs(a.ao) << "i";
    return out; 
}

bool operator == (SoPhuc a, SoPhuc b) {
    return ((a.ao == b.ao) && (a.thuc == b.thuc)); 
}

SoPhuc SoPhuc::operator + (SoPhuc a) {
    SoPhuc sum;
    sum.ao = this->ao + a.ao;
    sum.thuc = this->thuc + a.thuc;
    return sum;
}

SoPhuc SoPhuc::operator - (SoPhuc a) {
    SoPhuc sum;
    sum.ao = this->ao - a.ao;
    sum.thuc = this->thuc - a.thuc;
    return sum;
}

SoPhuc operator * (SoPhuc a, SoPhuc b) {
    SoPhuc res;
    res.thuc = a.thuc * b.thuc - a.ao * b.ao;
    res.ao = a.thuc * b.ao + a.ao * b.thuc;
    return res;
}

SoPhuc operator / (SoPhuc a, SoPhuc b) {
    SoPhuc res;
    res.thuc = (a.thuc * b.thuc + a.ao * b.ao) / (b.thuc * b.thuc + b.ao * b.ao);
    res.ao = (a.ao * b.thuc - a.thuc * b.ao) / (b.thuc * b.thuc + b.ao * b.ao);
    return res;
}

int main() {
    SoPhuc x, y, tong, hieu, tich, thuong;

    cout << "Nhap so phuc 1" << endl; 
    cin >> x;
    cout << endl << "Nhap so phuc 2" << endl;
    cin >> y;
    
    cout << endl << x << endl;
    cout << y << endl;

    tong = x + y;
    cout << "\nTong hai so phuc: " << tong << endl;
    hieu = x - y;
    cout << "Hieu hai so phuc: " << hieu << endl;
    tich = x * y;
    cout << "Tich hai so phuc: " << tich << endl;
    thuong = x / y;
    cout << "Thuong hai so phuc: " << thuong << endl;

    if(x == y) cout << "\nHai so phuc bang nhau." << endl;
    else cout << "\n!(Hai so phuc bang nhau.)" << endl;

    return 0;
}