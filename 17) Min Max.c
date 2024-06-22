#include <stdio.h>

// Function to find minimum and maximum using Divide and Conquer
void findMinMax(int arr[], int left, int right, int minmax[2]) {
    if (left == right) { // Only one element
        minmax[0] = arr[left]; // min
        minmax[1] = arr[right]; // max
    } else if (right - left == 1) { // Two elements
        if (arr[left] < arr[right]) {
            minmax[0] = arr[left]; // min
            minmax[1] = arr[right]; // max
        } else {
            minmax[0] = arr[right]; // min
            minmax[1] = arr[left]; // max
        }
    } else { // More than two elements
        int mid = (left + right) / 2;
        int leftMinMax[2], rightMinMax[2];

        // Recursively find min and max in left and right halves
        findMinMax(arr, left, mid, leftMinMax);
        findMinMax(arr, mid + 1, right, rightMinMax);

        // Determine minimum and maximum from left and right halves
        if (leftMinMax[0] < rightMinMax[0]) {
            minmax[0] = leftMinMax[0]; // min
        } else {
            minmax[0] = rightMinMax[0]; // min
        }

        if (leftMinMax[1] > rightMinMax[1]) {
            minmax[1] = leftMinMax[1]; // max
        } else {
            minmax[1] = rightMinMax[1]; // max
        }
    }
}

int main() {
    int arr[] = {3, 5, 1, 9, 8, 4, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int minmax[2];

    findMinMax(arr, 0, n - 1, minmax);

    printf("Minimum element: %d\n", minmax[0]);
    printf("Maximum element: %d\n", minmax[1]);

    return 0;
}
