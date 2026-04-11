//a2r13c10
#include <stdio.h>
#include <string.h>
//fibonnaci number of 0 is 0, 1 is 1 by default. why? find out...
//fibonnaci numbers 0,1,1,2,3,5,8,13,21...

// ---------- Recursive ----------
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// ---------- Memoization ----------
int fib_memo(int n, int dp[]) {
    if (n <= 1) return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
    return dp[n];
}

// ---------- Tabulation ----------
int fib_tabulation(int n) {
    if (n <= 1) return n;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// ---------- Space Optimized ----------
int fib_optimized(int n) {
    if (n <= 1) return n;

    int prev2 = 0, prev1 = 1, curr;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    scanf("%d", &n);

    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    printf("Recursive: %d\n", fib_recursive(n));
    printf("Memoization: %d\n", fib_memo(n, dp));
    printf("Tabulation: %d\n", fib_tabulation(n));
    printf("Optimized: %d\n", fib_optimized(n));

    return 0;
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
