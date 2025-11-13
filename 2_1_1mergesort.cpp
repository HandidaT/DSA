//#include <bits/stdc++.h>
#include <iostream>
//using namespace std;

void merge(int arr[],int p, int q, int r);
 
// Utility function to find minimum of two integers
int min(int x, int y) { return (x<y)? x :y; }

void imergeSort(int arr[], int n){/* Iterative mergesort function to sort arr[0...n-1] */
   int curr_size;  // For current size of subarrays to be merged. curr_size varies from 1 to n/2
   int left_start; // For picking starting index of left subarray to be merged
   // Merge subarrays in bottom up manner.  First merge subarrays of size 1 to create sorted subarrays of size 2, then merge subarrays
   for (curr_size=1; curr_size<=n; curr_size = 2*curr_size){// of size 2 to create sorted subarrays of size 4, and so on.
       for (left_start=0; left_start<n; left_start += 2*curr_size){//Pick starting point of different subarrays of current size
           int mid = min(left_start + curr_size - 1, n);// Find ending point of left subarray. mid+1 is starting point of right
           int right_end = min(left_start + 2*curr_size - 1, n);
           std::cout<<"\nleft_start "<<left_start<<" curr_size "<<curr_size<<" mid "<<mid<<" right_end "<<right_end;
           merge(arr, left_start, mid, right_end);// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
       }
       std::cout<<"\n";
   }
}

void rmergesort(int arr[], int begin, int end){
   if(begin < end){
	   int mid=begin+((end-begin)/2);
	   rmergesort(arr,begin,mid);
	   rmergesort(arr,mid+1,end);
	   merge(arr,begin,mid,end);
   }
}

void merge(int arr[],int p, int q, int r){
    int i,j,k,lsize=q-p+1,rsize=r-q;
    int L[lsize],R[rsize];
    for(i=0;i<lsize;i++){//creating temporary left and right arrays
        L[i]=arr[p+i];
    }
    for(j=0;j<rsize;j++){
        R[j]=arr[q+1+j];
    }
    i=0;
    j=0;
    k=p;
    while(i<lsize && j<rsize){//merging arrays in sorted order
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<lsize){//merging the array with leftover elements
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<rsize){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        std::cout <<" "<< A[i];
    std::cout <<"\n";
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {3, 7, 6, 4, 5, 8, 2, 1, 0};
    int arr1[] = {3, 7, 6, 4, 5, 8, 2, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    std::cout <<"Given array is \n ";
    printArray(arr, n);
 
//    imergeSort(arr, n);
    rmergesort(arr,0, n-1);
    imergeSort(arr1,n-1);
    std::cout <<"\nSorted array is \n";
    printArray(arr, n);
    printArray(arr1, n);
    return 0;
}
