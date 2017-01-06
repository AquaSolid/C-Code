#include <stdio.h>

int numberOfDigits (int a);
int forDigits (int a);
int martinWay (int a);

int sumOfDigits (int a) {
	int sumOfDigits = 0;

	while(a > 0) {
		sumOfDigits += a%10;
		a /= 10;
	}

	return sumOfDigits;
}

int flipNumber (int a) {
	int flip = 0;

	while (a > 0) {
		flip *= 10;
		flip += a%10;
		
		a /= 10;
	}

	return flip;
}

int upNumber (int a) {
	int new = 0;
	while (a > 0) {
		new *= 10;
		new += a%10;
		new += 1;
		a /= 10;
	}
	return flipNumber(new);
}

int main(int argc, char const *argv[]) {
	int x = 1234;

	printf("%d\n", sumOfDigits(x));

	return 0;
}

int numberOfDigits (int a) {
	int digits = 0;
	while (a > 0) {
		digits += 1;
		a /= 10;
	}
	return digits;
}

int forDigits (int a) {
	int digits = 0;
	int i = 0;

	for (i = a; i > 0; i /= 10) {
		digits++;
	}

	return digits;
}

int martinWay (int a) {
	int i = 0, digits = 0;
	for (i = a; i > 0; i /= 10) {
		digits++;
	}
	return digits;
}





