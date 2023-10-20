#include <stdio.h>
#include <stdlib.h>

struct node
{
	int value;
	node *left, *right;
	int height;
};

node *createnode(int value)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->value = value;
	newnode->height = 1;
	newnode->left = newnode->right = NULL;
	return newnode;
}

int getmax(int left, int right)
{
	return left > right ? left : right;
}

int getheight(node *curr)
{
	return curr == NULL ? 0 : curr->height;
}

int getbalance(node *curr)
{
	return curr == NULL ? 0 : getheight(curr->left) - getheight(curr->right);
}

node *rightrotate(node *curr)
{
	node *x = curr->left;
	node *temp = x->right;
	x->right = curr;
	curr->left = temp;
	curr->height = 1 + getmax(getheight(curr->left), getheight(curr->right));
	x->height = 1 + getmax(getheight(x->left), getheight(x->right));
	return x;
}

node *leftrotate(node *curr)
{
	node *x = curr->right;
	node *temp = x->left;
	x->left = curr;
	curr->right = temp;
	curr->height = 1 + getmax(getheight(curr->left), getheight(curr->right));
	x->height = 1 + getmax(getheight(curr->left), getheight(curr->right));
	return x;
}

node *selfbalance(node *curr)
{
	curr->height = 1 + getmax(getheight(curr->left), getheight(curr->right));
	int balance = getbalance(curr);
	if(balance > 1 && getbalance(curr->left) >= 0) return rightrotate(curr);
	if(balance > 1 && getbalance(curr->left) < 0)
	{
		curr->left = leftrotate(curr->left);
		return rightrotate(curr);
	}
	if(balance < -1 && getbalance(curr->left) <= 0) return leftrotate(curr);
	if(balance < -1 && getbalance(curr->left) > 0)
	{
		curr->right = rightrotate(curr->right);
		return leftrotate(curr);
	}
	return curr;
}

node *insertnode(node *curr, int value)
{
	if(curr == NULL) curr = createnode(value);
	else if(value < curr->value) curr->left = insertnode(curr->left, value);
	else if(value > curr->value) curr->right = insertnode(curr->right, value);
	else return curr;
	return selfbalance(curr);
}

node *getpredecessor(node *curr)
{
	node *temp = curr->left;
	while(temp->right)
	{
		temp = temp->right;
	}
	return temp;	
}

node *getsucessor(node *curr)
{
	node *temp = curr->right;
	while(temp->left)
	{
		temp = temp->left;
	}
	return temp;
}

node *search(node *curr, int value)
{
	if(curr == NULL) return  NULL;
	else if(value < curr->value)
	{
		return curr->left = search(curr->left, value);	
	}	
	else if(value > curr->value)
	{
		return curr->right = search(curr->right, value);
	}
	return curr;
}

node *deletenode(node *curr, int value)
{
	if(curr == NULL)
	{
		return curr;
	}
	else if(value < curr->value)
	{
		curr->left = deletenode(curr->left, value);
	}
	else if(value > curr->value)
	{
		curr->right = deletenode(curr->right, value);
	}
	else
	{
		if(!curr->left && !curr->right)
		{
			free(curr);
			curr = NULL;
			return NULL;
		}
		else if(!curr->left || !curr->right)
		{
			node *temp = (!curr->left) ? curr->right : curr->left;
			free(curr);
			curr = NULL;
			return temp;
		}
		else
		{
			node *temp = getpredecessor(curr);
			curr->value = temp->value;
			curr->left = deletenode(curr->left, temp->value);
			return selfbalance(curr);
		}
	}
	return selfbalance(curr);
}

node *updatenode(node *curr, int value, int newvalue)
{
	node *temp = NULL;
	temp = deletenode(curr, value);
	temp = insertnode(curr, newvalue);
	return temp;
}
void inorder(node *curr, int tab)
{
	if(curr != NULL)
	{
		inorder(curr->right, tab+1);
		for(int i=0; i<tab; i++)
		{
			printf("\t");	
		}
		printf("%d\n", curr->value);
		inorder(curr->left, tab+1);
	}
}

int main()
{
	node *root = NULL;
	root = insertnode(root, 10);
	root = insertnode(root, 20);
	root = insertnode(root, 30);
	root = insertnode(root, 40);
	root = insertnode(root, 50);
	root = insertnode(root, 60);
	inorder(root, 0);
	printf("-----------------------------------\n");
	root = deletenode(root, 50);
	root = deletenode(root, 30);
	root = deletenode(root, 40);
	inorder(root, 0);
	printf("==================================\n");
	node *target = search(root, 50);
	printf("%d", target->value);
	printf("==================================\n");
	root = updatenode(root, 10, 25);
	inorder(root, 0);
	
	return 0;
}
