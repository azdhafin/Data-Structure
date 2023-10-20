#include <stdio.h>
#include <string.h>

struct database
{
	int num;
	char name[20];
};
void swap(struct data *a, struct data *b)
{
	struct data *temp;
	temp = *a;
	*a = *b;
	*b = temp;
	
}
struct person
{
	char name[255];
	int age;
}person2;

void printarray(int arr[])
{
	for(int i=0; i<=sizeof(arr)/sizeof(int); i++)
	{
		printf("%d\n", arr[i]);
	}puts(" ");
}
int main()
{
	//struct
	person person3;
	person *ptr = &person3;
	strcpy(person3.name, "Guido");
	person3.age = 10;
	printf("address of name    : %s\n", &person3.name);
	printf("address of age     : %d\n", person3);
	printf("address of person 3: %d\n", person3.age);
	
	strcpy(data[0].name, "Vincent");
	data[0].age = 10;
	
	/*
	Array is a storage to store data where the data is homogenous
	create: data_type variable's_name[size];
	insert: 
		1. declare it next to array
		2. declare it via index
	*/
//	int num[5] = {1, 2, 3, 4, 5};
//	num[0] = 1;
//	printf("%lld\n", num);
//	*(num+1) = 2;
//	printarray(num);

//create an array without declaring an array

//	int *num = (int *)malloc(sizeof(int)*5);
//	*num = 1;
//	*(num+1) = 2;
//	num[2] = 3;
//	printarray(num);

//	int num1 = 10;
//	int num2 = 5;
//	int *ptr = &num1;
//	int **ptr2 = &ptr;
//	*ptr = 5;
//	
//	printf("the value of num1 pointed");
//	printf("the value of num: %d\n", num1);
//	printf("the value of num1 pointed at ptr: %d\n", *ptr);
//	printf("the address of num1 %x\n", &num1);
//	printf("the value of ptr: %x\n", ptr);
//	printf("the address of ptr: %x\n", &ptr);
	
	return 0;
}
