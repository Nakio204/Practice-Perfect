#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Hangxe {
    private:
        string ma, ten, nuoc, nam;
    public:
        string getMa(), getTen();
        void input();
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
    getline(cin, nam);
}

class Oto {
    private:
        long long giaNiemyet;
        string ma, ten, nam, mauf;
        int index;
    public:
        Oto() : ma(""), ten(""), nam(""), mauf(""), giaNiemyet(0) {}
        string getMa(), getTen();
        long long getGia();
        void Nhap(vector<Hangxe> &hangXe);
        void Xuat(Hangxe &hxe);
        long long giaLanbanh();
        long long phiDangki();
};

string Oto::getMa() {
    return this->ma;
}

string Oto::getTen() {
    return this->ten;
}

void Oto::Nhap(vector<Hangxe> &hangXe) {
    getline(cin, this->ma);
    getline(cin, this->ten);
    getline(cin, this->nam);
    cin >> index;
    cin >> this->giaNiemyet;
    cin.ignore();
    getline(cin, this->mauf);
}

void Oto::Xuat(Hangxe &hxe) {
    cout << this->ma << "-" << this->ten << "-" << this->nam << "-" << hxe.getTen() << "-" << this->giaNiemyet << "-" << this->mauf << endl;
}

long long Oto::phiDangki() {
    return 2160000 + 480000 + 340000 + 500000 + (giaNiemyet * .072);
}

long long Oto::giaLanbanh() {
    return giaNiemyet + phiDangki();
}

bool cmp(Oto a, Oto b) {
    return a.giaLanbanh() > b.giaLanbanh();
}

int main() {
    int q, p;
    cin >> q;
    cin.ignore();
    vector<Hangxe> hangXe(q);
    for(int i = 0; i < q; i++) {
        hangXe[i].input();
    }
    cin >> p;
    cin.ignore();
    vector<Oto> Car(p);
    for(int i = 0; i < p; i++) {
        Car[i].Nhap(hangXe);
    }

    cout << "===" << endl;
    sort(Car.begin(), Car.end(), cmp);
    for(int i = 0; i < p; i++) {
        Car[i].Xuat(hangXe[i]);
    }
 
    return 0;
}