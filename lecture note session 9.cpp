#include <stdio.h>
#include <stdlib.h>

//representation of binary
struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
};
struct node *root = NULL;
//expression teree concept
struct Tnode
{
	char chr;
	struct Tnode *left;
	struct Tnode *right;
};

//expression tree from prefix
/*
	char s[MAXN];
	int p = 0;
	
	void f(struct Tnode *curr)
	{
		if(is_operator(s[p]))
		{
			p++; curr->left = newnode(s[p]);
			f(curr->left);
			p++; curr->right = newnode(s[p]);
			f(curr->right);
		}
	}
	
	main function :
	struct Tnode *root = newnode(s[p]);
	f root;
*/
//prefix transvesal
//void prefix(struct Tnode *curr)
//{
//	printf("%c", curr->chr);
//	if(furr->left != 0)
//		prefix(curr->left);
//	if(curr->right != 0)
//		prefix(curr->right);
//}

//postfix transvesal
//void prefix(struct Tnode *curr)
//{
//	if(furr->left != 0)
//		prefix(curr->left);
//	if(curr->right != 0)
//		prefix(curr->right);
//	printf("%c", curr->chr);
//}

//infix transvesal
//void prefix(struct Tnode *curr)
//{
//	if(furr->left != 0)
//		prefix(curr->left);
//	printf("%c", curr->chr);
//	if(curr->right != 0)
//		prefix(curr->right);
//}

int main()
{
	
	return 0;
}
