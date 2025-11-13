//a1r28c0
#include <stdio.h>
#include <errno.h>

#ifdef linux
#include <sys/stat.h>
#elif _WIN32
#include <direct.h>
#endif

void file_handling(){
    FILE *filePtr = fopen("file1.txt", "w+");

    if(filePtr){
        printf("file created/opened\n");
    }else{
        printf("Error creating/opening file\n");
    }

    char content[100], ch;
    scanf("%s", content);
    fprintf(filePtr, "%s", content);

    printf("-------------\n");
    rewind(filePtr);
    while((ch=fgetc(filePtr)) != EOF){
        printf("%c", ch);
    }

    if(fclose(filePtr)){
        printf("Error closing file");
    }
}

int main(){
  file_handling();
  return 0;
}

// int main(){
//   FILE *fp1=fopen("filehandling.txt","w+");
//   if(fp1==NULL)
//   {
//     printf("Error");
//   }
//   fprintf(fp1,"%d %s",7,"Hey those");

//   rewind(fp1);//to move file pointer offset to beggining of file.

//   char a[20];
//   int b;
//   fscanf(fp1,"%d %[^\n]",&b,a);
//   printf("---%s--%d--",a,b);

//   fclose(fp1);
  
// #ifdef linux
//    int rtCode = mkdir("newdir",0777);
// #elif _WIN32
//    int rtCode = _mkdir("newdir");
// #endif

//    if (rtCode){
// //     printf("\nFolder created\n");
// //   }else if(errno==EEXIST){
//      perror("Error");
//    }else {
//      perror("Folder creation - Error");
//      //exit(1);
//    }
//    printf("%d %d",rtCode,EEXIST);


//   return 0;
// }
