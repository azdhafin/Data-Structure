#include <stdio.h>
#include <stdlib.h>
// heaps -> find the smallest element of a set
// max heaps -> each parent is larger than the child
// min heap -> each parent is smaller than the child

const int MAX_ELEMENT = 1000;
int heap[MAX_ELEMENT];
int heap_size = 0;

int parent(int idx)
{
	return (idx-1)/2;
}

int leftchild(int idx)
{
	return 2*idx+1;
}

int rightchild(int idx)
{
	return 2*idx+2;
}

//needs tobe
int assert(int parentidx, int childidx)
{
//	return heap[parentidx] < heap[childidx]; // minheap
	return heap[parentidx] > heap[childidx]; //maxheap
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//index of the child
void upheap(int idx)
{
	if(idx <= 0)
	{
		return;
	}
	int parentidx = parent(idx);
	if(!assert(parentidx, idx))
	{
		swap(heap+idx, heap+parentidx); // is equivalent to swap(&heap[idx], &heap[parentidx]);
		upheap(parentidx);
	}
}

void insert(int val)
{
	heap[heap_size] = val;
	upheap(heap_size);
	heap_size += 1;
}

void inorder(int idx, int tab)
{
	if(idx >= heap_size)
	{
		return;
	}
	// only for visualization!!
	inorder(rightchild(idx), tab+1);
	for(int i=0; i<tab; i++)
	{
		printf("\t");
	}
	printf("%d\n", heap[idx]);
	inorder(leftchild(idx), tab+1);
}

void downheap(int idx)
{
	if(idx >= heap_size)
		return;
	// find the samllest of the parentand its two children
	// best candidate found so far
	int replacementidx = idx;
	int leftidx = leftchild(idx);
	int rightidx = rightchild(idx);
	
	if(leftidx < heap_size && !assert(replacementidx, leftidx))
	{
		replacementidx = leftidx;
	}
	if(rightidx < heap_size && !assert(replacementidx, rightidx))
	{
		replacementidx = rightidx;
	}
	if(replacementidx != idx)
	{
		swap(heap+replacementidx, heap+idx);
		downheap(replacementidx);
	}
}

// pops the top most element (root)
// which is also the smallest/largest value
// depending on the heap type
int del()
{
	int temp = heap[0];	
	//do something to delete heap[0]
	heap[0] = heap[--heap_size];
	downheap(0);
	
	return temp;
}

void print()
{
	inorder(0, 0);
	printf("=========================\n");
}

int main()
{
	for(int i=0; i<20; i++)
	{
		insert(i);
		print();
	}
//	insert(20);
//	print();
//	insert(10);
//	print();
//	insert(5);
//	print();
//	insert(1);
//	print();
	
	while(heap_size > 0)
	{
		printf("popped: %d\n", del());
		print();
	}
	
	
	return 0;
}
