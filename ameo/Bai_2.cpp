#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n;
    cout << "Nhap N: "; cin >> n;
    if( n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12 ){
        cout << "31\n";
    } else if( n == 4 || n == 6 || n == 9 || n == 11){
        cout << "30\n";
    } else{
        cout << "M bi dien a ?\n";
    }

    int month;
    cout << "Month: "; cin >> month;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "31\n";
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << "30\n";
    return 0;
}
}