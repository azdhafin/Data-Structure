#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char name[50]; 
	int age; 
	char description[50]; 
	char code[15];
	
	Node* next; 
}*head = NULL, *tail = NULL;

Node* createNode(char name[], int age, char description[], char code[]){
	Node* newNode = (Node*)malloc(sizeof(Node)); 
	strcpy(newNode->name, name); 
	newNode->age = age; 
	strcpy(newNode->description, description); 
	strcpy(newNode->code, code); 
	
	newNode->next = NULL;
	return newNode;
}

void popHead(){
	if(head == NULL){
		return; 
	}
	else if(head == tail){
		free(head);
		head = NULL;
		tail = NULL; 
	}
	else{
		Node* temp = head->next;
		free(head); 
		head = temp; 
	}
}
	
void pushTail(char name[], int age, char description[], char code[]){
	Node* newNode = createNode(name, age, description, code); 
	if(head == NULL){
		head = newNode; 
		tail = newNode; 
	}
	else{
		tail->next = newNode;
		tail = newNode;  
	}
	return; 
}



void printQueue(char name[], int age, char description[], char code[]){
	Node* curr = head; 
	while(curr != NULL){
		printf("[ %s | %d | %s | %s ] -> ", curr->name, curr->age, curr->description, curr->code); 
		curr = curr->next; 
	}
	printf("\n");
}

void printCoolQueue(char name[], int age, char description[], char code[]){
	int i = 0;
	Node* curr = head; 
	printf("Paitient List: \n"); 
	printf("---------------------------------------------------------------------------------------------\n");
	printf("|No  | Name                      | Age | Description                               |  Code  |\n");
	while(curr != NULL){
		printf("| %d | %s                        | %d  | %s                                        |    %s  |\n", i+1, curr->name, curr->age, curr->description, curr->code); 
		curr = curr->next; 
		i++;
	} 
		
	printf("---------------------------------------------------------------------------------------------\n");
}

void printMenu(){
	printf("Bluejack Hosptial\n");
	printf("=================\n");
	printf("1. Insert\n");
	printf("2. View\n");
	printf("3. Next Queue\n"); 
	printf("4. Exit\n"); 
	printf("5. Print linked list\n"); 
	printf(">> "); 
}

int main(){
	
	char nama[50], deskripsi[50], warna[50]; 
	int input, umur; 
	
	do{
		int counter = 0; 
		printMenu(); 
		scanf("%d", &input); getchar();
		
		if(input == 1){
			do{
				printf("Input paitient name[4-25]: "); scanf("%[^\n]", &nama); getchar(); 
			}while(strlen(nama) < 4 || strlen(nama) > 25); 
			
			do{
				printf("Input age[>=0]: "); scanf("%d", &umur); getchar();
			}while(umur < 0); 
			
			do{
				printf("Input description[>= 6 characters]: "); scanf("%[^\n]", &deskripsi); getchar();  
			}while(strlen(deskripsi) < 6); 
			
			do{
				printf("Input code[Red | Yellow | Green]: "); scanf("%[^\n]", &warna); getchar(); 
			}while(strcmp(warna, "Red") == 0 && strcmp(warna, "Yellow") == 0 && strcmp(warna, "Green") == 0); 
			

			pushTail(nama, umur, deskripsi, warna); 
			printf("\n"); 
			printf("Insert Success\n\n"); 
		}
		
		else if(input == 2){
			Node* curr = head; 
			if(head == NULL){
				printf("\nThere is no queue yet !\n"); 
				printf("Press Enter to continue...\n\n"); 
			}
			else{
				printCoolQueue(nama, umur, deskripsi, warna); 
			}
				
		} 
		else if(input == 3){
			Node* curr = head; 
					if(head == NULL){
						printf("\nThere is no queue yet !\n"); 
						printf("Press Enter to continue...\n\n"); 
					}
					else{
						printf("\nThe next paitient is : \n"); 
						printf("Name            : %s\n", curr->name);
						printf("Age             : %d\n", curr->age);
						printf("Description     : %s\n", curr->description); 
						printf("Code            : %s\n", curr->code); 
						printf("\n Press Enter to Continue ...\n\n"); 
						popHead(); 
					}	
		}
		else if(input == 4){
			return 0; 
		}
		else if(input == 5){
			printQueue(nama, umur, deskripsi, warna); 
		}
	}while(input >= 1 && input <= 5); 
	return 0; 
}
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct Node{
//	char* name; 
//	int age; 
//	char* description; 
//	char* code;
//	Node* next; 
//}*head = NULL, *tail = NULL;
//
//Node* createNode(char name[], int age, char description[], char code[]){
//	Node* newNode = (Node*)malloc(sizeof(Node*)); 
//	newNode->name = name; 
//	newNode->age = age; 
//	newNode->description = description; 
//	newNode->code = code; 
//	newNode->next = NULL;
//	return newNode;
//}
//	
//void pushTail(char name[], int age, char description[], char code[]){
//	Node* newNode = createNode(name, age, description, code); 
//	if(head == NULL){
//		head = newNode; 
//		tail = newNode; 
//	}
//	else{
//		tail->next = newNode;
//		tail = newNode;  
//	}
//}
//
//void printQueue(char name[], int age, char description[], char code[]){
//	Node* curr = head; 
//	while(curr->age != NULL){
//		printf("%s | %d | %s | %s -> ", curr->name, curr->age, curr->description, curr->code); 
//		curr = curr->next; 
//	}
//}
//
//void printMenu(){
//	printf("Bluejack Hosptial\n");
//	printf("=================\n");
//	printf("1. Insert\n");
//	printf("2. View\n");
//	printf("3. Next Queue\n"); 
//	printf("4. Exit\n"); 
//	printf("5. Print linked list\n"); 
//	printf(">> "); 
//}
//
//int main(){
//	
//	char nama[50], deskripsi[50], warna[50]; 
//	int input, umur; 
//	
//	do{
//		int counter = 0; 
//		printMenu(); 
//		scanf("%d", &input); getchar();
//		if(input == 1){
//			do{
//				printf("Input paitient name[4-25]: "); scanf("%[^\n]", &nama); getchar(); 
//			}while(strlen(nama) < 4 || strlen(nama) > 25); 
//			do{
//				printf("Input age[>=0]: "); scanf("%d", &umur); getchar();
//			}while(umur < 0); 
//			do{
//				printf("Input description[>= 6 characters]: "); scanf("%[^\n]", &deskripsi); getchar();  
//			}while(strlen(deskripsi) < 6); 
//			do{
//				printf("Input code[Red | Yellow | Green]: "); scanf("%[^\n]", &warna); getchar(); 
//			}while(strcmp(warna, "Red") != 0 && strcmp(warna, "Yellow") != 0 && strcmp(warna, "Green") != 0); 
////			if(counter == 0){
////				createNode(nama, umur, deskripsi, warna);
////			}
////			else{
////				pushTail(nama, umur, deskripsi, warna); 
////			}
//			pushTail(nama, umur, deskripsi, warna); 
//			printf("\n"); 
//			printf("Insert Success");
//			printf("\n");  
//		
//		}
//		else if(input == 2){
//			printf("Option 2 \n"); 
//		}
//		else if(input == 3){
//			printf("Option 3 \n"); 
//		}
//		else if(input == 4){
//			return 0; 
//		}
//		else if(input == 5){
//			printQueue(nama, umur, deskripsi, warna); 
//		}
//	}while(input >= 1 && input <= 5); 
//	
//}
