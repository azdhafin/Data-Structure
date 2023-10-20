//#include <stdio.h>
//#include <stdlib.h>
//  
//struct Node 
//{
//    int data;
//    struct Node* next;
//};
//  
//// This function prints contents of linked list starting
//// from the given node
//void printList(struct Node* n)
//{
//    while (n != NULL) {
//        printf(" %d ", n->data);
//        n = n->next;
//    }
//}
//  
//// Driver's code
//int main()
//{
//    struct Node* head = NULL;
//    struct Node* second = NULL;
//    struct Node* third = NULL;
//  
//    // allocate 3 nodes in the heap
//    head = (struct Node*)malloc(sizeof(struct Node));
//    second = (struct Node*)malloc(sizeof(struct Node));
//    third = (struct Node*)malloc(sizeof(struct Node));
//  
//    head->data = 1; // assign data in first node
//    head->next = second; // Link first node with second
//  
//    second->data = 2; // assign data to second node
//    second->next = third;
//  
//    third->data = 3; // assign data to third node
//    third->next = NULL;
//  
//    // Function call
//    printList(head);
//  
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

// Define a struct for the nodes in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node to the beginning of the linked list (push)
void push(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Set data and next pointer for new node
    new_node->data = new_data;
    new_node->next = *head_ref;
    
    // Update head to point to new node
    *head_ref = new_node;
}

// Function to insert a new node at a specified position in the linked list (insert)
void insert(struct Node** head_ref, int pos, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Set data for new node
    new_node->data = new_data;
    
    // If position is 0, make new node the new head
    if (pos == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        // Traverse the list to find the node before the specified position
        struct Node* current_node = *head_ref;
        for (int i = 0; i < pos - 1; i++) {
            if (current_node == NULL) {
                printf("Invalid position\n");
                return;
            }
            current_node = current_node->next;
        }
        // Insert the new node after the node at the specified position
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Function to add a new node to the end of the linked list (pushback)
void pushback(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // Set data and next pointer for new node
    new_node->data = new_data;
    new_node->next = NULL;
    
    // If the list is empty, make the new node the new head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // Traverse the list to find the last node
    struct Node* last_node = *head_ref;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    // Insert the new node after the last node
    last_node->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() 
{
    // Start with an empty list
    struct Node* head = NULL;
    
    // Add some nodes to the list using push
    push(&head, 3);
    push(&head, 5);
    push(&head, 1);
    
    // Insert a node at position 1 using insert
    insert(&head, 1, 2);
    
    // Add a node to the end of the list using pushback
    pushback(&head, 4);
    
    // Print the list
    printf("Linked list:");
    
    return 0;
}

