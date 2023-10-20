#include <stdio.h>
#include <stdlib.h>

//no 2


//no 3
struct Node 
{
    int data;
    struct Node* next;
};

void sortedInsert(struct Node** head_ref, struct Node* new_node) 
{
    struct Node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
	{
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) 
		{
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void push(struct Node** head_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    sortedInsert(head_ref, new_node);
}

void printList(struct Node* node) 
{
    while (node != NULL) 
	{
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() 
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 5);
    push(&head, 6);
    push(&head, 9);
    push(&head, 12);
    printf("Sorted Linked List: ");
    printList(head);
    return 0;
}
