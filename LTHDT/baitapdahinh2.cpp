#include <iostream>
using namespace std;

class Employee {
	private:
		string name;
		int paymentPerHour;
	public:
		Employee() {this->name = ""; this->paymentPerHour = 0;}

		Employee(string name, int pay) {this->name = name; this->paymentPerHour = pay;}

		~Employee(){};

		string getName() {return this->name;}

		void setName(string ten) {this->name = ten;}

		int getPay() {return this->paymentPerHour;}

		void setPay(int pay) {this->paymentPerHour = pay;}

		virtual int calculateSalary() {return 1;}
};

class PartTimeEmployee : public Employee {
	private:
		int workingHours;
	public:
		PartTimeEmployee() {this->workingHours = 0;}
		
		PartTimeEmployee(string name, int paymentPerHour, int workingHours) : Employee(name, paymentPerHour) {this->workingHours = workingHours;}
		
		~PartTimeEmployee(){};
		
		int getHour() {return this->workingHours;}
		
		void setHour(int hour) {this->workingHours = hour;}
		
		int calculateSalary() {return this->workingHours * getPay();}
};

class FullTimeEmployee : public Employee {
	public:
		FullTimeEmployee(string name, int paymentPerHour) : Employee(name, paymentPerHour) {}
		int calculateSalary() {return 8 * getPay();}
};

int main() {
	Employee *employee1 = new PartTimeEmployee("Trung", 45000, 7);
	cout << "Name: " << employee1->getName() << endl;
	cout << "Salary per day: " << employee1->calculateSalary() << endl;
	cout << "\n";
	Employee *employee2 = new FullTimeEmployee("Linh", 65000);
	cout << "Name: " << employee2->getName() << endl;
	cout << "Salary per day: " << employee2->calculateSalary() << endl;
	
	return 0;
}