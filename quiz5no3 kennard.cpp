#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int universalcounter;

struct Node{
	char Name[50];
    int value; 
    Node *next, *prev; 
}*head, *tail;


Node *createNode(int value, char name[]){
    Node *newNode = (Node*)malloc(sizeof(Node*));
    strcpy(newNode->Name, name);
	newNode->value = value; 
    return newNode; 
}


void pushTail(int value, char name[]){
    //Node *newNode = createNode(value, name); 
    Node *newNode = (Node*)malloc(sizeof(Node*));
    strcpy(newNode->Name, name);
	newNode->value = value; 
    if(head == NULL){
        head = tail = newNode; 
    }
    else{
        tail->next = newNode;
    	newNode->prev = tail; 
    	tail = newNode;	
	} 
	head->prev = NULL; 
	tail->next = NULL; 
}


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
}

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
	
	char itemname[50], optionstring[1];
	int pricelist[10] = {3000, 2000, 7000, 9000, 4000}; 
	char productList[5][50] = {"Milk Tea", "Mineral Water", "Hot Dog", "Cheeseburger", "Cold/Hot Tea"};
	int input, qty, totalprice = 0, tempmult, arrList[100] ;
	char productName[50];
	
	do{
		makelongList(); 
		printMenu(); 
		scanf("%d", &input); getchar();
		if(input == 1){
			itemDatabase(); 
		}
		else if(input == 2){
			do{	
			printf("\n\n\n\n");
				makelongList();
				do{
					printf("Insert the item code you want to buy: "); scanf("%[^\n]", &itemname);getchar();
				}while(strcmp(itemname, "A0") != 0 && strcmp(itemname, "A1") != 0 && strcmp(itemname, "A2") != 0 && strcmp(itemname, "A3") != 0 && strcmp(itemname, "A4") != 0);
	
					do{
						printf("Insert the amount you desire : "); scanf("%d", &qty); getchar(); 	
					}while(qty <= 0);
					 
					if(strcmp(itemname, "A0") == 0){
						tempmult = qty*pricelist[0];
						totalprice += tempmult;  
					}
					else if(strcmp(itemname, "A1") == 0){
						tempmult = qty*pricelist[1];
						totalprice += tempmult;   
					}
					else if(strcmp(itemname, "A2") == 0){
						tempmult = qty*pricelist[2];
						totalprice += tempmult;  
					}
					else if(strcmp(itemname, "A3") == 0){
						tempmult = qty*pricelist[3];
						totalprice += tempmult;  
					}
					else if(strcmp(itemname, "A4") == 0){
						tempmult = qty*pricelist[4];
						totalprice += tempmult;  
					}
				if(strcmp(itemname, "A0") == 0){
					printf("Item name : Milk Tea \n"); 
				}
				else if(strcmp(itemname, "A1") == 0){
					printf("Item name : Mineral Water \n"); 
				}
				else if(strcmp(itemname, "A2") == 0){
					printf("Item name : Hot Dog \n"); 
				}
				else if(strcmp(itemname, "A3") == 0){
					printf("Item name : Cheeseburger \n"); 
				}
				else if(strcmp(itemname, "A4") == 0){
					printf("Item name : Cold/Hot Tea \n"); 
				}
				printf("Your total amount will be : %d\n", totalprice);
				printf("Do you want to continue? [Y \\ N]? : "); scanf("%[^\n]", optionstring); getchar(); 
				pushTail(qty, itemname);
				qty = 0; 
				fflush(stdin);
			}while(strcmp(optionstring, "Y") == 0); 
		}
		else if(input == 3){
			orderHistory(totalprice);
		}
		else if(input == 4){
			makelongList();
			printReciept(totalprice);
			return 0;
		}
		else if(input > 4){
			makelongList(); 
			printf("The number you input doesn't exist !\n");
			printf("Please Restart The Program \n"); getchar();
		}
	}while(input >= 1 && input <= 4);
	
	return 0; 
}
