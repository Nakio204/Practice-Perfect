#include <bits/stdc++.h>
using namespace std;

// base class: class cha
// derived class: class con

class A {
    public:
        A() {
            cout << "Constructor cua lop A\n";
        }
        ~A() {
            cout << "Destructor cua lop A\n";
        }
        void xinchao() {
            cout << "Xin chao A\n";
        }
};

class B {
    public:
        B() {
            cout << "Constructor cua lop B\n"; // Goi ham tao cua lop cha truoc
        }
        ~B() {
            cout << "Destructor cua lop B\n"; // Goi ham huy cua lop con truoc
        }
        void xinchao() {
            cout << "Xin chao B\n";
        }        
};

class C: public A, public B {
    public:
        C() {
            cout << "Constructor cua lop C\n";
        }
        ~C() {
            cout << "Destructor cua lop C\n";
        }
        // void xinchao() {
        //     cout << "Xin chao C\n";
        // }
};


int main() {
    C object;
    object.xinchao();

    return 0;
}