#include <stdio.h>

#define MAX 20

int set[MAX];
int subset[MAX];
int n;  // Number of elements in set
int target_sum;  // Target sum to be achieved

void printSubset(int subset[], int size) {
    printf("{ ");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

void sumOfSubsets(int set[], int subset[], int subset_size, int total, int node) {
    if (total == target_sum) {
        printSubset(subset, subset_size);
        return;
    }
	int i;
    for (i = node; i < n; i++) {
        if (total + set[i] <= target_sum) {
            subset[subset_size] = set[i];
            sumOfSubsets(set, subset, subset_size + 1, total + set[i], i + 1);
        }
    }
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
	int i;
    printf("Enter the elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    printf("Subsets with the given sum are:\n");
    sumOfSubsets(set, subset, 0, 0, 0);

    return 0;
}

