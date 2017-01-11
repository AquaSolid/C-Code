#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	int random = 0; 
	int i = 0;
	for (i = 0; i < 10; i++) {
		random = rand() % 100;
		printf("%d ", random);
	} 
	printf("\n");
	return 0;
}