#include <stdio.h>


void insertionsort(int *a, int n){
	int key,i;
	for(int j=0;j<n;j++){
		key=a[j];
		i=j-1;
		while(i>-1 & a[i]>key){
			a[i+1]=a[i];
			i=i-1;
		}
		a[i+1]=key;
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
