#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int findMaxRepeatingElement(int arr[], int n) {
    int greatestElement = INT_MIN;
    for(int i=0; i<n; i++){
        if(greatestElement < arr[i])
            greatestElement = arr[i];
    }

    int *count = (int*)calloc(greatestElement, sizeof(arr[0]));

    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    int mostOccuringElement = arr[0];
    int maxCount = count[arr[0]];
    for(int i=1; i<n; i++){
        if(maxCount < count[arr[i]]){
            mostOccuringElement = arr[i];
        }
    }

    free(count);

    return mostOccuringElement;
}

int main() {
    int arr[] = {2, 3, 11, 5, 3, 11, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = n; // The size of the array or max element + 1

    int maxRepeatingElement = findMaxRepeatingElement(arr, n);

    printf("The maximum repeating element is %d\n", maxRepeatingElement);

    exec("./a.out");

    return 0;
}







// int CheckPowerOf2(int n){
//     if((n & (n-1)) == 0)
//         return 1;
//     else
//         return 0;
// }

// void CheckPowerOf4(int n){
//     if(CheckPowerOf2(n)){
//         int c = 0;
//         while((n & 1) == 0){
//             c++;
//             n >>= 1;
//         }
//         if((c && (c % 2)) == 0){
//             printf("Power of 4\n");
//         }
//     }else
//         printf("Not power of 4\n");
// }

// int main(){
//     int x = 4;

//     if(CheckPowerOf2(x))
//         printf("Power of 2\n");
//     else
//         printf("Not power of 2\n");

//     CheckPowerOf4(x);
// }