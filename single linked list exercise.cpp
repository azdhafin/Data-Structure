#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node *next;	
};
node *head = NULL;
node *tail = NULL;

node *createnode(int num)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->value = num;
	newnode->next = NULL;
	return newnode;
}

void pushhead(int num)
{
	node *newnode = createnode(num);
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

void pushtail(int num)
{
	node *newnode = createnode(num);
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

void pushmid(int num)
{
	if(head == NULL || num <= head->value)
		pushhead(num);
	else if(num >= tail->value)
		pushtail(num);
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
			curr = curr->next;
		}
	}
}

void pophead()
{
	if(head == NULL)
		return;
	else if(head == tail)
	{
		free(head); //to free the memory in the head
		head = tail = NULL;
	}
	else
	{
		node *temp = head->next;
		free(head);
		head = temp;
	}
}

void poptail()
{
	if(tail == NULL) //head or tail is the same
		return;
	else if(tail == head)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		node *curr = head;
		while(curr != NULL)
		{
			if(curr->next == tail)
			{
				curr->next = NULL;
				free(tail);
				tail = curr;
			}
			curr = curr->next;
		}
	}
}

void popmid(int num)
{
	if(head == NULL)
	{
		return;
	}
	else if(num == head->value)
	{
		pophead();
	}
	else if(num == tail->value)
	{
		poptail();
	}
	else
	{
		node *curr = head;
		while(curr->next != NULL)
		{
			if(curr->next->value == num)
			{
				node *temp = curr->next->next;
				free(curr->next);
				curr->next = temp;
				return;
			}
			curr = curr->next;
		}
	}
	
}

void search(int num)
{
	node *curr = head;
	while(curr != NULL)
	{
		if(curr->value == num)
		{
			printf("The value is found at %d\n", curr->value);
			break;
		}
	}
	if(curr == NULL)
	{
		printf(" %d The value is not found\n", num);
	}
}

void print()
{
	node *curr = head;
	while(curr != NULL)
	{
		printf("%d -> ", curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
	if(head != NULL)
	{
		printf("Head: %d\n", head->value);
	}
	if(tail != NULL)
	{
		printf("Tail: %d\n", tail->value);
	}
}

int main()
{
	
	pushhead(4);
	pushhead(10);
	pushhead(3);
	pushhead(5);
	print();
	pushmid(4); print();
	
	return 0;
}


