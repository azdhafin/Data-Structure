#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char name[100];
	int date;
	char title[100];
	char publisher[100];
	node *next;
} *head = NULL, *tail = NULL;

node *createnode(char name[], char title[], char publisher[], int date)
{
	node *newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->name, name);
	strcpy(newnode->title, title);
	strcpy(newnode->publisher, publisher);
	newnode->date = date;
	newnode->next = NULL;
}

void menu()
{
	printf("====Sunib Library====\n");
	printf("1. Add Journal\n");
	printf("2. View Journal\n");
	printf("3. Delete Journal\n");
	printf("4. Exit\n");
	printf(">> ");
}

void view(char name[], char title[], char publisher[], int date)
{
	printf("------------------------------------------------------\n");
	printf("| Name     | Title        | Publisher         | Date |\n");
	node *curr = head;
	while(curr != NULL)
	{
		printf("---------------------------------------------------\n");
		printf("| %-5s | %-5s | %-5s | %-5d |\n", curr->name, curr->title, curr->publisher, curr->date);
		printf("---------------------------------------------------\n");
	}
	printf("--------------------------------------------------------\n");
}

//int datevalidate(char date[])
//{
//	if(date[0] > 0 || date[0] < 31)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}

void pushtail(char name[], char title[], char publisher[], int date)
{
	node *newnode = createnode(name, title, publisher, date);
	if(tail == NULL)
	{
		tail = head = newnode;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
	}
}

//void poptail(char name[])
//{
//	if(tail == NULL)
//		return;
//	else if(strcmp(head->name, tail) == 0)
//	{
//		free(head);
//		head = tail = NULL;
//	}
//	else
//	{
//		node *curr = head;
//		while(curr->next != NULL)
//		{
//			if(curr->next == tail)
//			{
//				curr->next = NULL;
//				free(tail);
//				tail = curr;
//				return;
//			}
//			curr = curr->next;
//		}
//	}
//}

int main()
{
	int opt, validate;
	char name[100], title[100], publisher[100], date[100], add[2];
	do
	{
		menu();
		scanf("%d", &opt); getchar();
		if(opt == 1)
		{
			do
			{
				printf("Input the name of the author: ");
				scanf("%[^,]", &name); getchar();
			}while(strlen(name) < 3);
			do
			{
				printf("Input the title of the journal: ");
				scanf("%[^\n]", &title); getchar();
			}while(strlen(title) < 5);
			do
			{
				printf("Input the publisher name: ");
				scanf("%[^\n]", &publisher); getchar();
			}while(strlen(publisher) < 5);
			do
			{
				printf("Input the date time it released: ");
				scanf("%d", &date); getchar();
			}while(date == 0);
			pushtail(name, title, publisher, 2016);
//			printf("Do you want to add more? [y|n]: ");
//			scanf("%s", &add); getchar();
//			if(strcmp(add, ) == 0)
//			{
//				do
//				{
//					do
//					{
//						printf("Input the name of the author: ");
//						scanf("%[^,]", &name); getchar();
//					}while(strlen(name) < 3);
//					do
//					{
//						printf("Input the title of the journal: ");
//						scanf("%[^\n]", &title); getchar();
//					}while(strlen(title) < 5);
//					do
//					{
//						printf("Input the publisher name: ");
//						scanf("%[^\n]", &publisher); getchar();
//					}while(strlen(publisher) < 5);
//					do
//					{
//						printf("Input the date time it released: ");
//						scanf("%d", &date); getchar();
//					}while(date < 1000 || date > 2023);
//					printf("Do you want to add more? [y|n]: ");
//					scanf("%c", &add); getchar();
//				}while(add == 'y' || add != 'n');
//			}
//			else
		}	
		if(opt == 2)
		{
			view(name, title, publisher, 2016); getchar();
		}
		if(opt == 3)
		{
			
		}
	}while(opt != 4);
}
