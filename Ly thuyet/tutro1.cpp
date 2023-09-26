#include <iostream>
using namespace std;

struct Sinhvien {
	float masv;
	string hoten;
	string lop;
	float diem;
};

Sinhvien *insertStudent(int &n) {
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	Sinhvien *lsv = new Sinhvien[n];
	for (int i = 0; i < n; i++) {
		cout << "Ma sinh vien: ";
		cin >> (lsv + i)->masv;
		
		cout << "Ho ten: ";
		cin.ignore();
		getline(cin, (lsv + i)->hoten);
		
		cout << "Lop: ";
		getline(cin, (lsv + i)->lop);
		
		cout << "Diem: ";
		cin >> (lsv + i)->diem;
	}
	return lsv;
}

void findAllStudent(Sinhvien *lsv, int n) {
	cout << "\nMaSV" << "\t" << "Ho ten" << "\t" << "Lop" << "\t" << "Diem" << endl;
	for (int i = 0; i < n; i++) {
		cout << (lsv + i)->masv << "\t" << (lsv + i)->hoten << " \t" << (lsv + i)->lop << " \t" << (lsv + i)->diem << endl;
	}
}

/*
Vòng lặp for đầu tiên (for (int i = 0; i < k; i++)) 
Sao chép các phần tử từ mảng lsv ban đầu sang mảng tạm thời temp đến vị trí k - 1.
Điều này đảm bảo rằng tất cả các phần tử trước điểm chèn vẫn còn trong mảng mới.

temp[k] = newStudent;
Dòng này chèn 'newStudent' vào vị trí thứ k trong mảng tạm thời temp.

Vòng lặp for thứ hai (for (int i = k + 1; i <= n; i++)) 
Sao chép các phần tử còn lại từ mảng 'lsv' ban đầu sang mảng tạm thời temp bắt đầu từ vị trí k + 1.
Vd k = 0, thì mảng ban đầu em nhập sẽ được paste từ vị trí k = 1, nghĩa là
giữ nguyên thông tin sinh viên mới vừa nhập và bê nguyên bọn cũ để sau thằng mới

lsv = temp;
Dòng này làm cho con trỏ ban đầu lsv trỏ đến mảng temp mới được sửa đổi.
Bây giờ, con trỏ lsv trỏ đến mảng chứa danh sách cập nhật với sinh viên mới được thêm vào.

*/

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

	// Nhap vao danh sach sinh vien
	lsv = insertStudent(n);
	findAllStudent(lsv, n);

	// Chen sinh vien vao vi tri k
	cout << "\nNhap vi tri k: ";
	cin >> k;
	cout << "Ma sinh vien: ";
	cin >> newStudent.masv;
	cout << "Ho ten: ";
	cin.ignore();  // Nãy em quên ko thêm nên nó mới lỗi ko nhập đc đó:3
	getline(cin, newStudent.hoten);
	cout << "Lop: ";
	getline(cin, newStudent.lop);
	cout << "Diem: ";
	cin >> newStudent.diem;
	addStudent(n, k, lsv, newStudent);

	// In lại danh sách sinhvien sau khi chèn nè
	findAllStudent(lsv, n);

	delete[] lsv; // Làm trống mảng để code mượt hơn, hihi.
	return 0;
}
