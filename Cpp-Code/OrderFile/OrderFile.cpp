#include <iostream>
#include <fstream>
using namespace std;

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort (int a[], int len){
	int i = 0, j = 0;
	for (i = 0; i < len-1; ++i) {
		for (j = i; j < len; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}

void rewindFile(fstream& file) {
	file.clear();
	file.seekg(0, file.beg);
} 

int linesOfFile (fstream& file) {
	rewindFile(file);
	int len = 0;
	string line;
	while(getline(file, line)) len++;
	
	// rewind the file
	rewindFile(file);

	return len;
}

void printFile (fstream& file) {
	rewindFile(file);
	string line;
	while(getline(file, line)) {
		cout << line << " ";
	} cout << endl;
	rewindFile(file);
}

int main(int argc, char const *argv[]) {
	int array[100];
	fstream numbers;

	numbers.open("numbers.txt");

	int length = linesOfFile(numbers);
	printf("Number of lines in file: %d\n", length);

	for (int i = 0; i < length; ++i) {
		numbers >> array[i];
	}

	printFile(numbers);

	bubbleSort(array, length);
	puts("Ordered array");

	for (int i = 0; i < length; ++i) {
		numbers << array[i] << endl;
		cout << array[i] << " ";
	} cout << endl;

	return 0;
}