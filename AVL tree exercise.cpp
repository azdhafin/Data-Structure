#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
	int height, bf, val;
	char name[50], type[50];
	node *left, *right;
};

node *createnode(char name[], char type[], int val)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left = newnode->right = NULL;
	newnode->height = 0;
	newnode->bf = 1;
	newnode->val = val;
	strcpy(newnode->name, name);
	strcpy(newnode->type, type);
}

node *updatenode(node *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	int left = root->left ? root->left->height : 0;
	int right = root->right ? root->right->height : 0;
	root->height = 1 + (left > right ? left : right);
	root->bf = left - right;
}

node *leftrotate(node *oldroot)
{
	if(oldroot == NULL)
	{
		return NULL;
	}
	node *newroot = oldroot->right;
	node *temp = newroot->left;
	
	newroot->left = oldroot;
	oldroot->right = temp;
	
	updatenode(newroot);
	updatenode(oldroot);
	
	return newroot;
}

node *rightrotate(node *oldroot)
{
	if(oldroot == NULL)
	{
		return NULL;
	}
	node *newroot = oldroot->left;
	node *temp = newroot->right;
	
	newroot->right = oldroot;
	oldroot->left = temp;
	
	updatenode(newroot);
	updatenode(oldroot);
	
	return newroot;
}

node *rotation(node *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(root->bf <= -2)
	{
		if(root->right->bf >= 1)
		{
			root->right = rightrotate(root->right);
		}
		return leftrotate(root);
	}
	else if(root->bf >= 2)
	{
		if(root->left->bf <= -1)
		{
			root->left = leftrotate(root->left);
		}
		return rightrotate(root);
	}
	return root;
}

node *insert(node *root, char name[], char type, int val)
{
	if(root == NULL)
	{
		return createnode(name, type, val);
	}
	else if(strcmp(name, root->name) < 0)
	{
		root->left = insert(root->left, name, type, val);
	}
	else if(strcmp(name, root->name) > 0)
	{
		root->right = insert(root->right, name, type, val);
	}
	else
	{
		puts("Duplicated values");
	}
	updatenode(root);
	root = rotation(root);
	return root;
}

node *deletenode(node *root, char name[], char type[], int val)
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(strcmp(name, root->name) < 0)
	{
		root->left = deletenode(root->left, name, type, val);
	}
	else if(strcmp(name, root->name) > 0)
	{
		root->right = insert(root->right, name, type, val);
	}
	else
	{
		if(root->left && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left == NULL)
		{
			node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			node *temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			node *successor = root->right;
			while(successor->left != NULL)
			{
				successor = successor->left;
			}
			strcpy(root->name, successor->name);
			root->right = deletenode(root->right, successor->name, successor->type, successor->val);
		}
	}
}

node *search(node *root, char name[])
{
	if(root == NULL || strcmp(name, root->name) == 0)
	{
		return NULL;
	}
	else if(strcmp(name, root->name) < 0)
	{
		root->left = search(root->left, name);
	}
	else
	{
		root->right = search(root->right, name);
	}
}

void inorder(node *root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf("--------------\n");
		inorder(root->right);
	}
}
