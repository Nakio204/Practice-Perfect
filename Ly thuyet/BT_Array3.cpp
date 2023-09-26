#include <iostream>
#include <cmath>

int nt(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return 0;
    }
    return n > 1;
}

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(nt(a[i])) cout << a[i] << " ";
    }

    return 0;
}