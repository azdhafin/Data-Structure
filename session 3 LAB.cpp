#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
	char name[255];
	int value;
	node *next, *prev;	
}*head, *tail;

node *createnode(int value)
{
	node* newnode = (node*) malloc(sizeof(node*));
	newnode->value = value;
	newnode->next = newnode->prev = NULL;
	return newnode;
}

void pushhead(int value)
{
	node *newnode = createnode(value);
	if(!head) // head == NULL
	{
		head = tail = newnode;
//		return;
	}
	else
	{
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}
}

void pushtail(int value)
{
	node *newnode = createnode(value);
	if(!tail) // tail == NULL
	{
		tail = head = newnode;
//		return;
	}
	else
	{
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
}

void pushmid(int value)
{
	node *newnode = createnode(value);
	node *curr = head;
	if(head->value > value)
	{
		pushhead(value);
	}
	if(tail->value < value)
	{
		pushtail(value);
	}
	while(curr != NULL)
	{
		if(curr->value > value)
		{
			curr->prev->next = newnode;
			newnode->prev = curr->prev;
			curr->prev = newnode;
			newnode->next = curr;
		}
		curr = curr->next;
	}
}

void pophead()
{
	if(head == NULL) 
	if(head ==  tail)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		node *temp = head;
		head = temp->next;
		head->prev = NULL;
		free(temp);
	}
}

void poptail()
{
	if(tail == NULL) 
	if(tail ==  head)
	{
		free(tail);
		tail = head = NULL;
	}
	else
	{
		node *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);	
	}
}

//void popmid(int value)
//{
//	node *curr = head;
//	while(curr != NULL)
//	{
//		if(curr->value == value)
//		{
//			node *temp = curr;
//			curr->prev->next = curr->next;
//			curr->next->prev = curr->prev;
//			free(temp);
//			return;	
//		}
//	}
//}

node *search(int value)
{
	node *curr = head;
	while(curr != NULL)
	{
		if(curr->value == value)
		{
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}

void popvalue(int value)
{
	node *target = search(value);
	if(target == NULL)
		return;
	else if(target == head)
		pophead();
	else if(target == tail)
		poptail();
	else
	{
		node *prevoftarget = target->prev;
		target->prev->next = target->next;
		target->next->prev = prevoftarget;
		free(target);
	}
}

printlist()
{
	node *curr = head;
	printf("NULL");
	while(curr != NULL)
	{
		printf("<-[ %d ]->", curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
}

int main()
{
	pushhead(5);
	printlist();
	
	pushhead(3);
	printlist();
	
	pushtail(7);
	printlist();
	
	pushmid(6);
	printlist();
	
//	pophead();
//	printlist();
//	
//	poptail();
//	printlist();

//	popmid(5);
//	printlist();
	
	popvalue(6);
	printlist();
	
	return 0;
}
