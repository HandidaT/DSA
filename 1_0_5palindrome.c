#include <stdio.h>
#include <string.h>

int IsPalindrome(char string[]){
    int count, countBack, end;

	end = strlen(string) - 1;
	for(count = 0, countBack = end; count <= end/2; count++, countBack--){
	    if(string[count] != string[countBack]){
            return 0;
		}
	}

    printf("%s is palindrome", string);
	return 1;
}

int main(){
	char s[100];
	scanf("%99s", s);
	IsPalindrome(s);
}