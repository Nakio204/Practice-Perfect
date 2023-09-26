#include <iostream>
using namespace std;

struct Sinhvien {
	string hotenSV, lop, maSV;
	double Diem;
};

Sinhvien *insertStudent(Sinhvien *lsv, int &n) {
	cout << "Nhap so luong sinh vien: "; cin >> n; cout << endl;
	lsv = new Sinhvien[n];
	for(int i = 0; i < n; i++) {
		cout << "Sinh vien " << i+1 << endl;
		
		cin.ignore();
        cout << "+ Nhap ma sinh vien: ";
        getline(cin, lsv[i].maSV);

        cout << "+ Nhap ho ten: ";
        getline(cin, lsv[i].hotenSV);

        cout << "+ Nhap lop: ";
        getline(cin, lsv[i].lop);

        cout << "+ Nhap diem: ";
        cin >> lsv[i].Diem;
	}
	return lsv;
}

void findAllStudent(Sinhvien *lsv, int n) {
	cout << "\nThong tin sinh vien vua nhap la: \n";
	cout << "STT\t" << "MaSV\t" << "Ho ten\t" << "Lop\t" << "Diem" << endl;
	for(int i = 0; i < n; i++) {
		cout << i+1 << "\t" << lsv[i].maSV << "\t" << lsv[i].hotenSV << "\t" << lsv[i].lop << "\t" << lsv[i].Diem << endl;
	}
}

void addStudent(int &n, int k, Sinhvien *&lsv, Sinhvien newStudent) {
	
	Sinhvien *temp = new Sinhvien[n + 1]; 
	for (int i = 0; i < k; i++) {
		temp[i] = lsv[i];
	}
	
	temp[k] = newStudent;
	
	for (int i = k + 1; i <= n; i++) {
		temp[i] = lsv[i - 1];
	}
	
	delete[] lsv; 
	
	lsv = temp; 
	
	n++;
}

int main() {
	int n, k;
	Sinhvien *lsv;
	Sinhvien newStudent;
	lsv = insertStudent(lsv, n);
	findAllStudent(lsv, n);
	
	cout << "\nNhap vi tri k: ";
	cin >> k;
	cout << "Ma sinh vien: ";
	cin >> newStudent.maSV;
	cout << "Ho ten: ";
	cin.ignore();
	getline(cin, newStudent.hotenSV);
	cout << "Lop: ";
	getline(cin, newStudent.lop);
	cout << "Diem: ";
	cin >> newStudent.Diem;
	addStudent(n, k, lsv, newStudent);
	findAllStudent(lsv, n);
	
	delete[] lsv;
	return 0;
}