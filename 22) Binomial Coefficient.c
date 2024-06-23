#include <stdio.h>

// Function to calculate binomial coefficient C(n, k)
int binomialCoeff(int n, int k) {
    int C[k + 1];
    
    // Initialize all elements of the array to 0
    int i,j;
    for (i = 0; i <= k; i++) {
        C[i] = 0;
    }
    
    // Base case
    C[0] = 1;  // C(n, 0) is always 1

    // Calculate value of Binomial Coefficient in bottom-up manner
    for (i = 1; i <= n; i++) {
        // Compute next row of pascal triangle using the previous row
        for (j = k; j > 0; j--) {
            C[j] = C[j] + C[j - 1];
        }
    }

    return C[k];
}

int main() {
    int n = 5, k = 2;
    printf("C(%d, %d) = %d\n", n, k, binomialCoeff(n, k));
    return 0;
}

