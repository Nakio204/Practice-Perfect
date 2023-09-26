#include <iostream>

using namespace std;

void inputArray(int &n, int a[100]){
	cout << "N = "; cin >> n;
	for (int i = 0; i < n; i++){
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}	
}

long long maxx(int &n, const int a[100]) {
	int max = a[0];
	for(int i = 0; i < n; i++) {
		if(a[i] > max) max = a[i];
	}
	return max;
}

long long countArray(const int &n, const int a[100], const int &max){
	int dem = 0;
	for (int i = 0; i < n; i++){
		if(a[i] == max) {
			dem++;
		}
	}
	return dem;
}
int main(){
	int n, a[100], max;
	inputArray(n, a);
	
	long long maxVal = maxx(n, a);
	cout << "Gia tri lon nhat cua A: " << maxVal << endl;
	
	long long cnt = countArray(n, a, maxVal);
	cout << "So phan tu co gia tri lon nhat: " << cnt << endl;
	
	return 0;
}