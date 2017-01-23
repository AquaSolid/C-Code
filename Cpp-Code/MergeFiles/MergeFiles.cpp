#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	ifstream odds;
	ifstream evens;
	fstream numbers;

	int odd, even;

	odds.open("odds.txt");
	evens.open("evens.txt");

	if (odds.fail() || evens.fail()) {
		puts("Error opening a file");
	}

	numbers.open("numbers.txt");
	if (numbers.fail()) {
		puts("Error opening output file");
	}

	string line;
	
	puts("Printing the first file..");
	if (odds.is_open()) {
		while(!odds.eof()) {
			getline(odds, line);
			cout << line << endl;
		}
	}
	puts("Printing the second file..");
	if (evens.is_open()) {
		while(!evens.eof()) {
			getline(evens, line);
			cout << line << endl;
		}
	}
	odds.clear();
	odds.seekg(0, ios::beg);
	evens.clear();
	evens.seekg(0, ios::beg);
	if (odds.is_open() && evens.is_open()) {
		while(!odds.eof() || !evens.eof()){
			getline(odds, line);
			numbers << line << endl;
			getline(evens, line);
			numbers << line << endl;
		}
	}

	puts("Printing the output file..");
	numbers.clear();
	numbers.seekp(0, numbers.beg);
	if (numbers.is_open()) {
		while(!numbers.eof()) {
			getline(numbers, line);
			cout << line << endl;
		}
	}

	odds.close();
	evens.close();
	numbers.close();
	return 0;
}