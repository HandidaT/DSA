#include <stdio.h>

int FactorialRecursive(int number){
    if(number == 0) return 1;
    return number * FactorialRecursive(number - 1);
}

int FactorialIterative(int number){
	int factorial = 1, temp = 1;

	while(temp <= number){
		factorial *= temp;
		temp++;
	}

    return factorial;
}

int main(){
     int number;
	 scanf("%d", &number);
	 printf("%d %d", FactorialRecursive(number), FactorialIterative(number));
}








































// int factorial_recursive(int num){
// 	if(num==0) return 1;
// 	return num * factorial_recursive(num-1);
// }

// int factorial_iterative(int num){
// 	int factorial=num,temp1;
// 	if(num==0) factorial=1;
// 	else{
// 		while(--num!=0){
// 			factorial=factorial*num;
// 		}
// 	}
// 	return factorial;
// }

// int main(){
// 	int num;
// 	scanf("%d",&num);
// 	printf("%d\n",factorial_recursive(num));
// 	printf("%d\n",factorial_iterative(num));
// }

