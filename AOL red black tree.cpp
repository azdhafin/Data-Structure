#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data; 
	int color; 
	struct node* parent; 
	struct node* right; 
	struct node* left; 
};
struct node* root = NULL;

struct node* createNode(int data) 
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->color = 1; 
	newNode->parent = NULL;
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

struct node* bstInsert(struct node* root, struct node* newNode) 
{
	if(root == NULL)
		return newNode;

	if(newNode->data < root->data) 
	{
		root->left = bstInsert(root->left, newNode);
		root->left->parent = root;
	}
	else if(newNode->data > root->data) 
	{
		root->right = bstInsert(root->right, newNode);
		root->right->parent = root;
	}

	return root;
}

void rightRotate(struct node* node) 
{
	struct node* leftChild = node->left;
	node->left = leftChild->right;

	if(leftChild->right != NULL)
		leftChild->right->parent = node;

	leftChild->parent = node->parent;

	if(node->parent == NULL)
		root = leftChild;
	else if(node == node->parent->left)
		node->parent->left = leftChild;
	else
		node->parent->right = leftChild;

	leftChild->right = node;
	node->parent = leftChild;
}

void leftRotate(struct node* node) 
{
	struct node* rightChild = node->right;
	node->right = rightChild->left;

	if(rightChild->left != NULL)
		rightChild->left->parent = node;

	rightChild->parent = node->parent;

	if(node->parent == NULL)
		root = rightChild;
	else if(node == node->parent->left)
		node->parent->left = rightChild;
	else
		node->parent->right = rightChild;

	rightChild->left = node;
	node->parent = rightChild;
}

void fixViolation(struct node* root, struct node* newNode) 
{
	struct node* parent = NULL;
	struct node* grandParent = NULL;

	while ((newNode != root) && (newNode->color != 0) && (newNode->parent->color == 1)) 
	{
		parent = newNode->parent;
		grandParent = newNode->parent->parent;

		if(parent == grandParent->left) 
		{
			struct node* uncle = grandParent->right;
			if(uncle != NULL && uncle->color == 1) 
			{
				grandParent->color = 1;
				parent->color = 0;
				uncle->color = 0;
				newNode = grandParent;
			}
			else 
			{
				if(newNode == parent->right)
				{
					leftRotate(parent);
					newNode = parent;
					parent = newNode->parent;
				}

				rightRotate(grandParent);
				int temp = parent->color;
				parent->color = grandParent->color;
				grandParent->color = temp;
				newNode = parent;
			}
		}
		else 
		{
			struct node* uncle = grandParent->left;
			if(uncle != NULL && uncle->color == 1) 
			{
				grandParent->color = 1;
				parent->color = 0;
				uncle->color = 0;
				newNode = grandParent;
			}
			else 
			{
				if(newNode == parent->left) 
				{
					rightRotate(parent);
					newNode = parent;
					parent = newNode->parent;
				}

				leftRotate(grandParent);
				int temp = parent->color;
				parent->color = grandParent->color;
				grandParent->color = temp;
				newNode = parent;
			}
		}
	}

	root->color = 0; 
}

void inorder(struct node* node) 
{
	if(node == NULL)
		return;
	inorder(node->left);
	printf("%d ", node->data);
	inorder(node->right);
}

int main() 
{
	int n = 10;
	int elements[10] = { 41, 22, 5, 51, 48, 29, 18, 21, 45, 3};
	for(int i = 0; i < n; i++) 
	{
		struct node* newNode = createNode(elements[i]);
		root = bstInsert(root, newNode);
		fixViolation(root, newNode);
	}
	printf("Inorder Traversal of Created Tree: \n");
	inorder(root);

	return 0;
}

