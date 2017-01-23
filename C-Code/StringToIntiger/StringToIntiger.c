#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void getString(char a[]){
	char c = '\0'; int i = 0;
	while( (c = getchar()) != '\n'){
		a[i++] = c;
	} a[i] = '\0';
}

int StringToIntger(char a[]){
	int i = 0;
	int len = strlen(a);
	int Integer = 0, sign = 1;
	for (i = 0; i < len; ++i) {

		if (a[i] == '-') {
			sign = (-1);
		}

		Integer *= 10;
		if (isdigit(a[i])) {
			Integer += a[i] - '0';
		}
	}
	return sign * Integer;
}

int main(int argc, char const *argv[]) {
	char A[100];
	getString(A);
	printf("%s\n", A);
	printf("%d\n", StringToIntger(A));
	return EXIT_SUCCESS;
}