#include <iostream>
using namespace std;

void nhapMang2D(int arr[][100], int n, int m) {
    cout << "Nhap cac phan tu cua mang: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "Nhap phan tu thu arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
}

void hienThiMang2D(int arr[][100], int n, int m) {
    cout << "Mang hai chieu da nhap:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;

    cout << "Nhap so hang n: ";
    cin >> n;

    cout << "Nhap so cot m: ";
    cin >> m;

    int arr[100][100];

    nhapMang2D(arr, n, m);

    hienThiMang2D(arr, n, m);

    return 0;
}
