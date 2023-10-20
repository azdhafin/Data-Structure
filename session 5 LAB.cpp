#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//catetan:
/*
recursive fungsi yang memanggil dirinya sendiri!
3 case/condition:
	1. base condition = kondisi yang membuat rekusif ini berhenti ketika telah menemuan solusi
	2. call condition = kondisi yang memanggil fungsi itu lagi namun biasanya dengan parameter yang mendekati base condition
	3. stop condition = kondisi yang membuat rekursif berhenti jika tidak mendapatkan solusi
	
contoh Fibonacci: 
0, 1, 1, 2, 3, 5, 8, 13, 21, 34,...
f(n) = f(n-1) + f(n+2)

f(4) = 3
base case:
	if(n <= 1) 
		return n;
call condition:
	return f(n-1) + f(n+2); nb
stop condition:
	if(n < 0)
		return n;
*/

//more note:
/*
predesesor = ke left sekali trus ke kanan sampe NULL
suksesor = ke kanan trus ke left sampe NULL
*/

struct node
{
	int value;
	node *right, *left;	
};

node *createnode(int value)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->value = value;
	newnode->left = newnode->right = NULL;
	return newnode;
}

node *insert(node *curr, int value)
{
	if(curr == NULL)
		return createnode(value);
	else
	{
		if(value < curr->value)
		{
			curr->left = insert(curr->left, value);
		}
		else if(value > curr->value)
		{
			curr->right = insert(curr->right, value);
		}
		else
		{
			return curr;
		}
	}
	return curr;
}

node *search(node *curr, int value)
{
	if(curr == NULL)
	{
		printf("%d is not found\n", value);
		return NULL;
	}
	else
	{
		if(value < curr->value)
		{
			return search(curr->left, value);
		}
		else if(value > curr->value)
		{
			return search(curr->right, value);
		}
		else if(value == curr->value)
		{
			printf("%d is found\n", value);
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
		printf("%d -> ", curr->value);
		preorder(curr->left);
		preorder(curr->right);
	}
}

void inorder(node *curr)
{
	if(curr == NULL)
	{
		return;
	}
	else
	{
		inorder(curr->left);
		printf("%d -> ", curr->value);
		inorder(curr->right);
	}
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
		printf("%d -> ", curr->value);
	}
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
	inorder(root);
	puts("");
	postorder(root);
	puts("");
	search(root, 70);
	search(root, 100);
	search(root, 20);
	return 0;
}
