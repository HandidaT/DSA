class J2_1_0insertionsort{
    
    public static void main(String args[]){
          int a[]={6,3,7,8,2,5},key,j;
          int lent=a.length;
          System.out.println(lent);
          char z=5;
/*
          {
            int bar=1;
            {
              int bar=2;
            }
          }
  */
  for(int i=0;i<lent;i++){
    key=a[i];
    j=i-1;
    //while(j>-1 & a[j]>key){
    while(j>-1 && a[j]>key){
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=key;
  }

  for(int i=0;i<lent;i++){
     System.out.print(a[i]);
  }
    }
}