#include <iostream>
using namespace std;

void nhapmang (int &n,int a[]){
	do{
		cout << "Nhap n = "; cin >> n;
	}while(n <= 0|| n >= 50);
   for (int i = 0; i < n; i++){
        cout << "So thu " << i+1 << ": ";cin >> a[i];
   }
}

void insertx(int &n, int a[], int x){
	n++;
	for (int i = n; i > 0; i--){
		a[i] = a[i-1];
	}
	a[0] = x;
}

void xuatmang(int n, int a[], int x){
	cout << "Day so:";
    for (int i = 0; i < n; i++){
        	cout << " " << a[i];
    }
	
}
	
int main(){
	int n, a[100], x;
    nhapmang(n, a);
    cout << "Cho x = ";cin >> x;
	insertx(n, a, x);
	xuatmang(n, a, x);
    return 0;
}