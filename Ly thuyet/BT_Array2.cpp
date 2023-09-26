#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dem_c = 0, dem_l = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 == 0) dem_c += 1;
        else dem_l += 1;
    }
    cout << dem_c << " " << dem_l;

    return 0;
}