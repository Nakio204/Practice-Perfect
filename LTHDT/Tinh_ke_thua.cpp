#include <bits/stdc++.h>
using namespace std;

// base class: class cha
// derived class: class con

class Person {
    private:
        string name;
        string addr;
    public:
        Person(string name, string addre) {
            this->name = name;
            this->addr = addre;
        }
        void nhap() {
            getline(cin, name);
            getline(cin, addr);
        }
        string getName() {
            return this->name;
        }
        string getAddr() {
            return this->addr;
        }
        void setName(string name) {
            this->name = name;
        }
        void setAddr(string addr) {
            this->addr = addr;
        }
        void in() {
            cout << name << " " << addr << " ";
        }
};

class Student : public Person {
    private:
        float gpa;
    public:
        Student(string name, string addre, float gpa) {
            this->name = name;
            this->adrr = addre;
            this->gpa = gpa;
        }
        void nhap() {
            Person::nhap();
            cin >> gpa;
        }
        float getGpa() {
            return this->gpa;
        }
        void setGpa(float gpa) {
            this->gpa = gpa;
        }
        void in() {
            Person::in();
            cout << fixed << setprecision(2) << gpa << endl;
        }
};



int main() {
    Student s;
    s.nhap();
    s.in();

    return 0;
}