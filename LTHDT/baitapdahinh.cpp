#include <iostream>
using namespace std;

class Person {
	private:
		string name, address;
	public:
		Person() {
			this->name = this->address = "";
		};
		Person(string ten, string dc) {
			this->name = ten;
			this->address = dc;	
		}
		void setName(string name) {
			this->name = name;
		}		
		string getTen() {
			return this->name;
		}
		void setAdd(string add) {
			this->address = add;
		}
		string getAdd() {
			return this->address;
		}
		virtual void display() {
			cout << "Ten: " << this->name << endl;
			cout << "Dia chi: " << this->address << endl;
		}
};

class Employee : public Person {
	private:
		int salary;
	public:
		Employee() {
			this->salary = 0;
		}
		Employee(string name, string address, int salary) : Person(name, address) {
			this->salary = salary;
		};
		void setSalary(int sala) {
			this->salary = sala;
		}
		int getSalary() {
			return this->salary;
		}
		void display() {
			Person::display();
			cout << "Luong: " << this->salary << endl;
		}
};

class Customer : public Person {
	private:
		int balance;
	public:
		Customer() {this->balance = 0;}
		Customer(string name, string address, int balance) : Person(name, address) {
			this->balance = balance;
		}
		int getBalan() {
			return this->balance;
		}
		void setBalan(int balan) {
			this->balance = balan;
		}
		void display() {
			Person::display();
			cout << "So du tai khoan: " << this->balance << endl;
		}
		
};

int main() {
	Person *Per;
	
	Per = new Employee("Quan", "Hanoi", 5000);
	Per->display();
	cout << endl;
	Per = new Customer("Nakio", "Hanam", 3500);
	Per->display();
	
	
	
	return 0;
}