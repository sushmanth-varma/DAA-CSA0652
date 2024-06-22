#include <stdio.h>

// Function to perform knapsack using greedy approach
void knapsack_greedy(int capacity, int weights[], int values[], int n) {
    // Calculate value-to-weight ratio and store in an array
    double value_per_weight[n];
    int i,j;
    for (i = 0; i < n; i++) {
        value_per_weight[i] = (double) values[i] / weights[i];
    }

    // Sort items based on value-to-weight ratio in descending order (using simple swap-based bubble sort)	
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (value_per_weight[j] < value_per_weight[j + 1]) {
                // Swap value_per_weight
                double temp = value_per_weight[j];
                value_per_weight[j] = value_per_weight[j + 1];
                value_per_weight[j + 1] = temp;
                // Swap weights array
                int temp_weight = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp_weight;
                // Swap values array
                int temp_value = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp_value;
            }
        }
    }

    // Initialize variables to track current weight and total value
    int current_weight = 0;
    double total_value = 0.0;

    // Iterate through sorted items and select greedily
    printf("Selected items (weight, value):\n");
    for (i = 0; i < n; i++) {
        if (current_weight + weights[i] <= capacity) {
            printf("   Weight: %d, Value: %d\n", weights[i], values[i]);
            current_weight += weights[i];
            total_value += values[i];
        } else {
            // Calculate fraction of the item that can be taken
            double fraction = (double) (capacity - current_weight) / weights[i];
            printf("   Weight: %d (fraction %.2lf), Value: %.2lf\n", capacity - current_weight, fraction, fraction * values[i]);
            total_value += fraction * values[i];
            break;
        }
    }

    // Print the maximum value achievable
    printf("Maximum value achievable: %.2lf\n", total_value);
}

int main() {
    int capacity = 50;
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int n = sizeof(weights) / sizeof(weights[0]);

    // Call the knapsack_greedy function
    knapsack_greedy(capacity, weights, values, n);

    return 0;
}

