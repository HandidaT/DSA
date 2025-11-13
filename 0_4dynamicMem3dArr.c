#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 3; // Size of the first dimension
    int y = 4; // Size of the second dimension
    int z = 5; // Size of the third dimension

    // Allocate memory for the 3D array
    float ***array3D = (float ***)malloc(x * sizeof(float **));
    for (int i = 0; i < x; i++) {
        array3D[i] = (float **)malloc(y * sizeof(float *));
        for (int j = 0; j < y; j++) {
            array3D[i][j] = (float *)malloc(z * sizeof(float));
        }
    }

    // Initialize and access the elements of the 3D array
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                array3D[i][j][k] = (i + 1) * 100 + (j + 1) * 10 + (k + 1);
                printf("array3D[%d][%d][%d] = %.1f\n", i, j, k, array3D[i][j][k]);
            }
        }
    }

    // Free memory for the 3D array
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            free(array3D[i][j]);
        }
        free(array3D[i]);
    }
    free(array3D);

    return 0;
}






























































/*
int main(){
	time_t begin=time(NULL);
	sleep(2);
	time_t end=time(NULL);
	time_t timetaken=end-begin;
	printf("%ld",timetaken);
}*/
