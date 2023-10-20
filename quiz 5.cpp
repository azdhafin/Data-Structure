#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
	char product[101];
	long long int price;
	Node *next;
	Node *prev;
};
Node *head=NULL;
Node *tail=NULL;

struct kasir
{
	char product[101];
	long long int price;
	int quantity;
	long long int total;
	kasir *next;
	kasir *prev;
};

kasir *headKasir=NULL;
kasir *tailKasir=NULL;
int searchPrice(char []);

Node* createNode(char product[],long long int price)
{
	Node *newNode= (Node*)malloc(sizeof(Node));
	strcpy(newNode->product,product);
	newNode->price=price;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}

void push(char product[],long long int price)
{
	Node *newNode= createNode(product,price);
	if(head==NULL)
	{
		head=tail=newNode;
	}
	else{
		tail->next=newNode;
		newNode->prev=tail;
		tail=newNode;
	}
}

void print()
{
	Node *curr=head;
	while(curr!=NULL)
	{
		printf("%-20s | %-6lld |\n",curr->product,curr->price);
		curr=curr->next;
	}
}

int search(char product[])
{
	Node *curr=head;
	while(curr!=NULL){
		if(strcmp(curr->product,product)==0)
		{
			return 1;
		}
		curr=curr->next;
	}
	return 0;
}

int searchPrice(char product[])
{
	Node *curr=head;
	while(curr!=NULL)
	{
		if(strcmp(curr->product,product)==0)
		{
			return curr->price;
		}
		curr=curr->next;
	}
	return 0;
}

kasir* createKasir(char product[],long long int price,int quantity)
{
	kasir *newKasir= (kasir*)malloc(sizeof(kasir));
	strcpy(newKasir->product,product);
	newKasir->price=price;
	newKasir->quantity=quantity;
	newKasir->total=price*quantity;
	newKasir->next=NULL;
	newKasir->prev=NULL;
	return newKasir;
}
void pushKasir(char product[],long long int price,int quantity)
{
	kasir *newKasir= createKasir(product,price,quantity);
	if(headKasir==NULL){
		headKasir=tailKasir=newKasir;
	}
	else
	{
		tailKasir->next=newKasir;
		newKasir->prev=tailKasir;
		tailKasir=newKasir;
	}
}

void searchKasir(char product[],int quantity)
{
	kasir *curr=headKasir;
	while(curr!=NULL)
	{
		if(strcmp(curr->product,product)==0)
		{
			curr->quantity+=quantity;
			curr->total=curr->price*curr->quantity;
			break;
		}
		curr=curr->next;
	}
}

int searchCash(char product[])
{
	kasir* curr=headKasir;
	while(curr!=NULL)
	{
		if(strcmp(curr->product,product)==0)
		{
			return 1;
		}
		curr=curr->next;
	}
	return 0;
}

void update(char product[],int quantity)
{
	kasir *curr=headKasir;
	while(curr!=NULL)
	{	
		if(strcmp(curr->product,product)==0)
		{
			curr->quantity=quantity;
			curr->total=curr->price*curr->quantity;
			break;
		}
		curr=curr->next;
	}
}
void receipt()
{
	kasir* curr=headKasir;
	while(curr!=NULL)
	{
		printf("%-20s | %-10d | %-15d\n",curr->product,curr->quantity,curr->total);
		curr=curr->next;
	}
}
int total()
{
	kasir* curr=headKasir;
	int total=0;
	while(curr!=NULL)
	{
		total+=curr->total;
		curr=curr->next;
	}
	return total;
}
menu()
{
	printf("   ===Binus Canteen===\n\n");
	printf("================================\n");
	printf("|    Name      	     | Price  |\n");
	printf("================================\n");
}


int main()
{
	int opt;
	do
	{
	printf("Choose the option:\n");
	printf("1. See Menu\n");
	printf("2. Buy\n");
	printf("3. Update\n");
	printf("4. Exit\n");
	printf(">> ");
	scanf("%d", &opt);
	if(opt == 1)
	{
		push("Mineral water",5000);
		push("Burger",8000);
		push("Candy",4000);
		push("Milk tea",6000);
		push("Onigiri",10000);
		menu();
		print();
	printf("================================\n");
	}
	if(opt == 2)
	{
		char choose[2];
		int k=0;
		do{
			char name[101];
			strcpy(name,"NULL");
			int qty;
			while(search(name) == 0)
			{
				if(k == 0)
				{
					printf("Input item name: "); getchar();
					scanf("%[^\n]",name); getchar();
						k++;
				}
				else{
					printf("Input item name: ");
					scanf("%[^\n]",name); getchar();
				}
				if(search(name) == 1)
				{
					break;
				}
			}
			int price = searchPrice(name);
			printf("Input Quantity: ");
			scanf("%d",&qty);
			printf("Total price of this item: %d\n", price*qty);
			if(searchCash(name) == 1){
				searchKasir(name,qty);
			}
			else
			{
				pushKasir(name,price,qty);
			}
			do{
				printf("Do you want to continue [y/n]: ");
				scanf("%s",&choose); getchar();
				puts("");
				for(int i=0;i<strlen(choose);i++){
					if(choose[i] >= 'A' && choose[i] <= 'Z')
					{
						choose[i] += 32;
					}
				}
				if(strcmp(choose,"n") == 0)
				{
					puts(" ");
					printf("-----------------------------------------\n");
					printf("SUMMARY\n");
					printf("-----------------------------------------\n");
					receipt();
					printf("-----------------------------------------\n");
					printf("Total: %d\n",total());
					break;
				}
			}while(strcmp(choose,"y") != 0 && strcmp(choose,"n") != 0);
			
		}while(strcmp(choose,"y") == 0);
		
		
	}
	else if(opt == 3)
	{
		char choose[2];
		int k = 0;
		do
		{
			char name[101];
			strcpy(name,"NULL");
			int quantity;
			while(searchCash(name)==0){
				if(k==0){
					printf("Input item that you want to update: "); getchar();
					scanf("%[^\n]",name); getchar();
					k++;
				}
				else{
					printf("Input item that you want to update: ");
					scanf("%[^\n]",name); getchar();
				}
				if(searchCash(name)==1){
					break;
				}
				
			}
			
			int price=searchPrice(name);
			printf("Update The Quantity to: ");
			scanf("%d",&quantity);
			printf("Total price of this item: %d\n",price*quantity);
			update(name,quantity);
			do{
				printf("Do you want to continue update? (y/n): ");
				scanf("%s",&choose); getchar();
				puts(" ");
				for(int i=0; i<strlen(choose); i++)
				{
					if(choose[i] >= 'A' && choose[i] <= 'Z')
					{
						choose[i] += 32;
					}
				}
				if(strcmp(choose,"n") == 0)
				{
					puts(" ");
					printf("=========================================\n");
					printf("Your Bill\n");
					printf("=========================================\n");
					receipt();
					printf("==========================================\n");
					printf("TOTAL: %d\n",total());
					break;
				}
			}while(strcmp(choose,"y") != 0 && strcmp(choose,"n") != 0);
			
		}while(strcmp(choose,"y") == 0);
	}
	else if(opt == 4)
	{
		puts(" ");
		printf("-----------------------------------------\n");
		printf("Receipt\n");
		printf("-----------------------------------------\n");
		receipt();
		printf("-----------------------------------------\n");
		printf("Total: Rp.%d\n",total());
		printf("Thank you for shopping\n");
		exit(0);
		break;
	}
	}while(opt != 4);
}




//int main()
//{
//	int opt, Qty, harga, total=0, totalqty;
//	char press[2], kode[10], temp[5];
//	int pricelist[10] = {4000, 3000, 7000, 8000, 12000};
//	do
//	{
//		menu();
//		scanf("%d", &opt); getchar();
//		if(opt == 1)
//		{
//			items();
//			puts("");
//			printf("Press enter to continue...");
//			getchar();
//		}	
//		if(opt == 2)
//		{
//			do
//			{
//				printf("Input items code: ");
//				scanf("%s", &kode); getchar();
//			}while(kode[0] != 'A' && kode[1] != '0' && kode[1] != '1' && kode[1] != '2' && kode[1] != '3' && kode[1] != '4');
//			do
//			{
//				printf("Input the quantity: ");
//				scanf("%d", &Qty); getchar();
//			}while(Qty < 0);
//			do
//			{
//				kode[1] = temp[0];
//				printf("Do you want to keep ordering [y/n]: ");
//				scanf("%s", &press); getchar();
//				if(strcmp(press,"y") == 0)
//				{
//					printf("Input items code: ");
//					scanf("%s", &kode); getchar();
//					printf("Input the quantity: ");
//					scanf("%d", &Qty); getchar();
//					totalqty += Qty;
//					if(strcmp(kode,"A0") == 0)
//					{
//						harga = Qty*pricelist[0];
//						total += harga;
//					}
//					if(strcmp(kode,"A1") == 0)
//					{
//						harga = Qty*pricelist[1];
//						total += harga;
//					}
//					if(strcmp(kode,"A2") == 0)
//					{
//						harga = Qty*pricelist[2];
//						total += harga;
//					}
//					if(strcmp(kode,"A3") == 0)
//					{
//						harga = Qty*pricelist[3];
//						total += harga;
//					}
//					if(strcmp(kode,"A4") == 0)
//					{
//						harga = Qty*pricelist[4];
//						total += harga;
//					}
//					printf("total: %d\n", total);
//					printf("quantitiy: %d\n", totalqty);
//				}
//				pushtail(Qty, kode);
//			}while(strcmp(press, "n") != 0);
//		}
//		if(opt == 3)
//		{
//			node *curr = head;
//			if(head == NULL)
//			{
//				printf("You have not add anything to your cart !\n\n");
//				printf("Press enter to continue...\n\n");
//			}
//			else
//			{
//				cart(total);
//			}
//		}
//	}while(opt != 4);
//	receipt(total);
//	printf("Thank you for shopping !!\n");
//	
//}
