#include <iostream>

void merge(int arr[],int p, int q, int r){
    int i,j,k,lsize=q-p+1,rsize=r-q;
    int L[lsize],R[rsize];
    //creating temporary left and right arrays
    for(i=0;i<lsize;i++){
        L[i]=arr[p+i];
    }
    for(j=0;j<rsize;j++){
        R[j]=arr[q+1+j];
    }
    i=0;
    j=0;
    k=p;
    //merging arrays in sorted order
    while(i<lsize && j<rsize){
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
    //merging the array with leftover elements
    while(i<lsize){
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

void mergesort(int arr[], int l, int r, int n){
    if(l<r){
        int m=(l+(r-1))/2;
        mergesort(arr,l,m,n);
        mergesort(arr,m+1,r,n);
        merge(arr,l,m,r);
    }
}

int main(){
    int n;//size of the original array
    std::cin>>n;
    std::cout<<n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    //Start Mergesort
    mergesort(arr,0,n-1,n);
    std::cout<<"\n\n";
    //print out sorted array
    for(int i=0;i<n;i++){
        std::cout<<arr[i];
    }
}