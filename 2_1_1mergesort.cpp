#include <iostream>

void merge(int arr,int p, int q, int r, int n){
    int i,j,k,lsize=q-p+1,rsize=r-q;
    int L[lsize],R[rsize];
    for(i=0;i<lsize;i++){
        L[i]=arr[p+i];
    }
    for(j=0;j<rsize;j++){
        R[j]=arr[q+1+j];
    }
    i=0;
    j=0
    k=0;
}

void mergesort(int arr[], int l, int r, int n){
    int mid=l+(r-1)/2;
    mergesort(arr,l,mid,n);
    mergesort(arr,mid+1,r,n);
    merge(arr,l,mid,r,n);
}

int main(){
    size_t n;//size of the original array
    std::cin>>n;
    std::cout<<n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    mergesort(arr,0,n-1,n)
    for(int i=0;i<n;i++){
        std::cout<<"\n"<<arr[i];
    }
}