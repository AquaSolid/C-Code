#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void getString (char a[]){
	char c = '\0'; int i = 0;
	while( (c = getchar()) != '\n'){
		a[i++] = c;
	}	a[i] = '\0';
}

int areAnagrams(char a[], char b[]){
	int flag = 1;

	char current = '\0';
	int timesA = 1, timesB = 1;

	int i = 0, j = 0, k = 0;
	int x = strlen(a);
	int y = strlen(b); 
	
	if (x != y) return 0;

	for (i = 0; i < x; ++i) {
		timesA = 1; timesB = 1;
		current = a[i];

		for (j = 0; j < x; ++j) { // Times 
			
			if (current == a[j]) {
				timesA++;
			}

		}

		for (k = 0; k < y; ++k) {
			
			if (current == a[k]) {
				timesB++;
			}
		}

		if (timesA != timesB) {
			flag = 0;
			break;
		}
	}

	return flag;
}

/*
An anagram is a word, phrase, or name formed by rearranging
the letters of another, such as cinema, formed from iceman.
*/

int main(int argc, char const *argv[]) {
	char A[100], B[100];

	printf("Anagram Checker!\n");
	printf("Enter two words..\n");

	getString(A); getString(B);

	if (areAnagrams(A,B)) {
		printf("\'%s\' and \'%s\' are anagrams!\n", A,B);
	} else {
		printf("\'%s\' and \'%s\' are NOT anagrams!\n", A,B);
	}

	return 0;
}
