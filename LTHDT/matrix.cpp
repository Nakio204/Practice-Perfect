#include <iostream>
using namespace std;

class Matrix {
    public:
        Matrix();
        Matrix(const Matrix &);
        void Nhap();
        void Xuat();
        Matrix Cong(const Matrix &);
        int check_Cong(const Matrix &);
        friend Matrix Nhan(const Matrix &, int);
        friend Matrix Nhan2(const Matrix &, const Matrix &);
    private:
        int m;
        int n;
        double elem[100][100];
};

Matrix::Matrix() {
    this->m = this->n = 0;
}

Matrix::Matrix(const Matrix &b) {
    this->m = b.m;
    this->n = b.n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            this->elem[i][j] = b.elem[i][j];
        }
    }
}

void Matrix::Nhap() {
    cout << "Nhap so hang: "; cin >> m;
    cout << "Nhap so cot: "; cin >> n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Nhap elem[" << i << "]" << "[" << j << "]: ";
            cin >> elem[i][j];
        }
    }
}

void Matrix::Xuat() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << elem[i][j] << " ";
        }
        cout << endl;
    }
}   


Matrix Matrix::Cong(const Matrix &x) {
    if(!(this->m == x.m && this->n == x.n)) {
        cout << "Khong the cong hai ma tran khac cap!" << endl;
    }
    else {
        Matrix res;
        res.m = this->m;
        res.n = this->n;  
        for(int i = 0; i < this->m; i++) {
            for(int j = 0; j < this->n; j++) {
                res.elem[i][j] = this->elem[i][j] + x.elem[i][j];
            }
        }  
        return res;
    }
}

int Matrix::check_Cong(const Matrix &x) {
    if(!(this->m == x.m && this->n == x.n)) {
        return 0;
    }

    return 1;
}

Matrix Nhan(const Matrix &x, int k) {
    Matrix res;
    res.m = x.m;
    res.n = x.n;

    for(int i = 0; i < res.m; i++) {
        for(int j = 0; j < res.n; j++) {
            res.elem[i][j] = k * x.elem[i][j];
        }
    }
    return res;
}

Matrix Nhan2(const Matrix &x, const Matrix &y) {
    Matrix res;
    res.m = x.m;
    res.n = x.n;

    for(int i = 0; i < res.m; i++) {
        for(int j = 0; j < res.n; j++) {
            res.elem[i][j] = x.elem[i][j] * y.elem[i][j];
        }
    }
    return res;
}

int main() {
    while(1) {
        int lc;
        cout << "----------NAKIO'S MENU----------" << endl;
        cout << "1. Cong hai ma tran" << endl;
        cout << "2. Check tong 2 ma tran" << endl;
        cout << "3. Nhan ma tran voi mot so K" << endl;
        cout << "4. Nhan hai ma tran" << endl;
        cout << "0. Thoat menu" << endl;
        cout << "--------------------------------" << endl;
        cout << "Nhap lua chon: "; cin >> lc;

        if(lc == 1) {
            Matrix a, b, c;
            cout << "Nhap ma tran A:" << endl;
            a.Nhap();
            cout << "Nhap ma tran B:" << endl;
            b.Nhap();  
            
            cout << "Ma tran A:" << endl;
            a.Xuat();
            cout << "Ma tran B:" << endl;
            b.Xuat();

            c = a.Cong(b);
            cout << "Tong hai ma tran la: " << endl;
            c.Xuat();
        }
        else if(lc == 2) {
            Matrix a, b;
            cout << "Nhap ma tran A:" << endl;
            a.Nhap();
            cout << "Nhap ma tran B:" << endl;
            b.Nhap(); 

            int res = a.check_Cong(b);
            if(res) cout << endl << "Hai ma tran co the cong!" << endl;
            else cout << endl << "Khong the cong hai ma tran khac cap!" << endl;
        }
        else if(lc == 3) {
            Matrix a, c;
            int k;
            cout << "Nhap ma tran A:" << endl;
            a.Nhap();
            cout << "Ma tran A:" << endl;
            a.Xuat();

            cout << "Nhap k: "; cin >> k;
            c = Nhan(a, k);
            cout << "Tich ma tran A * k la: " << endl;
            c.Xuat();
        }
        else if(lc == 4) {
            Matrix a, b, c;
            cout << "Nhap ma tran A:" << endl;
            a.Nhap();
            cout << "Nhap ma tran B:" << endl;
            b.Nhap();  
            
            cout << "Ma tran A:" << endl;
            a.Xuat();
            cout << "Ma tran B:" << endl;
            b.Xuat();

            c = Nhan2(a, b);
            cout << "Tich hai ma tran la: " << endl;
            c.Xuat();
        }
        else {
            break;
        }

    }
    return 0;
}