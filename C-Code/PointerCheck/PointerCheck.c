#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>
struct node {
	int val;
	struct node *next;
};

struct node *head = NULL;
struct node *curr = NULL;

struct node* create_list (int a) {
	struct node *ptr = NULL;
	ptr = (struct node *) malloc(sizeof(struct node));

	if (ptr == NULL) {
		printf("Node equals NULL, creating of node failed.\n");
		return NULL;
	}

	ptr->val = a;
	ptr->next = NULL;

	head = curr = ptr;
	return ptr;}

struct node* add_to_list (int a, int toEnd) {
	if (head == NULL) {
		return create_list(a);
	}

	/*
	if (toEnd) {
		printf("Adding node to the end of the list with value %d\n", a);
	} else {
		printf("Adding node to the beginning of the list with value %d\n", a);
	}
	*/

	struct node *ptr = NULL;
	ptr = (struct node *) malloc(sizeof(struct node));

	if (ptr == NULL) {
		printf("Node equals NULL, creating of node failed.\n");
		return NULL;
	}

	ptr->val = a;
	ptr->next = NULL;

	if (toEnd) {
		curr->next = ptr;
		curr = ptr;
	} else {
		ptr->next = head;
		head = ptr;
	}

	return ptr;}

void print_list (void) {
	struct node *ptr = head;
	printf("Printing...\n");
	while (ptr != NULL){
		printf("%d ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");
}

int lenght_list (void) {
	int len = 0;
	struct node *ptr = head;
	while (ptr != NULL){
		len += 1;
		ptr = ptr->next;
	}
	return len;
}

void user_input_list (void) {
	char *input = NULL;
	input = (char *) malloc(sizeof(char));
	printf("Enter number to populate the list..\n");
	while (scanf("%d", input)) {
		add_to_list(*input, 1);
	}
	free(input);

	// Cleans scanf buffer
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) continue;
}

int main(int argc, char const *argv[]) {
	int i = 0;
	struct node *ptr = NULL;

	user_input_list();

	user_input_list();
	
	print_list();
	printf("%d\n", lenght_list());
	
	return 0;
}

/*

	int *ptr = NULL;
	ptr = (int *) malloc(sizeof(int));

	if (ptr == NULL) {
		printf("Error allocating memory\n");
		return 1;
	}
	printf("Enter a number..\n");
	scanf("%d", ptr);
	printf("You entered %d located at %p\n", *ptr, ptr);

	free(ptr);

*/

/*


	int *arr = NULL;
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

*/