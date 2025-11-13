//a2r13c10
#include <stdio.h>
#include <string.h>
//fibonnaci number of 0 is 0, 1 is 1 by default. why? find out...
//fibonnaci numbers 0,1,1,2,3,5,8,13,21...

int FibonnaciRecursive(int number){
   if(number <= 1) return number;
   return FibonnaciRecursive(number-1) + FibonnaciRecursive(number-2);
}

int FibonnaciRecursiveMemoization(int number, int array[]){
   if(number <= 1) {array[number] = number; return number;}
   if(array[number] != 0) return array[number];
   int result = FibonnaciRecursiveMemoization(number-1, array)
                + FibonnaciRecursiveMemoization(number-2, array);
   array[number] = result;
   return result;
}

int FibonnaciTabulation(int number, int array[]){
    array[0] = 0;
    array[1] = 1;
    for(int i = 2; i<=number; i++){
        array[i] = array[i-1] + array[i-2];
    }
    return array[number];
}

int FibonnaciSpaceOptimized(int number){
    int a=0, b=1, result;
    if(number <= 1) return number;
    for(int i=2; i<=number; i++){
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main(){
    int num;
    scanf("%d", &num);
    int arr1[num + 1];
    int arr2[num + 1];

    int arrSizeInBytes = sizeof(arr1);
    memset(arr1, 0, arrSizeInBytes);

    printf("%d %d %d %d", FibonnaciRecursive(num), FibonnaciRecursiveMemoization(num, arr1)
                        , FibonnaciTabulation(num, arr2), FibonnaciSpaceOptimized(num));
}












// int fib_recursive(int num){
//    if(num<=1){ return num;}
//    return fib_recursive(num-1)+fib_recursive(num-2);
// }

// int fib_recursive_memoization(int num,int arr[]){//It is refered to as top down, but due to recursion, calculation-
//    if(num<=1){ arr[num]=num; return num;} //happens after base resursive call is reached and values are calculated bottom up
//    if(arr[num]!=0) return arr[num];
//    int result=fib_recursive_memoization(num-1,arr)+fib_recursive_memoization(num-2,arr);
//    arr[num]=result;
//    return result;
// }
// //In memoization approach we start from n and go down(top down approach) till all sub problems are solved, and most importantly we save the computed values in memo table.

// int fib_tabulation(int num,int arr[]){//dynamic programming tabulation/iterative/bottom up approach - starts from 0, 1,...till n
//    arr[0]=0;
//    arr[1]=1;
//    for(int i=2;i<=num;i++){
//       arr[i]=arr[i-1]+arr[i-2];
//    }
//    return arr[num];
// }

// int fib_spaceoptimized(int num){//iterative and no array is used to store
//    int a=0,b=1,c;
//    if(num<=1) return num;
//    for(int i=2;i<=num;i++){
//       c=b+a;
//       a=b;
//       b=c;
//    }
//    return c;
// }


// int main(){
//    int num;
//    scanf("%d", &num);
//    int arr1[num+1];//as numbers are one more than input number
//    int arr2[num+1];
//    for(int i=0;i<=num;i++){ arr1[i]=0;  printf("%d ", arr1[i]);}
//    printf("\n");
//    for(int i=0;i<=num;i++){ arr2[i]=0;  printf("%d ", arr2[i]);}
//    printf("\nfib recursive %d\n", fib_recursive(num));
//    printf("fib memoization %d\n", fib_recursive_memoization(num,arr1));
//    printf("fib tabulation %d\n", fib_tabulation(num,arr2));
//    for(int i=0;i<=num;i++){ printf("%d ", arr1[i]);}
//    printf("\n");
//    for(int i=0;i<=num;i++){ printf("%d ", arr2[i]);}
//    printf("\nfib space optimized %d", fib_spaceoptimized(num));
// }
