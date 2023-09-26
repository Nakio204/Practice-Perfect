#include <iostream>
#include <cmath>
using namespace std;

void nhapmang (int &n,int a[]){
	cout << "Nhap n = "; cin >> n;
   	for (int i = 0; i < n; i++){
        cout << "So thu " << i+1 << ": ";cin >> a[i];
  	}
}

bool ktraSNT(int n) {
	if(n == 1) return false;
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int maxSCP(int n, int a[]) {
	int max = -1;
	for(int i = 0; i < n; i++) {
		if(ktraSNT(a[i]) && a[i] > max) max = a[i];
	}
	return max;
}

int main(){
	int n, a[100], x;
    nhapmang(n, a);
    
    cout << "So nguyen to max la: " << maxSCP(n, a);
    
    return 0;
}