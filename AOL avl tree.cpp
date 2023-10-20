#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left, *right;
    int val;
    int height;
    int bf;
};

struct node *createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = val;
    newNode->height = 1;
    newNode->bf = 0;
    return newNode;
}

void updateNode(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    int left = root->left ? root->left->height : 0;
    int right = root->right ? root->right->height : 0;
    root->height = 1 + (left > right ? left : right);
    root->bf = left - right; // can also do right - left
}

struct node *leftRotate(struct node *oldRoot)
{
    if (oldRoot == NULL)
    {
        return NULL;
    }
    struct node *newRoot = oldRoot->right;
    struct node *temp = newRoot->left;
    newRoot->left = oldRoot;
    oldRoot->right = temp;

    updateNode(newRoot);
    updateNode(oldRoot);

    return newRoot;
}

struct node *rightRotate(struct node *oldRoot)
{
    if (oldRoot == NULL)
    {
        return NULL;
    }
    struct node *newRoot = oldRoot->left;
    struct node *temp = newRoot->right;
    newRoot->right = oldRoot;
    oldRoot->left = temp;

    updateNode(newRoot);
    updateNode(oldRoot);

    return newRoot;
}

struct node *rotation(struct node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->bf <= -2)
    {
        if (root->right->bf >= 1)
        {
            root->right = rightRotate(root->right);
        }
        return leftRotate(root);
    }
    else if (root->bf >= 2)
    {
        if (root->left->bf <= -1)
        {
            root->left = leftRotate(root->left);
        }
        return rightRotate(root);
    }
    return root;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
    }
    else if (val < root->val)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        printf("Duplicate value\n");
    }
    updateNode(root);
    root = rotation(root);
    return root;
}

struct node *findMinNode(struct node *root)
{
    struct node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node *deleteNode(struct node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    else if (val < root->val)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            struct node *temp = findMinNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    updateNode(root);
    root = rotation(root);
    return root;
}

void printPreorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->val);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(struct node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

void printPostorder(struct node *root)
{
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->val);
}


struct node *searchNode(struct node *root, int val)
{
    if (root == NULL || root->val == val)
    {
        return root;
    }
    if (val < root->val)
    {
        return searchNode(root->left, val);
    }
    else
    {
        return searchNode(root->right, val);
    }
}

void printTree(struct node *root, int tab)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->right, tab + 1);
    for (int i = 0; i < tab; i++)
    {
        printf("\t");
    }
    printf("%d(%d,%d)\n", root->val, root->height, root->bf);
    printTree(root->left, tab + 1);
}

void print(struct node *root)
{
    printf("Preorder: ");
    printPreorder(root);
    printf("\n");

    printf("Inorder: ");
    printInorder(root);
    printf("\n");

    printf("Postorder: ");
    printPostorder(root);
    printf("\n");

    printf("--------------------------------------\n");
}

int main()
{
    struct node *root = NULL;
    int choice, data, transvesal;
    struct node *search;
    do
    {
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Transvesal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &data);
            search = searchNode(root, data);
            if(search != NULL)
            {
            	printf("Data Found\n");
            	printf("Value %d was deleted\n", data);
			}
			else
			{
				printf("Data not found\n");
			}
            root = deleteNode(root, data);
            break;
        case 3:
            print(root);
            break;
        case 4:
        	printf("Thank you\n\n");
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while (choice != 4);

    return 0;
}

