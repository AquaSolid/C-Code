#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void getString(char a[]){
	int i = 0; char c = '\0';
	while((c = getchar()) != '\n'){
		a[i++] = c;
	} a[i] = '\0';
}

int main(int argc, char const **argv){

	char a[100];
	printf("Enter a phrase: ");
	getString(a);

	puts(a);

	int i = 0;
	for(i = 0; i < strlen(a); i++){
		printf("%c,", a[i]);
	} printf("\n");

	return EXIT_SUCCESS;
}
