#include<iostream>
#include<iomanip>
#include<math.h>
 
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    cout << fixed << setprecision(2) << (a + b) << " " << (a - b) << " " << (1ll * a * b) << " " << (1.0*a / b);
    
    return 0;
}