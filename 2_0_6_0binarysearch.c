// C program to implement iterative Binary Search
#include <stdio.h>
#include <math.h>

int binarysearchrecursive(int *arr,int l,int r,int x){
   if(r>=l){
	int mid=l+(r-l)/2;
	if(arr[mid]==x) return mid;// If the element is present at the middle
	if(arr[mid]>x) return binarysearchrecursive(arr,l,mid-1,x);
	else return binarysearchrecursive(arr,mid+1,r,x);
   }// We reach here when element is not present in array
   return -1;
}

int binarysearchiterative(int *arr,int l,int r,int find){
	while(l<=r){
		int m=l+(r-l)/2;//For finding mid in range of numbers for example in binary search, add half of the range(r-l) to the lower value(l) to get half(mid) value.
		if(arr[m]==find){return m;}
		if(arr[m]<find){l=m+1;}
		else{r=m-1;}
	}
	return -1;
}

int main(){
	int data[]={ 2, 3, 4, 10, 40 };
	int arrsize=sizeof(data)/sizeof(data[0]);
	int find=3;
	int result=binarysearchrecursive(data,0,arrsize-1,find);
    (result == -1) ? printf("Element is not present"
                            " in array")
                   : printf("Element is present at "
                            "index %d",
                            result);
	result=binarysearchiterative(data,0,arrsize-1,find);
    (result == -1) ? printf("\nElement is not present"
                            " in array")
                   : printf("\nElement is present at "
                            "index %d",
                            result);
	return 0;
}
