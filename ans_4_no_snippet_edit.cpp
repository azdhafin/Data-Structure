#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// you don't allowed to change the structure of struct data
struct data {
	char name[101];
	unsigned int priority;
	struct data* next;
	struct data* prev;
};

struct data *head=0;
struct data *tail=0;

void push(char *name, unsigned int priority) {
	/*
		please input your code here....
		note : you can add additional method if needed
	*/
	struct data *newdata = (data*)malloc(sizeof(data));
	strcpy(newdata->name, name);
	newdata->priority = priority;
	
	if (head == NULL){
		head = tail = newdata;
		head->prev = NULL;
		tail->next = NULL;
	}
	else{
		if(head->priority > priority){
			head->prev = newdata;
			newdata->next = head;
			head = newdata;
			head->prev = NULL;
		}
		else if (tail->priority < priority){
			tail->next = newdata;
			newdata->prev = tail;
			tail = newdata;
			tail->next = NULL;
		}
		else{
			
			struct data *curr = head;
			//place curr untuil curr->next->priority is more that priority
			while (curr->next->priority < priority){
				curr = curr->next;
			}
			newdata->prev = curr;
			newdata->next = curr->next;
			curr->next->prev = newdata;
			curr->next = newdata;
		}
	}
}

void popHead(){
	struct data *curr = head;
	head = head->next;
	free(curr);
}

void popAll() {
	/*
		please input your code here....
		note : you can add additional method if needed
	*/
	struct data *curr = head;
	while (curr != NULL){
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
			printf("%02d. %s %d\n", no++, curr->name, curr->priority);
			curr = curr->next;
		}

		printf("\n");
	}
}

int main() {
	push("Asu", 1);
	push("Asu", 2);
	push("Asu", 3);
	push("Asu", 4);
	push("Asu", 5);
	push("Asu", 6);
	int pil;
	do {
		menu();
		do {
			printf("Input your choice [1..3] : ");
			scanf("%d", &pil); fflush(stdin);
		}while(pil<1 || pil>4);
		
		switch(pil) {
			case 1:
				addQueue();
				break;
			case 2:
				viewQueue();
				getchar();
				break;
			case 3:
				popHead();
				break;
		}
		
		system("cls");
	}while(pil!=4);
	
	popAll();
}
