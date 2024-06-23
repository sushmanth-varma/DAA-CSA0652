#include <stdio.h>
#include <limits.h>

// Function to calculate the sum of probabilities from i to j
double sum(double prob[], int i, int j) {
    double s = 0;
    int k;
    for (k = i; k <= j; k++) {
        s += prob[k];
    }
    return s;
}

// Function to find the optimal binary search tree
void optimalBST(double keys[], double prob[], int n) {
    double cost[n][n]; // Cost of the optimal BST
    int root[n][n]; // Root of the optimal BST
	int i,L,r;
    // Initialize the cost for a single key
    for (i = 0; i < n; i++) {
        cost[i][i] = prob[i];
        root[i][i] = i;
    }

    // Calculate cost for chains of length 2 to n
    for (L = 2; L <= n; L++) {
        for (i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (r = i; r <= j; r++) {
                double c = ((r > i) ? cost[i][r - 1] : 0) +
                           ((r < j) ? cost[r + 1][j] : 0) +
                           sum(prob, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Cost of Optimal BST is %.6f\n", cost[0][n - 1]);

    // Function to print the OBST structure
    void printOBST(int root[n][n], int i, int j, int parent, char *relation) {
        if (i <= j) {
            int r = root[i][j];
            if (parent == -1) {
                printf("Root of the tree: %d\n", (int)keys[r]);
            } else {
                printf("%d is the %s child of %d\n", (int)keys[r], relation, (int)keys[parent]);
            }
            printOBST(root, i, r - 1, r, "left");
            printOBST(root, r + 1, j, r, "right");
        }
    }

    // Print the OBST structure
    printOBST(root, 0, n - 1, -1, "root");
}

int main() {
    double keys[] = {10, 20, 30, 40, 50};
    double prob[] = {0.1, 0.2, 0.4, 0.2, 0.1};
    int n = sizeof(keys) / sizeof(keys[0]);

    optimalBST(keys, prob, n);

    return 0;
}

