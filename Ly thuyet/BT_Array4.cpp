#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ptu_min = -1e9-1, idx;
    for(int i = 0; i < n; i++) {
        if(a[i] > ptu_min) {
            ptu_min = a[i];
            idx = i;
        }
    }
    cout << idx;

    return 0;
}