#include <iostream>
using namespace std;

struct Sinhvien {
	float masv;
	string hoten;
	string lop;
	float diem;
};

Sinhvien *insertStudent(Sinhvien *lsv, int &n){
	cout<<"Nhap so luong phan tu : ";cin>>n;
	lsv = new Sinhvien[n];
	for(int i = 0;i< n;i++){
		cout << "Ma sinh vien: "; cin>>(lsv+i)->masv;
		cout << "Ho ten: "; cin.ignore();getline(cin,(lsv+i)->hoten);
		cout << "Lop: ";getline(cin,(lsv+i)->lop);
		cout<<"Diem: "; cin>>(lsv+i)->diem;
	}
	return lsv;
}

void findAllStudent(Sinhvien *lsv,int n) {
	cout << "\nMaSV" << "\t" << "Ho ten" << "\t" << "Lop" << "\t" << "Diem" << endl;
	for(int i=0;i<n;i++){
		cout << (lsv+i)->masv << "\t" <<(lsv+i)->hoten << " \t" <<(lsv+i)->lop << " \t" <<(lsv+i)->diem <<endl;
	}
}

/* 
Sự cố: Bạn đang sử dụng con trỏ svm mà không cấp phát bộ nhớ cho nó.
Bạn nên sử dụng từ khóa mới để cấp phát bộ nhớ cho học viên mới trước khi nhập liệu

Vấn đề: Trong hàm addStudent, bạn đang sử dụng con trỏ ls,con trỏ này không được khởi tạo với dữ liệu sinh viên.
Thay vào đó, bạn nên sử dụng con trỏ lsv chứa danh sách sinh viên ban đầu.

Sự cố: Bạn không giải phóng bộ nhớ sau khi chương trình kết thúc.
Để tránh rò rỉ bộ nhớ, hãy đảm bảo sử dụng xóa [] để giải phóng bộ nhớ được cấp phát động.

*/
void addStudent(int &n, int k, Sinhvien *ls, Sinhvien svm) {
	cout << "Danh sach sinh vien sau khi them:" << endl;
	cout << "MaSV" << "\t" << "Ho ten" << "\t" << "Lop" << "\t" << "Diem" << endl;
	for (int i = n; i > k ; i--){
		ls[i] = ls[i - 1];
	}
	ls[k] = svm;
	n++;
}

int main(){
	int n, k;
	string lop;
	float diem;
	Sinhvien *lsv;
	Sinhvien svm;

	//Nhap vao danh sach sinh vien
	lsv = insertStudent(lsv,n);
	findAllStudent(lsv,n);
	
	//Chen sinh vien vao vi tri k
	cout << "Nhap vi tri k: ";cin >> k;
	cout<<"Ma sinh vien: ";cin >> svm.masv;cin.ignore();
	cout<<"Ho ten: ";getline(cin,svm.hoten);
	cout<<"Lop: ";getline(cin,svm.lop);
	cout<<"Diem: ";cin >> svm.diem;
	addStudent(n, k, lsv, svm);

	return 0;
}