#include <iostream>
#include <string>

using namespace std;

int main() {
    string name, subject;
    float score;
    char score_text;

    cout << "Nhap ten sinh vien: ";
    getline(cin, name);
    cout << "Nhap ten mon hoc: ";
    getline(cin, subject);
    cout << "Nhap diem cua sinh vien: ";
    cin >> score;

    if (score > 10 || score < 0.0) cout << "Du lieu khong hop le!";
    else {
        if (score <= 3.9) score_text = 'F';
        else if (score >= 4.0 && score <= 5.4) score_text = 'D';
        else if (score >= 5.5 && score <= 6.9) score_text = 'C';
        else if (score >= 7.0 && score <= 8.4) score_text = 'B';
        else if (score >= 8.5) score_text = 'A';
        cout << "Sinh vien '" << name << "' duoc diem '" << score_text << "' mon " << subject;
    }
    
    return 0;
}