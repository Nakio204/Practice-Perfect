#include <iostream>
#include <cmath>

using namespace std;

bool snt(int x) {
    for(int i = 2; i <= sqrt(x); i++){
        if (x % i == 0) return false;
    }
    return x > 1;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int &x : a) cin >> x; 
    for(int x : a) {
        if(snt(x)) cout << x << " ";
    }

    return 0;
}