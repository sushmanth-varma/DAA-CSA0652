#include <stdio.h>
#include <time.h>

int main() {
    int n = 100;
    int A[n][n], B[n][n], result[n][n];
    clock_t start_time = clock();
    int i,j,k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = 0;
            for (k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    clock_t end_time = clock(); 
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication (n = %d): %.10f seconds\n", n, time_taken);
    return 0;
}

