#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* next;
};

void push(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->val = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printHead(struct node* head) {
    printf("enter print.\n");
    struct node* current = head;
	while(current!=NULL) {
		printf("%d", current->val);
		current = current->next;
	}
	printf ("\n");
}


// method 1.
void remove_matches_1(struct node** newhead, int value){
    printf("enter\n");
    if (*newhead == NULL) {
        return;
    }
	struct node* head = *newhead;
	struct node* current = head;
	while ( head != NULL && head->val == value) {
	    head = head->next;
		free(current);
		current = head;
	}
	if (head == NULL) return;
	while(current != NULL) {
		while(current->next != NULL && current->next->val != value) {
			current = current->next;
		}
		struct node* tmp = current->next;
		if (tmp != NULL) {
		    current->next = tmp->next;
		    free(tmp);
		} else {
		    free(tmp);
		    break;
		}
		
	}
	*newhead = head;
	return;
}

// method 2.
struct node* remove_matches_2(struct node* head, int value) {
	if (head == NULL) return NULL;
	while (head != NULL && head->val == value) {
		struct node* tmp = head->next;
		free(head);
		head = tmp;
	}
	if (head == NULL) return NULL;
	struct node* current = head;
	while (current != NULL) {
		while (current->next!=NULL && current->next->val != value) {
			current = current->next;
		}
		if (current->next!=NULL) {
		    struct node* tmp = current->next->next;
		    free(current->next);
		    current->next = tmp;
		} else {
		    break;
		}
	}
	return head;
}

int main() {
	struct node* head = NULL;
	push(&head, 3);
	push(&head, 3);
	push(&head, 4);
	push(&head, 4);
	push(&head, 2);
	push(&head, 1);
	printHead(head);
	int val1 = 3;
	int val2 = 4;
	int flag = head->val;
	printf("main headvalue: %d\n", flag);
	//removeDuplicates(head);
	//remove_matches_1(&head, val2);
	//printHead(head);
	head = remove_matches_2(head, val2);
	printHead(head);
	return 0;
}