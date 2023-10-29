#include <bits/stdc++.h>
using namespace std;

class Vehicles {
	private:
		int tocdo;
	public:
		Vehicles() {
			tocdo = 0;
		}
		Vehicles(int td) {
			tocdo = td;
		}
		void setTd(int td) {
			this->tocdo = td;
		}
		int getTd() {
			return this->tocdo;
		}
		virtual int const maxSpeed() = 0;
		virtual void Nhap() {
			cout << "Toc do tieu chuan: "; cin >> tocdo;
		}
		virtual void Xuat() {
			cout << tocdo;
		}
		virtual bool operator > (Vehicles &other) {
    		return false;
		}
};

class Ferrari : public Vehicles {
	private:
		string color;
		float heso;
	public:
		Ferrari() : Vehicles() {
			color = "";
			heso = 0.0;
		}
		Ferrari(int td, string color, float hs) : Vehicles(td) {
			this->color = color;
			this->heso = hs;
		}
		void setMau(string mau) {
			this->color = mau;
		}
		void setHeso(float hs) {
			this->heso = hs;
		}
		string getMau() {
			return this->color;
		}
		float getHeso() {
			return this->heso;
		}
		int const maxSpeed() override {
			return getHeso() * Vehicles::getTd();
		}
		void Nhap() {
			Vehicles::Nhap();
			cin.ignore();
			cout << "Mau sac: "; getline(cin, color);
			cout << "He so toc do: "; cin >> heso;
		}
		void Xuat() {
			Vehicles::Xuat();
			cout << "-" << color << "-" << heso << "-" << maxSpeed() << endl;
		}
		friend bool operator > (Ferrari &T1, Ferrari &T2) {
    		return T1.maxSpeed() > T2.maxSpeed();
		}
};

int main() {
	int n;
	cout << "Nhap danh sach xe Ferrari: "; cin >> n;
	vector<Vehicles *> ds;
	
	for(int i = 0; i < n; i++) {
		Vehicles *car = new Ferrari();
		car->Nhap();
		ds.push_back(car);
	} cout << endl;
	for(int i = 0; i < n; i++) {
		cout << i << ". " << "Ferrari" << i << "-";
		ds[i]->Xuat();
	}
	int maxIndx = 0;
    for (int i = 1; i < n; i++) {
        if (ds[i] > ds[maxIndx]) {
            maxIndx = i;
        }
    }
    cout << "\nFerrari co toc do toi da cao nhat: " << endl;
    ds[maxIndx]->Xuat();
	
	return 0;
}