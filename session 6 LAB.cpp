#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	node *left;
	node *right;	
};

node *createnode(int val)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->val = val;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

node *insert(node *curr, int val)
{
	if(curr == NULL)
		return createnode(val);
	else
	{
		if(val < curr->val)
		{
			curr->left = insert(curr->left, val);
		}
		else if(val > curr->val)
		{
			curr->right = insert(curr->right, val);
		}
		else
		{
			return curr;
		}
	}
	return curr;
}

node *search(node *curr, int val)
{
	if(curr == NULL)
	{
		printf("%d is not found\n", val);
		return NULL;
	}
	else
	{
		if(val < curr->val)
		{
			return search(curr->left, val);
		}
		else if(val > curr->val)
		{
			return search(curr->right, val);
		}
		else if(val == curr->val)
		{
			printf("%d is found\n", val);
			return curr;
		}
	}
}

void preorder(node *curr)
{
	if(curr == NULL)
	{
		return;
	}
	else
	{
		printf("%d -> ", curr->val);
		preorder(curr->left);
		preorder(curr->right);
	}
}

void inorderintended(node *root, int count)
{
	if(root == NULL)
	{
		return;
	}
	inorderintended(root->right, count+1);
	for(int i=0; i<count; i++)
	{
		printf("\t");
	}
	printf("%d\n", root->val);
	inorderintended(root->left, count+1);
}

void postorder(node *curr)
{
	if(curr == NULL)
	{
		return;
	}
	else
	{
		postorder(curr->left);
		postorder(curr->right);
		printf("%d -> ", curr->val);
	}
}

// left once then right
node *predecessor(node *root)
{
	node *curr = curr->left;
	while(curr != NULL)
	{
		if(curr->right == NULL)
		{
			return curr;
		}
		curr = curr->right;	
	}
	return NULL;
}

node *deletenode(node *root, int val)
{
	if(root == NULL)
	{
		printf("%d not found\n", val);
		return NULL;
	}
	else if(val < root->val)
	{
		root->left = deletenode(root->left, val);
		return root;
	}
	else if(val > root->val)
	{
		root->right = deletenode(root->right, val);
		return root;
	}
	else // equal to the current node
	{
		//case 1, one child
//		if(root->left == NULL && root->right == NULL)
//		{
//			free(root);
//			return NULL;
//		}
		//case 2, two children
//		else if(root->left != NULL && root->right == NULL)
//		{
//			node *temp = root->left;
//			free(root);
//			return temp;
//		}
		//case 3, three children
//		else
//		{
//			node *replacement = predecessor(root);
//			root->val = replacement->val;
//			replacement->val = val;
//			root->left = deletenode(root->left, val);
//			return root;
//		}	
		
		//case 3
		if(root->left != NULL && root->right != NULL)
		{
			node *replacement = predecessor(root);
			root->val = replacement->val;
			replacement->val = val;
			root->left = deletenode(root->left, val);
		}
		else
		{
			node *temp = root->left != NULL ? root->left : root->right;
			free(root);
			return temp;
		}
	}
}

//postorder
node *deleteall(node *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	free(root);
	deleteall(root->left);
	deleteall(root->right);
	
	return NULL;
}

node *updatenode(node *root, int oldval, int newval)
{
	root = deletenode(root, oldval);
	return insert(root, newval);
}

void printdebug(node *root)
{
	inorderintended(root, 0);
	printf("------------------------------\n");
}


int main()
{
	node *root = NULL;
	root = insert(root, 50);
	root = insert(root, 70);
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 80);
	root = insert(root, 90);

	preorder(root);
	puts("");
	puts("");
	printdebug(root);
	deletenode(root, 90);
	deletenode(root, 80);
	printdebug(root);
	deletenode(root, 10);
	printdebug(root);
	root = updatenode(root, 30, 55);
	printdebug(root);
	predecessor(root);
	printdebug(root);
	
	return 0;
}
