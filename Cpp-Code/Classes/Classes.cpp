#include <iostream>
#include <string>
using namespace std;

class Person {
	string name, surname;
	int age;
public:
	void setValues (string n, string s, int a) {
		name = n;
		surname = s;
		age = a;
	}
	void printPerson () {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << endl;
	}
};

int main() {
	Person guy, girl;
	guy.setValues("Mike", "Wazowski", 23);
	guy.printPerson();
	girl.setValues("Lila", "Wirrow", 21);
	girl.printPerson();
	return 0;
}