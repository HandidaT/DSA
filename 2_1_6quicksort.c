#include <stdio.h>
#include <stdlib.h>

// Recursive quicksort#########################################################################
void rswap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int rpartition (int arr[], int low, int high){
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far. Starts with low-1 at beginning of partition function
    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){// If current element is smaller than the pivot
            i++; // increment index of smaller element
            rswap(&arr[i], &arr[j]);
        }
    }
    rswap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void rquickSort(int arr[], int low, int high){
    if (low < high){
        int pi = rpartition(arr, low, high);// pi is partitioning index, arr[p] is now at right place
        rquickSort(arr, low, pi - 1);// Separately sort elements before partition and after partition
        rquickSort(arr, pi + 1, high);
    }
}

void rprintArray(int arr[], int size){// Function to print an array
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//Iterative quicksort#########################################################################3333333
typedef struct activations {
  int name;
  int activation;
} activations;

void swap(activations* a, activations* b){
    activations t = *a;
    *a = *b;
    *b = t;
}

int partition(activations* arr, int l, int h){//This function is same in both iterative and recursive
    int x = arr[h].name;
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++) {
        if (arr[j].name <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
// A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSortIterative(activations* arr, int l, int h){
    int stack[h - l + 1];// Create an auxiliary stack
    int top = -1;// initialize top of stack
    stack[++top] = l;// push initial values of l and h to stack
    stack[++top] = h;
    while (top >= 0){// Keep popping from stack while is not empty
        h = stack[top--];// Pop h and l
        l = stack[top--];
        int p = partition(arr, l, h);// Set pivot element at its correct position in sorted array
        if (p - 1 > l) {// If there are elements on left side of pivot, then push left side to stack
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if(p+1 < h){// If there are elements on right side of pivot, then push right side to stack
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

void printArr(activations* arr, int n){// A utility function to print contents of arr
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i].name);
}

// Driver program to test above functions
int main(){
//Recursive quicksort#########################################################################3333333
    int rarr[] = {10, 7, 8, 9, 1, 5};
    int rn = sizeof(rarr) / sizeof(rarr[0]);
    rquickSort(rarr, 0, rn - 1);
    printf("Sorted array: \n");
    rprintArray(rarr, rn);

//Iterative quicksort#########################################################################3333333
    activations* array = malloc(10 * sizeof(*array));
    for(int i=0;i<10;i++){array[i].name=i;}
    array[0].name=4;
    array[1].name=3;
    array[2].name=5;
    array[3].name=2;
    array[4].name=1;	
    array[5].name=3;
    array[6].name=2;
    array[7].name=3;
    array[8].name=0;
    array[9].name=8;
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3, 0, 8 };
    int n = 10;//sizeof(array) / sizeof(*array);
    printf("%d\n",n);
    quickSortIterative(array, 0, n - 1);
    printArr(array, n);
    free(array);
    return 0;
}
