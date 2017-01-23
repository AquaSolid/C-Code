#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/*4
len = 3 * 2 - 1 = 6 - 1 = 5
half = 5 / 2 - i = 3 - i
00300
02320
12321

*/
int main(int argc, char const *argv[]) {
	int i = 0, j = 0, size = 0;
	printf("Enter a size for the diamond..\n");
	scanf("%d", &size);

	int len = size * 2 - 1;
	int half = len / 2;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < len; ++j) {
			if (half - i - 1 < j && j < half + i + 1) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	for (i = size; i > 1; --i) {
		for (j = 0; j < len; ++j) {
			if (half - i + 1 < j && j < half + i - 1) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}

	return EXIT_SUCCESS;
}