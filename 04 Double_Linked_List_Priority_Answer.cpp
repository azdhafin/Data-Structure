#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data {
	char name[101];
	unsigned int priority;
	struct data* next;
	struct data* prev;
};

struct data *head=0;
struct data *tail=0;

struct data* findAfterPosition(int newPriority) {
	struct data *curr = head;
	while(curr != 0) {
		if(curr->priority > newPriority)
			return curr;

		curr = curr->next;
	}

	return curr;
}

void push(char *name, unsigned int priority) {
	struct data *node = (struct data*) malloc(sizeof(struct data));
	strcpy(node->name, name);
	node->priority = priority;
	node->next = 0;
	node->prev = 0;
	
	if(head == 0) {
		head = tail = node;
	}
	else {
		struct data *curr = findAfterPosition(priority);
		
		if(curr == 0) {
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
		else if(curr == head) {
			node->next = head;
			head->prev = node;
			head = node;
		}
		else {
			node->next = curr;
			node->prev = curr->prev;
			curr->prev->next = node;
			curr->prev = node;
		}
	}
}

void popAll() {
	struct data* curr = head;
	while(curr != 0) {
		head = head->next;
		free(curr);
		curr = head;
	}
}

void menu() {
	printf("1. Add Queue\n");
	printf("2. View Queue\n");
	printf("3. Pop Queue\n");
	printf("4. Exit\n\n");
}

void popQueue(){
	struct data *curr = head;
	if(head == NULL){
		printf("\n\nQueue is empty...\n");	
	}
	else if(head == tail){
		printf("%s (%d) has been removed!\n", curr->name, curr->priority);
		head = tail = NULL;
		free(curr);
	}
	else{
		printf("%s (%d) has been removed!\n", curr->name, curr->priority);
		head = head->next;
		head->prev = NULL;
		free(curr);
	}
}

void addQueue() {
	char name[101];
	unsigned int priority, len;

	do {
		printf("\nInput name [1..100] : ");
		scanf("%s", name); fflush(stdin);
		len = strlen(name);
	}while(len<1 || len>100);
	
	do {
		printf("Input priority value [1..10] : ");
		scanf("%d", &priority); fflush(stdin);
	}while(priority<1 || priority>10);

	push(name, priority);
}

void viewQueue() {
	if(head == 0) {
		printf("\n\nQueue is empty...\n");	
	}
	else {
		int no = 1;
		printf("\nQueue List :\n");

		struct data* curr = head;
		while(curr != 0) {
			printf("%02d. %s (%d)\n", no++, curr->name, curr->priority);
			curr = curr->next;
		}

		printf("\n");
	}
}

int main() {
	int pil;
	do {
		menu();
		do {
			printf("Input your choice [1..4] : ");
			scanf("%d", &pil); fflush(stdin);
		}while(pil<1 || pil>4);
		
		switch(pil) {
			case 1:
				addQueue();
				break;
			case 2:
				viewQueue();
				break;
			case 3:
				popQueue();
				break;
		}
		
		printf("\n");
	}while(pil!=4);
	
	popAll();
}
