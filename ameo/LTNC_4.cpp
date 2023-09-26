#include <iostream>
#include <string>
using namespace std;

// Khai báo hàm:
string hocbong(string a, float b, float c); 

int main() {
    string ten;
    float diem_rl, diem_gpa;

    cout << "Nhập tên sinh viên: ";
    getline(cin, ten);
    cout << "Nhập điểm GPA: ";
    cin >> diem_gpa;
    cout << "Nhập điểm rèn luyện: ";
    cin >> diem_rl;

    // Gọi hàm:
    cout << hocbong(ten, diem_gpa, diem_rl);

    return 0;
}

// Định nghĩa hàm:
string hocbong(string a, float b, float c) {
    string result, hocbong;

    if ((c < 70 && c > 100) || (b < 2.5 && b > 4.0)) result = "Du lieu khong hop le!";
    else {
        if (c < 80 && b <= 3.19) hocbong = "Khá";
        else if (c < 90 && b <= 3.59) hocbong = "Giỏi";
        else hocbong = "Xuất Sắc";
        result = "Sinh viên " + a + " đạt học bổng " + hocbong + ", Congratulation !";
    }
    return result;
}