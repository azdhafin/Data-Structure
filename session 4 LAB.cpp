#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node
{
	char ID[6]; // ST001
	char name[30];
	int age;
	node* next;	
};

struct linkedlist
{
	node* head;
	node* tail;
};

int inc = 1;
node* createnode(char name [], int age)
{
	node* newnode = (node*) malloc(sizeof(node));
	strcpy(newnode->name, name);
	newnode->age = age;
	//random
	//sprintf(newnode->ID, "ST%d03", 1 + rand() % 100);
	//incremental 
	sprintf(newnode->ID, "ST%03d", inc++);
	newnode->next = NULL;
	
	return newnode;
}

const int MAX_ELEMENT = 10;

node* hashtable[10]; // head of linked list

void preptable()
{
	for(int i=0; i<MAX_ELEMENT; i++)
	{
		hashtable[i] = NULL;
	}
}

int hashing(char str[])
{
	int ret = 0;
	for(int i=0; i<strlen(str); i++)
	{
		ret += str[i];
	}
	return ret % MAX_ELEMENT;
}

void insert(char name[], int age)
{
	node* newnode = createnode(name, age);
	int idx = hashing(newnode->ID);
	
	//linked list part
	// pushtail
	if(hashtable[idx] == NULL)
		hashtable[idx] = newnode;
	else
	{
		node* curr = hashtable[idx];
		while(curr != NULL)
		{
			if(curr->next == NULL)
			{
				curr->next = newnode;
				return;
			}
			curr = curr->next;
		}
	}
}

void print()
{
	for(int i=0; i<MAX_ELEMENT; i++)
	{
		printf("%d: ", i);
		node* curr = hashtable[i];
		while(curr != NULL)
		{
			printf("(%s): %s,%d ---> ", curr->ID, curr->name, curr->age);
			curr = curr->next;
		}
		printf("NULL\n");
	}
}

void pop(char id[])
{
	int idx = hashing(id);
	
	// hashtable 
	// popmid
	if(hashtable[idx] == NULL)
	{
		return;
	}
	else if(strcmp(hashtable[idx]->ID, id) == 0) // pophead
	{
		node* temp = hashtable[idx]->next;
//		node* todelete = hashtable[idx]->next;
		free(hashtable[idx]);
		hashtable[idx] = temp;
	}
	else //popmid
	{
		node* curr = hashtable[idx];
		while(curr->next != NULL)
		{
			if(strcmp(curr->next->ID, id) == 0)
			{
				node* temp = curr->next->next;
				free(curr->next);
				curr->next = temp;
				return;
			}
			curr = curr->next;
		}
	}
}

void popall()
{
	for(int i=0; i<MAX_ELEMENT; i++)
	{
		if(hashtable[i] != NULL)
		{
			node* curr = hashtable[i];
			while(curr != NULL)
			{
				node* temp = curr->next;
				free(curr);
				curr = temp;
			}
			hashtable[i] = NULL;
		}
	}
}

// search by key
node*searchID(char id[])
{
	int idx = hashing(id);
	node* curr = hashtable[idx];
	while(curr != NULL)
	{
		if(strcmp(curr->ID, id) == 0)
		{
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

node* searchname(char name[])
{
	for(int i=0; i<MAX_ELEMENT; i++)
	{
		node* curr = hashtable[i];
		while(curr != NULL)
		{
			if(strcmp(curr->name, name) == 0)
				return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

void printTidy()
{
	for(int i=0; i<MAX_ELEMENT; i++)
	{
		printf("%d: ", i);
		node* curr = hashtable[i];
		while(curr != NULL)
		{
			printf("ID: %s\nName: %s\nAge: %d\n == ", curr->ID, curr->name, curr->age);
			curr = curr->next;
		}
		printf("NULL\n");
	}
}

int main()
{
//	srand(time(NULL));
//	node* a = createnode("test", 5);
//	printf("%s\n", a->ID);
//	a = createnode("test", 5);
//	printf("%s", a->ID);

	preptable();
	insert("test", 5);
	insert("test2", 10);
	insert("test3", 15);
	print();
//	popall();
	printf("\n");
	printTidy();
	puts("");
//	preptable();
	
	return 0;
}
