#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char id[50];
	char title[50];
	char author[50];
	long long int isbn;
	int pg;
	node *next;
} *head = NULL, *tail = NULL;

node *createnode(char id[], char title[], char author[], long long int isbn, int pg)
{
	node *newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->id, id);
	strcpy(newnode->title, title);
	strcpy(newnode->author, author);
	newnode->isbn = isbn;
	newnode->pg = pg;
	newnode->next = NULL;
	
	return newnode;
}

node *hashtable[1007];

void preptable()
{
	for(int i=0; i<1007; i++)
	{
		hashtable[i] = NULL;
	}
}

int hashing(char id[])
{
	int ret = 0;
	for(int i=0; i<strlen(id); i++)
	{
		ret += id[i];
	}
	return ret%1007;
}

void insert(char id[], char title[], char author[], long long int isbn, int pg)
{
	node *newnode = createnode(id, title, author, isbn, pg);
	int idx = hashing(newnode->id);
	if(hashtable[idx] == NULL)
	{
		hashtable[idx] = newnode;
	}
	else
	{
		node *curr = hashtable[idx];
		while(curr != NULL)
		{
			if(curr->next != NULL)
			{
				curr->next = newnode;
				return;	
			}	
			curr = curr->next;
		}
	}
}

int hash(char id[])
{
	int ret = 0;
	for(int i=0; i<1007; i++)
	{
		ret += id[i];
	}
	return ret%1007;
}

void menu()
{
	printf("Bluejack Library\n");
	printf("================\n");
	printf("1. View book\n");
	printf("2. Insert book\n");
	printf("3. Remove book\n");
	printf("4. Exit\n");
	printf(">> ");
}

int validate(int check)
{
	for(int i=0; i<1007; i++)
	{
		if(hashtable[i] == NULL)
		{
			printf("There is no book(s)!\n\n");
			printf("Press enter to continue..\n"); getchar();
			check = 0;
		}
	}
	check = 1;
	return check;
}

int existance(char title[], int check)
{
	node *curr = head;
	while(strcmp(curr->title, title) != 0)
	{
		curr = curr->next;
		if(curr == NULL)
		{
			check = 0;
			break;
		}
	}
	if(strcmp(curr->title, title) == 0)
	{
		printf("The book already title already exist !\n");	
	}
	check = 1;
	return check;
}

void remove(char id[])
{
	int flag = hash(id);
	if(hashtable[flag] == NULL)
	{
		return;
	}
	else if(strcmp(hashtable[flag]->id, id) == 0)
	{
		node *temp = hashtable[flag]->next;
		free(hashtable[flag]);
		temp = (hashtable[flag]);
	}
}

void table()
{
	node *curr = head;
	printf("-----------------------------------------------------------------------\n");
	printf("|Book ID     | Book Title     | Book Author     | ISBN     | Page Num |\n");
	while(curr != NULL)
	{
		printf("|%-5s | %-5s | %-5s | %-5d | %-5d |\n", curr->id, curr->title, curr->author, curr->isbn, curr->pg);
		printf("-----------------------------------------------------------------------\n");
	}
	puts("");
	printf("Press enter to continue..\n"); getchar();
}

double ID(long long int isbn, char author[], char title[])
{
	int j=1;
	for(int i=0; i<1007; i++)
	{
		printf("B%4d-%d-%s%s\n", j, isbn, author[0], title[0]);
		j++;
	}
}

int main()
{
	int check=0, temp, pg;
	int opt;
	long long int isbn;
	char title[100], author[100], id[100];
	do
	{
		menu();
		scanf("%d", &opt); getchar();
		if(opt == 1)
		{
			temp = validate(check);
			if(temp == 0)
			{
				getchar();
			}
			else
			{
				table();
			}
		}
		if(opt == 2)
		{
			do
			{
				printf("Input book title[5-50] word: ");
				scanf("%[^\n]", &title); getchar();
				temp = existance(title, check);
			}while(strlen(title) < 5 || strlen(title) > 50);
			do
			{
				printf("Input author name [Mr|Mrs] & [3-25 char]: ");
				scanf("%[^\n]", &author); getchar();
			}while(strlen(author) < 3 || strlen(author) > 25 && author != "Mr" || author != "Mrs");
			do
			{
				printf("Input ISBN[10-13][numeric]: ");
				scanf("%lld", &isbn); getchar();
			}while(isbn < 10 || isbn > 13);
			do
			{
				printf("Input page number [at least 16]: ");
				scanf("%d", &pg); getchar();
			}while(pg < 16);
			ID(isbn, author, title);
			insert(ID, title, author, isbn, pg);
		}
		if(opt == 3)
		{
			remove(id);
		}
	}while(opt != 4);
	printf("Thank you for using our library !!\n");
	
	return 0;
}
