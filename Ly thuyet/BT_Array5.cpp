#include <iostream>
#include <cmath>

using namespace std;

/* int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min1 = 1e9+1, min2 = 1e9+1;
    for(int i = 0; i < n; i++) {
        if(a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        }
        else if(a[i] < min2) {
            min2 = a[i];
        }
    }
    cout << min1 << " " << min2;

    return 0;
} */

/* int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max1 = -1e9-1, max2 = -1e9-1;
    for(int i = 0; i < n; i++) {
        if(a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2 && a[i] != max1) {
            max2 = a[i];
        }
    }
    if(max2 == -1e9-1) max2 = -1;
    cout << max1 << " " << max2;

    return 0;
} */

/* int check(int n);

int main() {
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(check(a[i])) {
            b[count] = a[i];
            count += 1;
        }
    }
    cout << count << endl;
    for(int i = 0; i < count; i++) {
        cout << b[i] << " ";
    }
}

int check(int n) {
    while(n) {
        int r = n % 10;
        if(r % 2 == 0) return 0;
        n /= 10;
    }
    return 1;
} */

/* int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int max1 = -1e9-1, max2 = -1e9-1;
    for(int i = 0; i < n; i++) {
        if(a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2 && a[i] != max1) {
            max2 = a[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] < max2) cout << a[i] << " ";
    }

    return 0;
} */

/* int check(int n) {
    int c1 = 0, c9 = 0;
    while(n) {
        int r = n % 10;
        if(r == 1) c1 = 1;
        if(r == 9) c9 = 1;
        n /= 10;
    }
    return c1 && c9;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ok = 0;
    for(int i = 0; i < n; i++) {
        if(check(a[i])) {
            cout << a[i];
            ok = 1;
        }
    }
    if(!ok) cout << -1;

    return 0;
} */

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(i == 0 && a[0] * a[1] < 0) cout << a[i] << " ";

        else if(i == n - 1 && a[n-1] * a[n-2] < 0) cout << a[i] << " ";
        
        else if(a[i] * a[i-1] < 0 || a[i-1] * a[i+1] < 0) {
            cout << a[i] << " ";
        } 
    }
    
    return 0;
}