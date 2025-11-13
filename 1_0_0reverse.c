#include <stdio.h>

void PrintBits32(int n){
    printf("\n");
    for(int i = 31; i>=0; i--){
        printf("%d", (n>>i) & 1);
    }
    printf("\n");
}

void ReverseBits(int *n){
    int Original = *n;
    int Reversed = 0;

    for(int i = 0; i<32; i++){
        Reversed <<= 1;
        Reversed |= (Original & 1);
        Original >>= 1;
    }

    *n = Reversed;
}

int reverse(int n){
	int rev=0;
	while(n>0){
		rev=(rev*10) + n%10;
		n/=10;
	}
	return rev;
}

int main(){
	int num;
	scanf("%d",&num);
	printf("%d",reverse(num));

    int num1 = 5;
    PrintBits32(num1);
    ReverseBits(&num1);
    PrintBits32(num1);
}










/*
int reverse(int x){
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;//modulus of negative numbers returns negative result
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
}
//if(ans >2147483647 || ans < -2147483648)
//                return 0;

int main(){
	int num;
	scanf("%d",&num);
	printf("%d",reverse(num));
}*/
