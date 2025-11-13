// C program for implementation of selection sort
#include <stdio.h>

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n){
	int i, j, min_idx;
	for (i = 0; i < n-1; i++){// One by one move boundary of unsorted subarray
		min_idx = i;// Find the minimum element in unsorted array
		for (j = i+1; j < n; j++)
			if (arr[j] < arr[min_idx]) min_idx = j;
		swap(&arr[min_idx], &arr[i]);// Swap the found minimum element with the first element
	}
}

void printArray(int arr[], int size){/* Function to print an array */
	for (int i=0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}

int main(){// Driver program to test above functions
	int arr[] = {64, 25, 12, 22, 0, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}

