#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Hangxe {
    private:
        string ma, ten, nuoc;
        int nam;
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
    cin.ignore();
    getline(cin, ma);
    getline(cin, ten);
    getline(cin, nuoc);
    cin >> nam;
    cin.ignore();
}

class Oto {
    private:
        long long giaNiemyet;
        string ma, ten, mauf;
        int nam, indx;
    public:
        string getMa(), getTen();
        void Nhap(vector<Hangxe> &hangXe);
        void Xuat(Hangxe &hxe);
        long long giaLanbanh();
        long long phiDangki();
        int getIndx();
};

string Oto::getMa() {
    return this->ma;
}

string Oto::getTen() {
    return this->ten;
}

int Oto::getIndx() {
    return this->indx;
}


void Oto::Nhap(vector<Hangxe> &hangXe) {
    getline(cin, this->ma);
    getline(cin, this->ten);
    cin >> this->nam;
    cin >> this->indx;
    cin >> this->giaNiemyet;
    cin.ignore();
    getline(cin, this->mauf);   
}

void Oto::Xuat(Hangxe &hxe) {
    cout << this->ma << "-" << this->ten << "-" << this->nam << "-" << hxe.getTen() << "-" << this->giaNiemyet << "-" << this->mauf << endl;
}

long long Oto::phiDangki() {
    return 2160000 + 480000 + 340000 + 500000 + (giaNiemyet * 0.072);
}

long long Oto::giaLanbanh() {
    return giaNiemyet + phiDangki();
}

bool cmp(Oto a, Oto b) {
    return a.giaLanbanh() > b.giaLanbanh();
}

int main() {
    int hangxe, oto;
    cin >> hangxe;
    cin.ignore();
    vector<Hangxe> hangXe(hangxe);
    for(int i = 0; i < hangxe; i++) {
        hangXe[i].input();
    }
    cin >> oto;
    cin.ignore();
    vector<Oto> Car(oto);
    for(int i = 0; i < oto ; i++) {
        Car[i].Nhap(hangXe);
    }

    string maHangXe;
    cin.ignore();
    getline(cin, maHangXe);

    for (int i = 0; i < oto; i++) {
        if (hangXe[Car[i].getIndx()].getMa() == maHangXe) {
            Car[i].Xuat(hangXe[Car[i].getIndx()]);
        }
    }
    cout << "===" << endl;
    sort(Car.begin(), Car.end(), cmp);
    for (int i = 0; i < oto; i++) {
        Car[i].Xuat(hangXe[Car[i].getIndx()]);
    }

    return 0;
}