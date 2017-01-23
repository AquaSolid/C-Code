#include <iostream>
using namespace std;

int main(){
	int x = 0, y = 0;
	char a[100], b[100];

	cout << "Enter two numbers: ";
	cin >> x >> y;
	cout << "Their sum is " << x+y << endl;

	cout << "Enter two strings: ";
	cin >> a >> b;
	cout << "You entered: " << a <<  b  << endl; 

	return 0;
}
