#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char bookID[50]; 
	char title[100]; 
	char author[50]; 
	long long int ISBN; 
	int pgnmbr;
	
	Node *next; 
}*head = NULL, *tail = NULL;

void tidySpace(){
	for(int i = 0; i < 25; i++){
		printf("\n"); 
	}
}

Node* createNode(char bookid[], char title[], char author[], int isbn[], int pgnmbr){
	Node *newNode = (Node*)malloc(sizeof(Node)); 
	strcpy(newNode->bookID, bookid); 
	strcpy(newNode->title, title);
	strcpy(newNode->author, author); 
	newNode->ISBN = isbn;  
	newNode->pgnmbr = pgnmbr;
	return newNode; 
}

const int constantSize = 1007; 
Node* hashTable[1007]; 

int hashingFunction(char bookid[]){
	int len = strlen(bookid);
	int totascii = 0;
	int size; 
	for(int i = 0; i < len; i++){
		totascii += bookid[i]; 
	}
	size = constantSize; 
	return totascii % size; 
}

void insert(char bookid[], char title[], char author[], long long int isbn[], int pgnmbr){
	Node* newNode = createNode(bookid,title,author,isbn,pgnmbr); 
	int insertVal = hashingFunction(bookid);
	if(hashTable[insertVal] == 0){
		hashTable[insertVal] == newNode;
	}
	else{
		Node* curr = hashTable[insertVal];
		while(curr!=NULL){
			if(curr->next == NULL){
				curr->next = newNode; 
				return; 
			}
			curr = curr->next; 
		}
	}
	
}

void searchPop(char bookid[]){
	int findHash = hashingFunction(bookid); 
	if(hashTable[findHash] == NULL){
		return;
	}
	else if(strcmp(hashTable[findHash]->bookID, bookid) == 0){
		Node* temp = hashTable[findHash]->next; 
		free(hashTable[findHash]);
		temp = hashTable[findHash]; 
	}
}

void printTable(){
	tidySpace();
	Node* curr = head; 
	while(curr!=NULL){
		printf("%5s %5s %5s %5s %5d \n", curr->bookID, curr->title, curr->author, curr->ISBN, curr->pgnmbr);
	}
	printf("\n Press ENTER to continue...\n"); 
	getchar();
}

void printMenu(){
	tidySpace(); 
	printf("Bluejack Library\n");
	printf("================\n");
	printf("1. View Book\n2. Insert Book\n3. Remove Book\n4. Exit\n");
	printf("================\n");
	printf(">>> "); 
}

int validateMe(int check){
	for(int i = 0; i < constantSize; i++){
		if(hashTable[i] == NULL){
			tidySpace(); 
			printf("\nThere is no book(s) !\n");
			printf("\n Press ENTER to continue...\n"); getchar(); 
			return 0; 
		}
	}
	return 1; 
}

int validateExistance(char title[], int check){
	for(int i = 0; i < constantSize; i++){
		if(strcmp(title, hashTable[i]) == 0){
			printf("The book title already exist !\n"); 
			return 0; 
		}
	}
	return 1; 
}



int main(){
	
	int input, check = 0, siu;
	char title[100], author[50];
	long long int isbn;  
	int pgnmbr; 
	
	do{
		printMenu(); 
		scanf("%d", &input);
		
		switch(input){
			case 1 : 
				siu = validateMe(check);
				if(siu == 0){
					getchar(); 
				}
				else if(siu == 1){
					printTable(); 
				} 
				break;
			case 2:
				do{
					printf("Input book title[5-50][unique]: "); scanf("%[^\n]", &title); getchar(); 
					siu = validateExistance(title, check); 	
				}while(siu == 0);
				do{
					printf("Input the author's Name[3-25][Mr. | Mrs.]: "); scanf("%[^\n]", &author); getchar();
				}while(strlen(author) < 3 || strlen(author) > 25 && author[0] != 'M' && author[1] != 'r' || author[3] != 's');
				do{
					printf("Input ISBN[10-13][numeric]: "); scanf("%lld", isbn); getchar(); 
				}while(isbn <= 10 || isbn >= 13); 
				do{
					printf("Input Page Number: "); scanf("%d", pgnmbr); getchar();
				}
				 
				break; 
				
			case 3:
				
				break; 
			
			case 4: 
				tidySpace();
				printf("Thank you for using Bluejack Library\n"); 
				return 0;
		}
	}while(input >= 1 || input <= 4); 
	
	
	return 0; 
}
