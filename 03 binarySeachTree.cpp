//
// Created by Hanry Ham on 2019-04-02.
//

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

struct node *newNode(int binusianID, char *binusianName, char *type){
    curr = (struct node *) malloc (sizeof(struct node));
    curr->binusianID = binusianID;
    strcpy(curr->binusianName, binusianName);
    strcpy(curr->type, type);
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

struct node *insert(struct node *ptr, int binusianID, char *binusianName, char *type){
    if(ptr == NULL){
        ptr = newNode(binusianID, binusianName, type);
    }else{
        if(binusianID < ptr->binusianID)
            ptr->left = insert(ptr->left, binusianID, binusianName, type);
        else if(binusianID > ptr->binusianID)
            ptr->right = insert(ptr->right, binusianID, binusianName, type);
        else
            printf("Value should be unique!\n");
    }
    return ptr;
}

struct node *successor(struct node *ptr){
    //right subtree, get the smallest
    curr = ptr->right;
    while(curr->left){
        curr = curr->left;
    }
    return curr;
}

struct node *remove(struct node * ptr, int binusianID){
    if(ptr == NULL) return NULL;

    if(binusianID < ptr->binusianID){
        ptr->left = remove(ptr->left, binusianID);
    }else if(binusianID > ptr->binusianID){
        ptr->right = remove(ptr->right, binusianID);
    }else{
        if((ptr->left == NULL) || (ptr->right == NULL)){

            struct node *temp = NULL;
            if(ptr->left != NULL) temp = ptr->left;
            else temp = ptr->right;

            if(temp == NULL){
                temp = ptr;
                ptr = NULL;
            }else{
                *ptr = *temp;
            }
            free(temp);
        }else{
            // have 2 children
            struct node *temp = successor(ptr);
            ptr->binusianID = temp->binusianID;
            strcpy(ptr->binusianName, temp->binusianName);
            strcpy(ptr->type, temp->type);
            ptr->right = remove(ptr->right, temp->binusianID);
        }
    }
    return ptr;
}

struct node *removeAll(struct node *ptr){
    if(ptr){
        ptr->left = removeAll(ptr->left);
        ptr->right = removeAll(ptr->right);
        free(ptr);
        ptr = NULL;
    }
    return ptr;
}

struct node *search(struct node *ptr, int binusianID){
    if(ptr == NULL)
        return NULL;
    if(binusianID == ptr->binusianID)
        return ptr;
    if(binusianID < ptr->binusianID)
        return search(ptr->left, binusianID);
    if(binusianID > ptr->binusianID)
        return search(ptr->right, binusianID);
}

void preOrder(struct node *root){
    if(root){
        printf("||%15d || %15s || %15s ||\n", root->binusianID, root->binusianName, root->type);
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
    printf("3. Delete\n");
    printf("4. Exit\n");
    printf("Choice : ");
    scanf("%d", &choice);
    fflush(stdin);
    return choice;
}

void insertMenu(){
    int binusianID;
    char binusianName[26];
    char type[15];
    struct node* tmpSearch;

    do{
        printf("\n\nBinusian ID [1..999] : ");
        scanf("%d", &binusianID);
        fflush(stdin);
    }while(binusianID<1 || binusianID>999);
    tmpSearch = search(root, binusianID);

    if(!tmpSearch){
        do{
            printf("Binusian Name [5..25] : ");
            scanf("%[^\n]", binusianName);
            fflush(stdin);
        }while(strlen(binusianName)<5 || strlen(binusianName)>25);

        do{
            printf("Binusian type [Student / Lecturer] : ");
            scanf("%s", type);
            fflush(stdin);
        }while(strcmpi(stakeholder[0], type)!=0 && strcmpi(stakeholder[1], type)!=0);

        root = insert(root, binusianID, binusianName, type);
        printf("Successfully added ...");
    }else{
        printf("%d is existed, data can not be added", binusianID);
    }
    getchar();
}

void removeMenu(){
    struct node *tmp;
    int binusianID;
    printf("Binusian ID to delete : ");
    scanf("%d", &binusianID);
    fflush(stdin);

    tmp = search(root, binusianID);
    if(tmp){
        root = remove(root, binusianID);
        printf("%d has been removed\n", binusianID);
    }
    else{
        printf("%d can not be found in the system\n", binusianID);
    }
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
                removeMenu();
                getchar();
                break;
            case 4:
                removeAll(root);
                printf("Thank you");
                getchar();
                break;
        }
    }while(choice!=4);

    return 0;
}
