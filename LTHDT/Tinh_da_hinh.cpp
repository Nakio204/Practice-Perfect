#include <bits/stdc++.h>
using namespace std;

class Pet {
	public:
		virtual string getSound() {
			return "Say it!\n";
		}
};

class Cat : public Pet {
	public:
		string getSound() {
			return "Meow meow!\n";
		}	
};

int main() {
	Pet *pet = new Cat();
	cout << pet->getSound();

	return 0;
}