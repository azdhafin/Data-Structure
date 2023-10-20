#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char stakeholder[][10]={"Lecturer", "Student"};
bool isShow = false;

struct node{
    int binusianID;
    char binusianName[26];
    char type[15];
    struct node *left;
    struct node *right;
}*root = NULL, *curr;

struct node *newNode(int binusianID, char binusianName[], char type[]){
    curr = (struct node *) malloc (sizeof(struct node));
    curr->binusianID = binusianID;
    strcpy(curr->binusianName, binusianName);
    strcpy(curr->type, type);
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

struct node *insert(struct node *ptr, int binusianID, char *binusianName, char *type){
	// insert code here
	if(ptr == NULL)
	{
		return newNode(binusianID, binusianName, type);
	}
	else
	{
		if(binusianID < ptr->binusianID && binusianName < ptr->binusianName && type < ptr->type)
		{
			ptr->left = insert(ptr->left, binusianID, binusianName, type);
		}
		else if(binusianID > ptr->binusianID && binusianName > ptr->binusianName && type > ptr->type)
		{
			ptr->right = insert(ptr->right, binusianID, binusianName, type);
		}
		else
		{
			return ptr;
		}
	}
    return ptr;
}

struct node *removeAll(struct node *ptr){
	// insert code here
	if(ptr == NULL)
	{
		return NULL;
	}
	free(ptr);
	removeAll(ptr->left);
	removeAll(ptr->right);
	
    return NULL;
}

void preOrder(struct node *root){
	// insert code here
	if(root == NULL)
	{
		return;
	}
	else
	{
		printf("|| %15d || %15s || %15s ||\n", root->binusianID, root->binusianName, root->type);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void print(struct node *root){
    if(root && isShow==true){
        printf("=========================================================\n");
        printf("||%15s || %15s || %15s ||\n", "Binusian ID", "Binusian Name", "Position");
        printf("=========================================================\n");
        preOrder(root);
        printf("=========================================================\n\n");
    }else{
        printf("No data ...\n");
    }
}

void validatePrintFlag(int checker){
    if(checker % 2 == 1) isShow = true;
    else isShow = false;
}

int getMenu(){
    int choice;
    printf("--------------------------------------------------\n");
    printf("|School of Computer Science Stakeholders Database|\n");
    printf("--------------------------------------------------\n");
    printf("1. Insert\n");
    if(!isShow)
        printf("2. Show View (Pre-Order)\n");
    else
        printf("2. Close View (Pre-Order)\n");
    printf("3. Exit\n");
    printf("Choice : ");
    scanf("%d", &choice);
    fflush(stdin);
    return choice;
}

void insertMenu(){
	// insert code here
	int id;
	char name[100], type[100];
	do
	{
		printf("Input your id: ");
		scanf("%d", &id); getchar();
	}while(id < 1 || id > 999);
	do
	{
		printf("input your name: ");
		scanf("%[^\n]", &name); getchar();
	}while(strlen(name) < 3 || strlen(name) > 20);
	do
	{
		printf("Input binusian type: ");
		scanf("%[^\n]", &type); getchar();
	}while(strcmp(type, "student") != 0 && strcmp(type, "lecturer") != 0);
	root = insert(root, id, name, type);
	printf("Press enter to continue..\n");
    getchar();
}

int main(){
    int choice;
    int checkerShow = 0;
    do{
        system("cls");
        if(isShow)
            print(root);
        choice = getMenu();
        switch(choice){
            case 1:
                insertMenu();
                break;
            case 2:
                checkerShow++;
                validatePrintFlag(checkerShow);
                break;
            case 3:
//                removeAll(root);
                printf("Thank you\n\n");
                printf("press enter to continue..\n");
                getchar();
                break;
        }
    }while(choice!=3);

    return 0;
}
