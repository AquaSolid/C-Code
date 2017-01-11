#include <stdio.h>
#include <stdlib.h>

void getString (char a[]) {
	int i = 0; char c = '\0';
	while( (c = getchar()) && c != '\n') {
		a[i++] = c;
	} a[i] = '\0';
}

int main(int argc, char const *argv[]) {
	char input_file[100];
	printf("Enter name of file to delete: ");
	getString(input_file);

	if (!remove(input_file)) {
		printf("%s deleted succesfully!\n", input_file);
	} else {
		printf("Unable to delete %s\n", input_file);
		perror("Error");
	}

	return EXIT_SUCCESS;
}