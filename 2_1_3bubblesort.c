// C program for implementation of Bubble sort
#include <stdio.h>
#include <stdbool.h>

void swap(int* xp, int* yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n){// A function to implement bubble sort
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){// Last i elements are already in place
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

void bubbleSortoptimized(int arr[], int n){// An optimized version of Bubble Sort
   bool swapped;
   for (int i = 0; i < n-1; i++){
     swapped = false;
     for (int j = 0; j < n-i-1; j++){
        if (arr[j] > arr[j+1]){
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
     if (swapped == false) break;// IF no two elements were swapped by inner loop, then break
   }
}

/* Function to print an array */
void printArray(int arr[], int size){
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 , 0};
	int arr1[] = { 64, 34, 25, 12, 22, 11, 90 , 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, n);
	bubbleSortoptimized(arr1, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	printf("Sorted array using bubblesort: \n");
	printArray(arr1, n);
	return 0;
}

