#include <stdio.h>
#include <stdlib.h>  // for qsort

#define MAX_ITEMS 100
#define MAX_CONTAINERS 100

// Function prototype for compare function used by qsort
int compare(const void *a, const void *b);

void firstFitDecreasing(int items[], int n, int capacity) {
    int bins[MAX_CONTAINERS] = {0};
    int binCount = 0;

    // Sort items in non-increasing order
    qsort(items, n, sizeof(int), compare);

    // Packing items into bins using First Fit Decreasing (FFD) heuristic
    int i;
    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j < binCount; j++) {
            if (bins[j] >= items[i]) {
                bins[j] -= items[i];
                break;
            }
        }
        if (j == binCount) {
            bins[binCount] = capacity - items[i];
            binCount++;
        }
    }

    printf("Number of bins required: %d\n", binCount);
    printf("Remaining capacity of each bin:\n");
    for (i = 0; i < binCount; i++) {
        printf("Bin %d: %d\n", i + 1, bins[i]);
    }
}

// Compare function for qsort: non-increasing order
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int items[MAX_ITEMS];
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter items sizes:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter capacity of each container: ");
    scanf("%d", &capacity);

    firstFitDecreasing(items, n, capacity);

    return 0;
}

