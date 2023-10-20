#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Order{
	char name[50];
	int amount;  
	Order* next; 
}*head = NULL,*tail = NULL;

struct userData{
	char number[50]; 
	char email[50]; 
	char name[50]; 
	int points; 
	userData* next; 
}*h = NULL, *t = NULL;

userData* makeUser(char number[], char email[], char name[], int points){
	userData* newUser = (userData*)malloc(sizeof(userData)); 
	strcpy(newUser->number, number);
	strcpy(newUser->email, email);
	strcpy(newUser->name, name); 
	newUser->points = points; 
	newUser->next = NULL; 
	return newUser; 
}

Order* makeOrder(char name[], int amount){
	Order* newOrder = (Order*)malloc(sizeof(Order)); 
	newOrder->amount = amount;
	strcpy(newOrder->name, name);
	newOrder->next = NULL; 
	return newOrder; 
}

void pushtailOrder(char name[], int amount){
	Order* newOrder = makeOrder(name, amount); 
	if(h == NULL){
		head = tail = newOrder;
	}
	else{
		tail->next = newOrder; 
		tail = newOrder; 
	}
	return; 
}

void pushtailUser(char number[], char email[], char name[], int points){
	userData* newUser = makeUser(number, email, name, points); 
	if(h == NULL){
		h = t = newUser;
	}
	else{
		t->next = NULL;
		t = newUser; 
	}
	return; 
}

void spacing(){
	for(int i = 0; i < 25; i++){
		printf("\n"); 
	}
}

void printMenu(){
	spacing(); 
	printf("BlueBucks\n");
	printf("==================\n"); 
	printf("1. Process Order\n");
	printf("2. View All Customer\n"); 
	printf("3. Remove Customer\n"); 
	printf("4. Exit\n"); 
	printf(">> "); 
}

int comValidation(char email[]){
	int flag = 0; // 18 
	int len, counter = 0; 
	char temp[10]; 
	len = strlen(email); 
	for(int i = 0; i < len; i++){
		if(email[i] == '.'){
			flag = i; 
		}
	}
	
	if(email[flag+1] == 'c' && email[flag+2] == 'o' && email[flag+3] == 'm'){
		counter++; 
	}
	
	if(counter == 1){
		return 1; 
	}
	else{
		return 2; 
	}
}

int coidValidation(char email[]){
	int flag = 0; // 18 
	int len, counter = 0; 
	char temp[10]; 
	len = strlen(email); 
	for(int i = 0; i < len; i++){
		if(email[i] == '.'){
			flag = i; 
			break;
		}
	}

	if(email[flag+1] == 'c' && email[flag+2] == 'o' && email[flag+3] == '.' && email[flag+4] == 'i' && email[flag+5] == 'd'){
		counter++; 
	}

	if(counter == 1){
		return 1; 
	}
	else{
		return 2; 
	}
}

int nameValidator(char name[]){
	int len; 
	
	len = strlen(name); 
	if(name[0] == 'M' && name[1] == 'r' && name[2] == '.'){
		return 1; 
	}
	else if(name[0] == 'M' && name[1] == 'r' && name[2] == 's' && name[3] == '.'){
		return 1; 
	}
	else{
		return 2; 
	}
	
}

void orderSummary(){
	Order* curr = head; 
	int total; 
	while(curr->next != NULL){
		printf("%s %dx = %d\n", curr->name, curr->amount, curr->amount*30000);
		total = total + curr->amount;  
		curr = curr->next; 
	}
	
}

void printNames(){
	userData* curr = h; 
	printf("====================================\n");
	printf("Name | Phone Number | Email | Points\n");
	printf("====================================\n");
	while(curr != NULL){
		printf("%s %s %s %d\n", curr->name, curr->number, curr->email, curr->points);
		printf("====================================\n"); 
		curr = curr->next;
	}
	return;
}

int searchUser(char number[]){
	userData* curr = h; 
	while(curr != NULL){
		if(strcmp(curr->number, number) == 0){
			return 1; 
		}
	}
	return 2;
}

int validator()
{
	
}

int main(){
	
	int input, checker = 0, checker2 = 0, overall, overall2; 
	char number[50], name[50], email[50], temp[50], option[2], drink[50]; 
	int freedrinks = 0, amount, ordernum = 0;
	int totalprice = 0, temppoints = 0, points = 0, temporary = 0; 
	int validator; 
	
	// .com = moc.@ 
	// .co.id = di.oc.@ 
	
	do{
		printMenu(); 
		scanf("%d", &input); 
		switch(input){ 
			case 1 :
				do{
					printf("Input phone number[10-13][numeric]: "); scanf("%s", number); getchar(); 
					validator = searchUser(number);
				}while(strlen(number) < 10 || strlen(number) > 13 || validator == 2); 
				do{
					printf("Input name[5-25][Mr. | Mrs.]: "); scanf("%[^\n]", name); getchar(); 
					overall = nameValidator(name); 
				}while(overall == 2 || strlen(name) < 5 || strlen(name) > 25 || validator == 2);
				do{
					printf("Input email[10-20][email format]: "); scanf("%s", email); getchar();
					checker = comValidation(email);
					checker2 = coidValidation(email); 
					if(checker == 2 && checker2 == 2){
						overall2 = 0; 
					}
					else if(checker == 1 || checker2 == 1){
						overall2 = 1; 
					} 
				}while(overall2 == 0 || strlen(email) < 10 || strlen(email) > 25); 
				printf("Insert Success !\n\n"); 
				printf("You have %d free drink(s) left.\n\n", freedrinks);	
				do{
					do{
						printf("Input drink [Cafe Latte | Caramel Macchiato| Cappucino | Cafe Mocha]: "); scanf("%[^\n]", drink); getchar();
					}while(strcmp(drink, "Cafe Latte") != 0 && strcmp(drink, "Caramel Macchiato") != 0 && strcmp(drink, "Cappucino") != 0 && strcmp(drink, "Cafe Mocha") != 0);
					do{
						printf("Input drink quantity[>=1]: "); scanf("%d", &amount); getchar();  
					}while(amount < 1);
					temporary = temporary + amount; 
					pushtailOrder(drink, amount);
					printf("Curr total = %d\n", temporary); 
					totalprice = temporary*30000; 
					temppoints = totalprice/50000;
					points += temppoints;
					printf("Total : %d\n", totalprice); 
					printf("Points Obtained : %d\n", points*3);
					printf("Do you want to order more? [y|n]: "); scanf("%c", option); getchar(); 
				}while(strcmp(option, "y") == 0); 
				
				pushtailUser(number, email, name, points); 
				break; 
			case 2 : 
				printNames(); 
				break; 
			
			case 3 :
				
				break; 
				
			case 4 : 
				return 0; 
				break; 
		}
		
	}while(input != 4); 
	printf("Your input is invalid! Please reload your program!\n"); 
	
	return 0; 
}
