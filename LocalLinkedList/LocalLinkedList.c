#include <stdio.h>
#include <malloc.h>

#define VARNAME(Var) (#Var)

struct node {
	int val;
	struct node *next;
};

struct node* create_list (int a, struct node **head, struct node **curr) {
	struct node *ptr = NULL;
	ptr = (struct node *) malloc(sizeof(struct node));

	if (ptr == NULL) {
		printf("Node equals NULL, creating of node failed.\n");
		return NULL;
	}

	ptr->val = a;
	ptr->next = NULL;

	*head = *curr = ptr;
	return ptr;}


struct node* add_to_list (int a, int toEnd, struct node **head, struct node **curr) {
	if ( (*head) == NULL) {
		return create_list(a, head, curr);
	}

	struct node *ptr = NULL;
	ptr = (struct node *) malloc(sizeof(struct node));

	if (ptr == NULL) {
		printf("Node equals NULL, creating of node failed.\n");
		return NULL;
	}

	ptr->val = a;
	ptr->next = NULL;

	if (toEnd) {
		(*curr)->next = ptr;
		*curr = ptr;
	} else {
		ptr->next = *head;
		*head = ptr;
	}

	return ptr;}

void print_list (struct node **head, char *varname) {
	struct node *ptr = *head;
	printf("Printing list %s...\n", varname);
	while (ptr != NULL){
		printf("%d ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");
}

int lenght_list (struct node **head) {
	int len = 0;
	struct node *ptr = *head;
	while (ptr != NULL){
		len += 1;
		ptr = ptr->next;
	}
	return len;
}

void user_input_list (struct node **head, struct node **curr) {
	char *input = NULL;
	input = (char *) malloc(sizeof(char));
	printf("Enter number to populate the list..\n");
	while (scanf("%d", input)) {
		add_to_list(*input, 1, head, curr);
	}
	free(input);

	// Cleans scanf buffer
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) continue;
}

int main(int argc, char const *argv[]) {

	struct node *head = NULL;
	struct node *curr = NULL;

	for (int i = 0; i < 3; ++i) {
		add_to_list(i, 1, &head, &curr);
	}
	
	print_list(&head, VARNAME(*head));
	user_input_list(&head, &curr);

	print_list(&head, VARNAME(**head));
	printf("Length of the list: %d\n", lenght_list(&head));

	return 0;
}