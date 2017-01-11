#include <stdio.h>
#include <stdlib.h>

void getString (char a[]) {
	int i = 0; char c = '\0';
	while( (c = getchar()) && c != '\n') {
		a[i++] = c;
	} a[i] = '\0';
}

int main(int argc, char const *argv[])
{
	FILE *input = NULL;
	char file_name[30];
	printf("Enter the name of the file: ");
	getString(file_name);

	input = fopen(file_name, "r");

	if (input == NULL) {
		perror("Error while opening the file");
		exit(EXIT_FAILURE);
	}

	char str[100];
	while(!feof(input)){
		fgets(str, 100, input);
		printf("%s", str);
	}
	fclose(input);
	return EXIT_SUCCESS;
}