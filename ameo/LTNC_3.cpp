#include <iostream>
using namespace std;

string swap_score(float n, string a, string b);

int main(){
	string tenSV, monhoc, diem_chu;
	float diem;

	cout << "Nhap ten sinh vien: "; 
    getline(cin, tenSV);
	cout << "Nhap ten mon hoc: "; 
    getline(cin, monhoc);
	cout << "Nhap diem: "; 
    cin >> diem;

    cout << swap_score(diem, tenSV, monhoc);

    return 0;
}

string swap_score(float n, string a, string b) {
    string result;
    char score_text;

    if(n < 0 || n > 10) result = "Du lieu khong hop le!";
	else {
		if(n >= 8.5) score_text = 'A'; 
		else if(n >= 7) score_text = 'B';
		else if(n >= 5.5) score_text = 'C';
		else if(n >= 4) score_text = 'D';
		else score_text = 'F';
		result = "Sinh vien '" + a + "' duoc diem '" + score_text + "' mon '" + b + "'\n";
    }

    return result;
}
