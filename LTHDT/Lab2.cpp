#include <bits/stdc++.h>
using namespace std;

class Hangxe {
    private:
        string ma, ten, nuoc, nam;
    public:
        Hangxe();

        string getMa();
        string getTen();
        string getNuoc();
        string getNam();

        void setMa(string);
        void setTen(string);
        void setNuoc(string);
        void setNam(string);

        void Nhap();
        void Xuat();
};

Hangxe::Hangxe() {
    ma = ten = nuoc = nam = "";
}

string Hangxe::getMa() {
    return ma;
}


int main() {
    cout << "Hi";

    return 0;
}