#include <stdio.h>
#include <stdlib.h>

void getString (char a[]) {
	int i = 0; char c = '\0';
	while( (c = getchar()) && c != '\n') {
		a[i++] = c;
	} a[i] = '\0';
}

int main(int argc, char const *argv[]) {
	FILE *input1 = NULL;  FILE *input2 = NULL; FILE *output = NULL;
	char input_file1[100];
	printf("Enter name of source file to copy: ");
	getString(input_file1);

	input1 = fopen(input_file1, "r");
	if (input1 == NULL) {
		perror("Error in opening file");
		exit(EXIT_FAILURE);
	}

	char input_file2[100];
	printf("Enter name of source file to copy: ");
	getString(input_file2);

	input2 = fopen(input_file2, "r");
	if (input2 == NULL) {
		fclose(input1);
		perror("Error in opening file");
		exit(EXIT_FAILURE);
	}

	char output_file[100];
	printf("Enter name of output file: ");
	getString(output_file);

	output = fopen(output_file, "w");
	if (output == NULL) {
		fclose(input1); fclose(input2);
		perror("Error in opening file");
		exit(EXIT_FAILURE);
	}

	char line[100];
	while (fgets(line, 100, input1)) {
		fputs(line, output);
	}
	while (fgets(line, 100, input2)) {
		fputs(line, output);
	}

	fclose(input1); fclose(input2); fclose(output);
	return EXIT_SUCCESS;
	return 0;
}