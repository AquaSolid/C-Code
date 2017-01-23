#include <stdio.h>
#include <stdlib.h>

int firstDigit (int a) {
	while(a > 9){
		a /= 10;
	}
	return a;
}

int lastDigit (int a){
	return a % 10;
}

int flipDigit (int a) {
	int flip = 0;
	while(a) {
		flip *= 10;
		flip += lastDigit(a);
		a /= 10;
	}
	return flip;
}

int middleDigit (int a) {
	a /= 10;
	a = flipDigit(a);
	a /= 10;
	return a;
}

int main(int argc, char const *argv[]) {
	int from = 0, to = 0;
	int i = 0, times = 0;
	int middle = 0, last = 0, first = 0, quotient = 0;
	scanf("%d %d\n", &from, &to);
	for (i = from; i < to; ++i) {

		middle = middleDigit(i);
		last = lastDigit(i);
		first = firstDigit(i);
		quotient = middle / (last + first);

		if (middle == (last + first) * quotient && quotient != 0) {
			printf("%d -> (%d == (%d + %d) * %d)\n", i, middle, last, first, quotient);	
			++times;
		}
		
	}
	printf("%d\n", times);
	return 0;
}		