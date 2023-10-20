#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char name[50];
	int age;
	char desc[50];
	char code[11];
	int num;
	
	int value;
	node *next;
};
node *head, *tail = NULL;

node *createnode(char name[], int age, char desc[], char code[])
{
	node *newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->name, name);
	newnode->age = age;
	strcpy(newnode->desc, desc);
	strcpy(newnode->code, code);
	newnode->next = NULL;
	return newnode;
}

void pushmid(char name, int age, char desc[], char code[])
{
	if(head == NUll || num <= head->value)
	{
		pushhead(num);
	}
	else if(tail >= num)
	{
		pushtail(num);
	}
	else
	{
		node *curr = head;
		node *newnode = createnode(num);
		while(curr->next != NULL)
		{
			if(curr->next->value >= num)
			{
				newnode->next = curr->next;
				curr->next = newnode;
				return;
			}
			curr = curr->next;o
		}
	}
}

void pushhead(char code[], char desc[], int age, char name[])
{
	node *newnode = createnode(name, age, desc, code);
	if(head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
}

void pushtail(char name[], int age, char desc[], char code[])
{
	node *newnode = createnode(name, age, desc, code);
	if(tail == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
	}
}

//void pushmid(char code[])
//{
//	int temp = strlen(code);
//	if(head == NULL || head <= temp)
//	{
//		pushhead(temp);
//	}
//	else if(tail >= temp)
//	{
//		pushtail(temp);
//	}
//	else
//	{
//		node *curr = head;
//		node *newnode = createnode(name, age, desc, code);
//		while(curr != NULL)
//		{
//			if(curr->next->code >= temp)
//			{
//				newnode->next = curr->next;
//				curr->next = newnode;
//				return;
//			}
//			curr = curr->next;
//		}
//	}
//}

void queue(char name[], int age, char desc[], char code[])
{
	int i=1;
	printf("---------------------------------------------------------\n");
	printf("|No  | Name		| Age | Description	| Code	|\n");
	printf("---------------------------------------------------------\n");
	
	node *curr = head;
	while(curr != NULL)
	{
		printf("| %d | %s		| %d | %s		| %s  |\n", i, curr->name, curr->age, curr->desc, curr->code);
		i++;
		curr = curr->next;
	}
	printf("---------------------------------------------------------\n\n");
	printf("Press enter to continue !\n\n");
}

void menu()
{
	printf("Bluejack Hospital\n");
	printf("==================\n");
	printf("1. Insert\n");
	printf("2. View\n");
	printf("3. Queue\n");
	printf("4. Exit\n");
	printf(">> ");
}

int main()
{
	char nama[50], desk[50], kode[15];
	int opt, umur;
	do
	{
		menu();
		scanf("%d", &opt); getchar();
		if(opt == 1)
		{
//			system("cls");
			do
			{
				printf("Name [4-25 char]: ");
				scanf("%[^\n]", &nama); getchar();
			}while(strlen(nama) < 4 || strlen(nama) > 25);
			do
			{
				printf("Age: ");
				scanf("%d", &umur); getchar();
			}while(umur < 0);
			do
			{
				printf("Description/symtomps [at least 6 char]: ");
				scanf("%[^\n]", &desk); getchar();
			}while(strlen(desk) < 6);
			do
			{
				printf("Enter Code [Red|Yellow|Green]: ");
				scanf("%s", &kode); getchar();
			}while(strcmp(kode, "Red") != 0 && strcmp(kode, "Yellow") != 0 && strcmp(kode, "Green") != 0);
			
			pushhead(kode, desk, umur, nama);
			puts("");
			printf("Insert success !\n\n");
			getchar();
		}
		if(opt == 2)
		{
			if(head == NULL)
			{
				printf("There is no queue yet !\n\n");
				printf("Press enter to continue...\n\n");
			}
			else
			{
				queue(nama, umur, desk, kode);
			}
			getchar();
		}
		if(opt == 3)
		{
			node *curr = head;
			if(curr == NULL)
			{
				printf("There is no queue yet !\n\n");
			}
			else
			{
				printf("The next patient is:\n");
				printf("Name		: %s\n", curr->name);
				printf("Age		: %d\n", curr->age);
				printf("Description	: %s\n", curr->desc);
				printf("Code		: %s\n\n", curr->code);
			}
			printf("Press enter to continue...\n\n");
			getchar();
		}
	}while(opt != 4);
	
	printf("Thank you for using our service !!\n");
	
	return 0;
}
