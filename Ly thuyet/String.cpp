//  Một số hàm kí tự
//  tolower(int char): chuyển thành kí tự in thường
//  toupper(int char): chuyển thành kí tự in hoa
//  islower(int char): kiểm tra xem có kí tự in thường không 
//  isupper(int char): kiểm tra xem có kí tự in hoa không
//  isdigit(int char): kiểm tra xem có kí số không
//  isalpha(int char): kiểm tra xem có

//  Bài tập: 

#include <iostream>
using namespace std;

/* int main() {
    string str;
    cout << "Nhap vao mot xau ki tu: ";
    getline(cin, str);
    int cnt = 0;
    for(int i = 1; i <= str.length(); i++) {
        cnt += 1;
    }
    cout << "So ki tu la: " << cnt;

    return 0;
} */

int main() {
    string str_new, str_default = "she likes cats";
    cout << "Nhap vao mot xau ki tu: ";
    getline(cin, str_new);
    

    cout << str_default << endl << str_new;

    return 0;
}