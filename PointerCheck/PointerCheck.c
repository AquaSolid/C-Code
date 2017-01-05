#include <stdio.h>
#include <malloc.h>

int arrlen (int *ptr){
	return sizeof(ptr)/sizeof(*ptr);
}

int main(int argc, char const *argv[]) {
	int *ptr = NULL;
	int *arr = NULL;
	
	ptr = (int *) malloc(sizeof(int));

	if (ptr == NULL) {
		printf("Error allocating memory\n");
		return 1;
	}
	printf("Enter a number..\n");
	scanf("%d", ptr);
	printf("You entered %d located at %p\n", *ptr, ptr);

	free(ptr);

	arr = (int *) malloc(sizeof(int) * 5);

	if (arr == NULL) {
		printf("Error allocating memory\n");
		return 1;
	}

	printf("Enter number for the array..\n");
	int arrlen = 0, i = 0;
	while (scanf("%d", (arr + i))){
		*(arr + i) = i;
		arrlen++;
		i++;
	}

	for (i = 0; i < arrlen; ++i) {
		printf("%d ", *(arr + i));
	} printf("\n");
	printf("Array length: %d\n", arrlen);

	free(arr);

	return 0;
}