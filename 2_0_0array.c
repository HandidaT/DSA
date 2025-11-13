#include <limits.h>
#include <stdio.h>
#include <stdlib.h>






































//Dynamc array##########################################################################################################################
//Array implementation. Very similar to c++ vector data structure. Capacity only increases, be wary.
typedef struct activations{
	int name;
	int activation;
} activations;

typedef struct dynamic_arr{
	int size,front;
	unsigned capacity;
	activations *array;
} d_arr;

d_arr* create_d_arr(unsigned capacity){
	d_arr* arr= malloc(sizeof(*arr));
	arr->size= arr->front = 0;
	arr->capacity=capacity;
	arr->array=malloc(arr->capacity * sizeof(arr->array));
	return arr;
}

// Queue is full when size becomes equal to the capacity
int ifFull(d_arr *arr){
	return arr->size==arr->capacity;
}
 
// Queue is empty when size is 0
int ifEmpty(d_arr *arr){
	return arr->size==0;
}

// Function to add an item to the dynamic array at rear.
void insert(d_arr *arr,int x){
	if(ifFull(arr)){
		arr->capacity=arr->capacity * 2;
		activations *array1=malloc(arr->capacity * sizeof(*array1));
		for(int i=0;i<arr->size;i++){
			array1[i].name=arr->array[i].name;
		}
		free(arr->array);
		arr->array=array1;
	}
	arr->array[arr->size].name=x;
	arr->size=arr->size+1;
}

//void delete(d_arr *arr,){}//No delete for array, only replace

//circular array#######################################################################################3
//https://www.geeksforgeeks.org/circular-array/
//https://embeddedartistry.com/blog/2017/05/17/creating-a-circular-buffer-in-c-and-c/
void circular_array(char a[], int size, int start)
{
    // print from ind-th index to (n+i)th index.
    for (int i = start; i < size + start; i++)
        printf("%c ",a[(i % size)]);
}


int main(){
	//array
	int a[]={1,2,3};//array with 3 elements
	int *b=a;//base address of a is assigned to pointer
	for(int i=0;i<3;i++) printf("%d ",b[i]);


	d_arr* darray=create_d_arr(3);
	printf("\nInitial capacity %d\n",darray->capacity);
	insert(darray,5);
	insert(darray,5);
	insert(darray,5);
	insert(darray,5);
	printf("\nCurrent capacity %d\n",darray->capacity);
	for(int i=0;i<darray->size;i++){
		printf("%d",(darray->array)[i].name);
	}
	free(darray->array);
	free(darray);

	char a1[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	int n = sizeof(a1) / sizeof(a1[0]);
	circular_array(a1, n, 3);
}

