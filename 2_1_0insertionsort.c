#include <stdio.h>


void insertionsort(int *a, int n){
	int key,j;
	for(int i=0;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>-1 & a[j]>key){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}

int main(){
  int a[]={6,3,7,8,2,5,4,0};
  int len=sizeof(a)/sizeof(a[0]);
  printf("%zu %ld %ld %d\n",sizeof(int),sizeof(a),sizeof(a)/sizeof(a[0]),len);//size of type int

  insertionsort(a,len);

  for(int i=0;i<len;i++){
     printf("%d ",a[i]);
  }
}
