#include <iostream>
#include <cmath>
using namespace std;

float tinhtong(float a);

int main() {
    float n;
    cout << "Nhap N: ";
    cin >> n;
    cout << "S = " << tinhtong(n);

    return 0;
}

float tinhtong(float a) {
    float sum = 1;
    for(int i = 1; i <= a; i++){
        sum += 3 * i; 
    }
    return sum;
} 