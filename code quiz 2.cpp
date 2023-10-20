#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void pushSorted(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;

    // if the list is empty or the new value is less than the head value, insert at the beginning
    if (head == NULL || value < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        // traverse the list to find the node after which to insert the new value
        struct Node* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }

        // insert the new value after current
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    pushSorted(5);
    pushSorted(1);
    pushSorted(9);
    pushSorted(7);
    pushSorted(12);
    pushSorted(6);

    // print the values in the list
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}
