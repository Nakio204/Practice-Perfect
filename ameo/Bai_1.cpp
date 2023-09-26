#include <iostream>
#include <iomanip>

using namespace std;

int main(){
 
    int a = 500, b = 350;
    int tong = a + b;
    int hieu = a - b;
    int tich = a * b;
    float thuong = float(a) / b;
    int du = a % b;
    cout << tong << " " << hieu << " " << tich << " " << thuong << " " << du;
/*
    int a = 100;
    int b = ++a;
    cout << a << " " << b;
    
    int a = 100, b = 200;
    bool ok = a > b;
    cout << ok << endl;
    
    int a = 200, b = 200, res;
    res = !(a == b);
    cout << res;
 */

    return 0;
}