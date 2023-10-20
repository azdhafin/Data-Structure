#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    char name[50];
    int priority;  
    Node *next, *prev; 
}*head = NULL, *tail = NULL; 

Node* createNode(char name[],int value){
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    strcpy(newNode->name, name); 
    newNode->priority = value; 
    newNode->next = NULL;
	newNode->prev = NULL; 
}

Node* findAfterPos(int newPriority){
    Node *curr = head; 
    while(curr != NULL){
        if(curr->priority > newPriority){
            return curr; 
        }
        curr = curr->next; 
    }
}

void push(char name[], int priority){
    Node *newNode = createNode(name, priority); 
    if(head == NULL){
        head = tail = newNode; 
    }
    else{
    	Node *curr = findAfterPos(priority); 
    	if(head == NULL){
    		newNode->prev = tail; 
    		tail->next = newNode;
    		tail = newNode; 
		}
		else if(curr == head){
        newNode->next = head; 
        newNode->prev = newNode; 
        head = newNode; 
    	}
    	else{
        newNode->next = curr; 
        newNode->prev = curr->prev; 
        curr->prev->next = newNode; 
        curr->prev = newNode; 
    	}
	}
    
}

void printMenu(){
    system("cls");
    printf("1. Insert Name\n"); 
    printf("2. View Names\n"); 
    printf("3. Remove Top Queue\n");
    printf("4. Exit\n");
    printf(">> ");  
}

void pop(){
    Node *curr = head; 
    if(head == NULL){
        printf("\nThere is no queue currently... Press Enter to continue\n"); getchar(); 
    }
    else if(head == tail){
        printf("%s with priority %d has been removed from the queue! \n", curr->name, curr->priority); 
        head = tail = NULL; 
        free(curr);
    }
    else{
        printf("%s with priority %d has been removed from the queue! \n", curr->name, curr->priority); 
        head = head->next; 
        head->prev = NULL; 
        free(curr); 
    }
}

void clearAll(){
    Node *curr = head; 
    while(curr != NULL){
        head = head->next; 
        free(curr); 
        curr = head; 
    }
}

void printQueue(){
    if(head == NULL){
        printf("\n There are no queues currently, please insert them. Press Enter to continue...");  getchar(); 
    }
    else{
        int no = 1; 
        printf("\n===Queue List===\n"); 

        Node *curr = head; 
        while(curr != NULL){
            printf("%02.d %s (%d)\n", no, curr->name, curr->priority); 
            no++; 
            curr = curr->next; 
        }
        printf("\n");
    }
}

int main(){

    char name[50];
    int input, priority; 

    do{
        printMenu(); 
        scanf("%d", &input); getchar();
        switch(input){
            case 1 :
                do{
                    printf("Input the name here [Max 50 Char]: "); scanf("%s", name); fflush(stdin);
                }while(strlen(name) > 50 || strlen(name) < 0); 
                do{
                    printf("Input the priority amount [1...10] "); scanf("%d", &priority); fflush(stdin); 
                }while(priority > 10 || priority < 0); 
                push(name, priority); 
                break;
            case 2:     
				printQueue(); 
				printf("\nPress Enter to continue...\n");getchar();
                break; 
            case 3:
                pop(); 
                break; 
        }
    }while(input != 4); 

    clearAll(); 

    return 0; 
}
