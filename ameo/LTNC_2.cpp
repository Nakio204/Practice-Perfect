#include <iostream>
#include <string>

using namespace std;

int main() {
    string ten, hocbong;
    float diem_rl, diem_tbtl;

    cout << "Nhập tên sinh viên: ";
    getline(cin, ten);
    cout << "Nhập điểm GPA: ";
    cin >> diem_tbtl;
    cout << "Nhập điểm rèn luyện: ";
    cin >> diem_rl;

    if ((diem_rl < 70 && diem_rl > 100) || (diem_tbtl < 2.5 && diem_tbtl > 4.0)) cout << "Không có học bổng rồi cu:D";
    else {
        if ((diem_rl < 80) || diem_tbtl <= 3.19) hocbong = "Khá";
        else if ((diem_rl >= 80 && diem_rl < 90) || (diem_tbtl >= 3.20 && diem_tbtl <= 3.59)) hocbong = "Giỏi";
        else if ((diem_rl >= 90) || diem_tbtl >= 3.60) hocbong = "Xuất sắc";
        cout << "Sinh viên " << ten << " đạt học bổng " << hocbong << ", Congratulation !";
    }

    return 0;
}