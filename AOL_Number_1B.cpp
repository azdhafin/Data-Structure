#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    int color;
    struct Node *left, *right, *parent;
};

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->color = 0;
    node->left = node->right = node->parent = NULL;
    return node;
}

void leftRotate(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        (*root) = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        (*root) = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void fixInsert(Node **root, Node *z) {
    while (z->parent != NULL && z->parent->color == 0) {
        if (z->parent == z->parent->parent->left) {
            Node *y = z->parent->parent->right;

            if (y != NULL && y->color == 0) {
                z->parent->color = 1;
                y->color = 1;
                z->parent->parent->color = 0;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }

                z->parent->color = 1;
                z->parent->parent->color = 0;
                rightRotate(root, z->parent->parent);
            }
        } else {
            Node *y = z->parent->parent->left;

            if (y != NULL && y->color == 0) {
                z->parent->color = 1;
                y->color = 1;
                z->parent->parent->color = 0;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }

                z->parent->color = 1;
                z->parent->parent->color = 0;
                leftRotate(root, z->parent->parent);
            }
        }
    }

    (*root)->color = 1;
}

void insert(Node **root, int data) {
    Node *node = createNode(data);
    Node *y = NULL;
    Node *x = (*root);

    while (x != NULL) {
        y = x;

        if (node->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;

    if (y == NULL)
        (*root) = node;
    else if (node->data < y->data)
        y->left = node;
    else
        y->right = node;

    node->color = 0;

    fixInsert(root, node);
}

void inOrder(Node *root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int main() {
    Node *root = NULL;

    insert(&root, 41);
    insert(&root, 22);
    insert(&root, 5);
    insert(&root, 51);
    insert(&root, 48);
    insert(&root, 29);
    insert(&root, 18);
    insert(&root, 21);
    insert(&root, 45);
    insert(&root, 3);

    printf("Inorder Traversal of Created Tree\n");
    inOrder(root);

    return 0;
}

