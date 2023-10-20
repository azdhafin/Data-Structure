#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct Node {
    char *key;
    char *value;
    struct Node *next;
} Node;

unsigned long hash(char *str);
void insert(Node** table, char *key, char *value);
char* lookup(Node** table, char *key);

int main() {
    // initialize hash table
    Node* table[TABLE_SIZE] = { NULL };

    // read key-value pairs from user input
    char key[100], value[100];
    while (1) {
        printf("Enter key (or 'quit' to exit): ");
        scanf("%s", key);
        if (strcmp(key, "quit") == 0) {
            break;
        }
        printf("Enter value: ");
        scanf("%s", value);
        insert(table, key, value);
    }

    // look up some keys
    printf("%s\n", lookup(table, "apple"));
    printf("%s\n", lookup(table, "banana"));
    printf("%s\n", lookup(table, "orange"));
    printf("%s\n", lookup(table, "potato"));
    printf("%s\n", lookup(table, "carrot"));

    return 0;
}

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++) != '\0') {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

void insert(Node** table, char *key, char *value) {
    unsigned long index = hash(key) % TABLE_SIZE;
    Node* node = malloc(sizeof(node* Node));
    if (node == NULL) {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        exit(1);
    }
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = table[index];
    table[index] = node;
}

char* lookup(Node** table, char *key) {
    unsigned long index = hash(key) % TABLE_SIZE;
    Node* node = table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

