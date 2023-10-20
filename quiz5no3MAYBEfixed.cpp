#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char Name[100];
    int value; 
    Node *next, *prev; 
}*head, *tail;

/*
Node *createNode(int value, char name[]){
    Node *newNode = (Node*)malloc(sizeof(Node*));
    strcpy(newNode->Name, name);
	newNode->value = value; 
    return newNode; 
}*/


void pushTail(int value, char name[]){
	struct Node *newNode = (Node*)malloc(sizeof(Node*));
    strcpy(newNode->Name, name);
	newNode->value = value; 
    if(head == NULL){
        head = tail = newNode; 
        head->prev = NULL; 
        tail->next = NULL;
    }
    else{
        tail->next = newNode;
    	newNode->prev = tail; 
    	tail = newNode;
    	tail->next = NULL;
	} 
}

void createTail(char ID[], int val){
	struct Node *newNode = (Node*)malloc(sizeof(Node));
	
	strcpy(newNode->Name, ID);
	newNode->value = val;
	
	if (head == NULL){
		head = tail = newNode;
		head->prev = NULL;
		tail->next = NULL;
	}
	else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		tail->next = NULL;
	}
	return;
}

/*
void pushHead(int value, char name[]){
    Node *newNode = createNode(value, name); 
    if(head == NULL){
        head = tail = newNode;
        return; 
	}
	else{
	  head->prev = newNode; 
    	newNode->next = head; 
    	head = newNode; 
	}
	head->next = NULL;
	tail->next = NULL;
	return; 
}*/

void makelongList(){
	for(int i = 0; i < 25; i++){
		printf("\n"); 
	}
}

void orderHistory(int val){
	Node* curr = head; 
	makelongList();
	printf("=== Order History ===\n");
	int i = 0;
	while(curr != NULL){
		printf("Order %d : %s, %d pcs\n", i+1, curr->Name, curr->value);	
		i++;
		curr = curr->next; 
	}
	printf("Total Spent = Rp. %d \n", val);
	printf("=====================\n"); getchar();

}

void itemDatabase(){
	makelongList();
	printf("=========================================\n");
	printf("| Item Code |    Item Name   |  Price   |\n"); 
	printf("|    A0     | Milk Tea       | Rp. 3000 |\n");
	printf("|    A1     | Mineral Water  | Rp. 2000 |\n");
	printf("|    A2     | Hot Dog        | Rp. 7000 |\n");
	printf("|    A3     | Cheeseburger   | Rp. 9000 |\n");
	printf("|    A4     | Cold/Hot Tea   | Rp. 4000 |\n");
	printf("=========================================\n");
	
	printf("\n Press enter to continue\n");  getchar(); 
}

void printMenu(){
	printf("=== suniB Supermarket ===\n");
	printf("1. View Available Items\n"); 
	printf("2. Buy Items\n");
	printf("3. Order History\n"); 
	printf("4. Exit\n");
	printf("=========================\n");
	printf(">> "); 
}

void printReciept(int val){
	printf("=== suniB Supermarket ===\n"); 
	printf("=  -  R E C I E P T - ===\n  ");
	printf("      [Name]-[QTY] \n");
	Node *curr = head;
    while(curr != NULL){
    printf("        %s     %d \n", curr->Name, curr->value);
        curr = curr->next; 
    }
    printf("Total Spent = Rp. %d \n", val);
	printf("-Thank You For Shopping!-\n"); 
	printf("=========================\n");
}
void classicprintList(){
    Node *curr = head; 
    printf("NULL");
    while(curr != NULL){
        printf("<-[ %d ]->", curr->value);
        curr = curr->next; 
    }
    printf("NULL\n");
}

int main(){
	
	int input, qty, pricelist[10] = {3000, 2000, 7000, 9000, 4000}, mult, total, temps;
	char itemcode[2], temp[2];
	char optionstring = 'N'; 
	int opt;
	
	do{
		makelongList(); 
		printMenu();
		scanf("%d", &input); getchar();
		
		switch(input){
			case 1: 
				itemDatabase(); 
				break; 
			case 2:
				do{
					
					do{
						printf("Insert the item code you want to buy : "); 
						scanf("%s", itemcode); getchar(); 
					}while((itemcode[0] != 'A') && (itemcode[1] != '0') && (itemcode[1] != '1') && (itemcode[1] != '2') && (itemcode[1] != '3') && (itemcode[1] != '4'));
					do{
						printf("Insert the amount : "); 
						scanf("%d", &qty); getchar(); 
					}while(qty < 0);
					itemcode[1] = temp[0];
					temps = atoi(temp);
					switch(temps){
						case 0:
						 	mult = qty*pricelist[0];
						 	total += mult; 
							printf("\nItem name : Milk Tea\n");
						 	break;
						case 1: 
							mult = qty*pricelist[1]; 
							total += mult;
							printf("\nItem name : Mineral Water\n"); 
							break; 
						case 2: 
							mult = qty*pricelist[2]; 
							total += mult; 
							printf("\nItem name : Hot Dog\n"); 
							break; 
						case 3:
							mult = qty*pricelist[3]; 
							total += mult; 
							printf("\nItem name : Cheeseburger\n");
							break; 
						case 4:
							mult = qty*pricelist[4];
							total += mult; 
							printf("\nItem name : Cold | Hot Tea\n"); 
							break; 
					}
					printf("Your total amount will be : %d\n", total); 
					createTail(itemcode, qty);
					printf("Do you want to continue? [Y = 1 | N = 0]? : ");
					scanf("%d", &opt);
				}while(opt != 0);
				/*
				printf("Do you want to continue? [Y | N]? : ");
				scanf("%c", optionstring);
				if (optionstring == 'Y'){
					input = 2;
				}
				//optionstring = "N";*/
				break;
			case 3:
				orderHistory(total); 
				break; 
			case 4:
				break; 
		}
		
	}while(input != 4);
	
	return 0; 
}
