#include <stdio.h>
#include <stdlib.h>

void getString (char a[]) {
	int i = 0; char c = '\0';
	while( (c = getchar()) && c != '\n') {
		a[i++] = c;
	} a[i] = '\0';
}

int main(int argc, char const *argv[]) {
	FILE *input = NULL; FILE *output = NULL;
	char input_file[100];
	printf("Enter name of source file to copy: ");
	getString(input_file);

	input = fopen(input_file, "r");
	if (input == NULL) {
		perror("Error in opening file");
		exit(EXIT_FAILURE);
	}

	char output_file[100];
	printf("Enter name of output file: ");
	getString(output_file);

	output = fopen(output_file, "w");
	if (output == NULL) {
		fclose(input);
		perror("Error in opening file");
		exit(EXIT_FAILURE);
	}

	char line[100];
	while (fgets(line, 100, input)) {
		fputs(line, output);
	}
	fclose(input); fclose(output);
	return EXIT_SUCCESS;
}