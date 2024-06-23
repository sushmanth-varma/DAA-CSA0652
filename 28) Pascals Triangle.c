#include <stdio.h>

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);
	int i,space,j;
    for (i = 0; i < numRows; i++) {
        int coeff = 1; // First element of each row is always 1

        // Print leading spaces for alignment
        for (space = 0; space < numRows - i - 1; space++) {
            printf(" ");
        }

        // Print elements of current row
        for (j = 0; j <= i; j++) {
            printf("%d ", coeff);
            coeff = coeff * (i - j) / (j + 1);
        }

        printf("\n");
    }

    return 0;
}

