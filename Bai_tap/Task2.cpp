#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    unsigned int r;
    cin >> r;

    cout << fixed << setprecision(3) << 2 * 3.14 * r << " " << 3.14 * r * r;

    return 0;
}