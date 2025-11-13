#include <stdio.h>
#include <string.h>

void reverse(char* begin, char* end)
{
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

void reverse_words(char *str){
    char *wordBegin = NULL;
    char *wordBoundary = str;

    while(*wordBoundary){
        if(wordBegin == NULL && *wordBoundary != ' '){
            wordBegin = wordBoundary;
        }

        char temp = *(wordBoundary+1);
        if(wordBegin && (temp == '\0' || temp == ' ')){
            reverse(wordBegin, wordBoundary);
            wordBegin = NULL;
        }

        wordBoundary++;
    }

    reverse(str, wordBoundary-1);
}

void tokenize(char str[], char * delimeter){
    if(strlen(str) == 0){
        return;
    }

    char *token;
    token = strtok(str, delimeter);
    while(token){
        printf("%s\n", token);
        token = strtok(NULL, delimeter);
    }
}

int countWords(char str[], char *delimeter){
    if(strlen(str) == 0){
        return 0;
    }

    char *token;
    token = strtok(str, delimeter);
    int count = 0;
    while(token != NULL){
        count++;
        token = strtok(NULL, delimeter);
    }

    return count;
}

int main(){
  // char s='a';
  // int b=2;
  // char* literal="This";
  // //printf("%c\n",s);
  // char arr1[8]="Thisisit";
  // char arr2[8]="ThisThis";
  // //printf("%s",strcat(strupr(arr[5]) ,  strupr(arr[6])));
  // strcpy(arr1,arr2);
  // printf("%s %s",arr1, literal);

  char s1[] = "i like this program very much";
  char* temp = s1;
  reverse_words(s1);
  printf("%s", s1);

  // char str[] = "abc this is a sample period";
  // char *delimeter = " ";
  // printf("No of words : %d", countWords(str, delimeter));
  // tokenize(str, delimeter);

  return 0;
}
