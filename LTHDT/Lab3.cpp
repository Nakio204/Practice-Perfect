#include <bits/stdc++.h>
using namespace std;

class Hangxe {
    private:
        string ma, ten, nuoc;
        int nam;
    public:
        string getMa(), getTen();
        void input();
        friend istream& operator >> (istream &in, Hangxe &a);
        friend ostream& operator << (ostream &out, Hangxe a);
};

string Hangxe::getMa() {
    return this->ma;
}

string Hangxe::getTen() {
    return this->ten;
}

void Hangxe::input() {
    getline(cin, ma);
    getline(cin, ten);
    getline(cin, nuoc);
    cin >> nam;
    cin.ignore();
}

istream & operator >> (istream &in, Hangxe &a) {
    cout << "Nhap ma: "; getline(in, a.ma);
    cout << "Nhap ten: "; getline(in, a.ten);
    cout << "Nhap nuoc: "; getline(in, a.nuoc);
    cout << "Nhap nam: "; in >> a.nam;
    cin.ignore();
    return in;
}

ostream & operator << (ostream &out, Hangxe a) {
    out << a.ma << "-" << a.ten << "-" << a.nuoc << "-" << a.nam << "-" << endl;
    return out;
}

class PTGT : public Hangxe {
    private:
        string mapt, tenpt, loaipt;
        int hangpt;
        long int giapt;
    public:
        void Nhap(vector<Hangxe> &hxe);
        long int getGia() {
            return this->giapt;
        }
        long int operator + ();
};

void PTGT::Nhap(vector<Hangxe> &hxe) {
    cout << "Nhap mapt: "; getline(cin, this->mapt);
    cout << "Nhap tenpt: "; getline(cin, this->tenpt);
    cout << "Nhap loaipt: "; getline(cin, this->loaipt);
    cout << "Nhap giapt: "; cin >> this->giapt;
    cout << "Nhap hangpt: "; cin >> this->hangpt;
    cin.ignore();
}

long int PTGT::operator + ( ) {
    long int kq;
    
}


class Oto : public PTGT {
    private:
        string tenct, mauct, loainl;
        int nam;
    public:
        void nhap();
};

void Oto::nhap() {
    cout << "Nhap tenct: "; getline(cin, this->tenct);
    cout << "Nhap namsx: "; cin >> this->nam; cin.ignore();
    cout << "Nhap mauct: "; getline(cin, this->mauct);
    cout << "Nhap loainl: "; getline (cin, this->loainl);
}

int main(){
    int ptgt, hangxe;

    cin >> hangxe;
    vector<Hangxe> HangXe(hangxe);
    for(int i = 0; i < hangxe; i++) {
        Hangxe[i].input();
    }

    cin >> ptgt;
    vector<PTGT> Ptgt(ptgt);
    for(int i = 0; i < ptgt; i++) {
        Ptgt[i].Nhap(HangXe);
    }
    // int type = 0;
    // for(int i = 0; i < n; i++){
    //     cin >> type; 
    //     if(type = 0){
            

    //     }else{
            

    //     }
    // }

    return 0;
}