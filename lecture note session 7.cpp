#include <stdio.h>
#include <stdlib.h>

// satck code insertion
struct stack* push(struct stack* top)
{
	struct stack* ptr;
	ptr = (struct stack*) malloc(sizeof(struck* stack));
	ptr->data = val;
	if(top == NULL)
	{
		top = ptr;
		top->next = NULL;
	}
	else
	{
		ptr->next = top;
		top = ptr;	
	}
	return top;
}

//stack code deletion
struct stack* pop(struct stack *pop)
{
	struct stack *ptr;
	if(top == NULL)
	{
		printf("\n STACK UNDERFLOW");
	}
	else
	{
		top = top->next;
		printf("\nThe deleted value: %d", ptr->data);
		free(ptr);
	}
	return top;
}

//stack code display
struct stack* display(struct stack* top)
{
	struct stack *ptr;
	pr = top;
	if(top ==NULL)
	{
		printf("\n TACK IS FULL");
	}
	else
	{
		while(ptr != NULL)
		{
			printf("\n%d", ptr->data);
			ptr = ptr->next;
		}
		return top;
	}
}
