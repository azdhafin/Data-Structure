#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int value;
    struct node* next;
};

node* head = NULL;
node* tail = NULL;

node* makenode(int val)
{
	node* newnode = (node*) malloc(sizeof(node*));
//	(*newnode).vall
	newnode->value = val;
	newnode->next = NULL;
	return newnode;
}

void pushhead(int val)
{
	node* newnode = makenode(val);
	if(head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
}

void pushtail(int val)
{
	node* newnode = makenode(val);
	if(tail == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
	}
}

void pushmid(int val)
{
	if(head == NULL || val <= head->value)
	{
		pushhead(val);
	}
	else if(val >= tail->value)
	{
		pushtail(val);
	}
	else
	{
		node* curr = head;
		node* newnode = makenode(val);
		while(curr->next != NULL)
		{
			if(curr->next->value >= val)
			{
				newnode->next = curr->next;
				curr->next = newnode;
				return;
			}
			curr = curr->next;
		}
	}
}

void print()
{
	node* curr = head;
	while(curr != NULL)
	{
		printf("%d - >", curr->value);
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

void pophead()
{
	if(head == NULL)
	{
		return;
	}
	else if(head == tail)
	{
		free(head);
		head = NULL;
		tail = NULL;
	}
	else
	{
		node* temp = head->next;
		free(head);
		head = temp;
	}
}

void poptail()
{
	if(tail == NULL)
	{
		return;
	}
	else if(head == tail)
	{
		free(tail);
		head = NULL;
		tail = NULL;
	}
	else
	{
		node* curr = head;
		while(curr->next != NULL)
		{
			if(curr->next == tail)
			{
				curr->next = NULL;
				free(tail);
				tail = curr;
				return;
			}
			curr = curr->next;
		}
	}
}

void popmid(int val)
{
	if(head == NULL)
		return;
	else if(val == head->value)
		pophead();
	else if(val == tail->value)
		poptail();
	else
	{
		node* curr = head;
		while(curr->next != NULL)
		{
			if(curr->next->value == val)
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

void search(int val)
{
	node * curr = head;
	while(curr != NULL)
	{
		if(curr->value == val)
		{
			printf("%d is found in the list\n", val);
			break;
		}
		curr = curr->next;
	}
	if(curr == NULL)
	{
		printf("%d is not found in the list\n", val);
	}
}

//void pushstack(int val)
//{
//	pushhead(val);
//}
//
//void popstack(int val)
//{
//	pophead(val);
//}

int main() 
{
//	node* test = makenode(5);
//	printf("%d", test->value);
	pushhead(4);
	pushhead(10);
	pushhead(3);
	pushhead(4);
	print();
	poptail(); print();
//	search(10);
	
    return 0;
}


