#include <iostream>
using namespace std;

struct Sinhvien{
    int MaSV;
    string Hoten, Lop;
    float diem;
};

void nhapSV(Sinhvien sv[], int &n) {
    for(int i = 0; i < n; i++) {
        cout << "Sinh vien " << i+1 << endl;

        cout << "Nhap ma sinh vien: ";
        cin >> sv[i].MaSV;

        cout << "Nhap ho ten: "; cin.ignore();
        getline(cin, sv[i].Hoten);

        cout << "Nhap lop: ";
        getline(cin, sv[i].Lop);

        cout << "Nhap diem: ";
        cin >> sv[i].diem;
    }
}

void xuatSV(Sinhvien sv[], int n) {
	cout << "\nThong tin sinh vien vua nhap la: \n";
	cout << "STT\t" << "MaSV\t" << "Ho ten\t" << "Lop\t" << "Diem" << endl;
	for(int i = 0; i < n; i++) {
		cout << i+1 << "\t" << sv[i].MaSV << "\t" << sv[i].Hoten << "\t" << sv[i].Lop << "\t" << sv[i].diem << endl;
	}
}

void findSVclass(Sinhvien sv[], int n, string clasS) {
	for(int i = 0; i < n; i++) {
		if(sv[i].Lop == clasS) {
			cout << "MaSV\t" << "Ho ten\t" << "Lop\t" << "Diem" << endl;
			cout << sv[i].MaSV << "\t" << sv[i].Hoten << "\t" << sv[i].Lop << "\t" << sv[i].diem << endl;
		}
	}
}

void findSVclass2(Sinhvien sv[], int n, string clasS) {
	for(int i = 0; i < n; i++) {
		if(sv[i].Lop == clasS && sv[i].diem > 5) {
			cout << "MaSV\t" << "Ho ten\t" << "Lop\t" << "Diem" << endl;
			cout << sv[i].MaSV << "\t" << sv[i].Hoten << "\t" << sv[i].Lop << "\t" << sv[i].diem << endl;
		}
	}
}

void diemMax(Sinhvien sv[], int n) {
	int max = sv[0].diem;
	for(int i = 0; i < n; i++) {
		if(sv[i].diem > max) {
			max = sv[i].diem;
			cout << "MaSV\t" << "Ho ten\t" << "Lop\t" << "Diem" << endl;
			cout << sv[i].MaSV << "\t" << sv[i].Hoten << "\t" << sv[i].Lop << "\t" << sv[i].diem << endl;			
		}
	}
} 

void themSV(Sinhvien sv[], int &n) {
    cout << "Nhap ma sinh vien: ";
    cin >> sv[n].MaSV;

    cout << "Nhap ho ten: "; cin.ignore();
    getline(cin, sv[n].Hoten);

    cout << "Nhap lop: ";
    getline(cin, sv[n].Lop);

    cout << "Nhap diem: ";
    cin >> sv[n].diem;
    
    n++;
}

int main() {
    Sinhvien sv[100];
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    
    nhapSV(sv, n);
    xuatSV(sv, n);
//    string clasS; cin.ignore();
//    cout << "\nNhap lop de tim kiem sinh vien: ";
//    getline(cin, clasS);
//    cout << "Sinh vien trong lop " << clasS << endl;
//    findSVclass(sv, n, clasS);
//    cout << "\nSinh vien trong lop " << clasS << " va co diem lon hon 5" << endl;
//    findSVclass2(sv, n, clasS);
//    cout << "\nSinh vien co diem lon nhat: \n";
//    diemMax(sv, n);
	cout << "\nNhap thong tin sinh vien moi\n";
	themSV(sv, n);
	xuatSV(sv, n);
	
    return 0;
}
