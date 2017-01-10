#include <stdio.h>
#include <malloc.h>

#define VARNAME(Var) (#Var)

struct node {
	int val;
	struct node *next;};

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

struct node* search_in_list (int val, struct node **prev, struct node **head) {
	struct node *ptr = *head;
	struct node *tmp = NULL;
	int found = 0;

	while (ptr != NULL) {
		if (ptr->val == val) {
			found = 1;
			break;
		} else {
			tmp = ptr;
			ptr = ptr->next;
		}
	}

	if (found) {
		if (prev) {
			*prev = tmp;
		}
		return ptr;
	} else {
		return NULL;
	}}

int position_of_node (struct node *ptr, struct node **head) {
	if (ptr = NULL) {
		return 0;
	} 
	struct node *i = *head;
	int pos = 0;
	while (i != ptr) {
		i = i->next;
		pos += 1;
	}
	return pos;}

int delete_from_list (int val, struct node **head, struct node **curr) {
	struct node *prev = *head;
	struct node *del = NULL;

	del = search_in_list(val, &prev, head);
	printf("Deleting %d..\n", val);
	if (del == NULL) {
		return -1;
	} else {
		if (prev != NULL)
		{
			prev->next = del->next;
		}
		if (del == *curr) {
			*curr = prev;
		} else if (del == *head) {
			*head = del->next;
		}
	}

	free(del); del = NULL;}

int lenght_list (struct node **head) {
	int len = 0;
	struct node *ptr = *head;
	while (ptr != NULL){
		len += 1;
		ptr = ptr->next;
	}
	return len;}

void print_list (struct node **head, char *varname) {
	struct node *ptr = *head;
	printf("Printing list %s with Length = %d...\n", varname, lenght_list(head));
	while (ptr != NULL){
		printf("%d ", ptr->val);
		ptr = ptr->next;
	}
	printf("\n");}

void user_input_list (struct node **head, struct node **curr) {
	char *input = NULL;
	input = (char *) malloc(sizeof(char));
	printf("Enter number(s) to populate the list..(char to exit)\n");
	while (scanf("%d", input)) {
		add_to_list(*input, 1, head, curr);
	}
	free(input);

	// Cleans scanf buffer
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) continue;}

void print_menu () {
	printf("p - Print the list\n");
	printf("a - Add an element to the list\n");
	printf("s - Search for an element in the list\n");
	printf("d - Delete an element from the list\n");
	printf("e - Exit the program\n");}

int main(int argc, char const *argv[]) {
	struct node *head = NULL;
	struct node *curr = NULL;
	struct node *ptr = NULL;
	printf("Command(m for menu): ");
	char c = '\0';
	while ((c = getchar()) && c != 'e') {
		if (c == '\n') continue;
		
		if (c == 'm') { 
			print_menu();
		} else if (c == 'p') {
			print_list(&head, VARNAME(*head));
		} else if (c == 'a') {
			user_input_list(&head, &curr);
		} else if (c == 's') {
			int toSearch = 0;
			printf("Enter a value to search for: ");
			scanf("%d", &toSearch);
			ptr = search_in_list(toSearch, NULL, &head);
			if (ptr == NULL) {
				printf("No such element..\n");
			} else {
				printf("Value [%d] found at position [%d] with address [%p]\n", ptr->val, position_of_node(ptr, &head), ptr);
			}
		} else if (c == 'd') {
			int toDelete = 0;
			printf("Enter a value to delete: ");
			scanf("%d", &toDelete);
			ptr = search_in_list(toDelete, NULL, &head);
			if (ptr == NULL) {
				printf("No such element..\n");
			} else {
				delete_from_list(toDelete, &head, &curr);
				printf("Value [%d] has been deleted!\n", toDelete);
			}
		}
		printf("Command(m for menu): ");
	}
	return 0;
}

/*
	for (int i = 0; i < 3; ++i) {
		add_to_list(i, 1, &head, &curr);
	}
	
	print_list(&head, VARNAME(*head));
	user_input_list(&head, &curr);

	print_list(&head, VARNAME(**head));
	printf("Length of the list: %d\n", lenght_list(&head));

	struct node *ptr = search_in_list(2, NULL, &head);
	if (ptr == NULL) {
		printf("No such element..\n");
	} else {
		printf("Search passed! val = %d\n", ptr->val);
	}

	delete_from_list(2, &head, &curr);
	print_list(&head, VARNAME(**head));
*/