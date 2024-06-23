#include <stdio.h>

#define ROW 3
#define COL 3

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    else if (b < c) return b;
    else return c;
}

// Function to find the minimum cost path in a grid
int minCostPath(int cost[ROW][COL]) {
    int dp[ROW][COL]; // Create a 2D array to store minimum costs

    // Initialize the first cell of dp array
    dp[0][0] = cost[0][0];

    // Initialize first row of dp array
    int i,j;
    for (i = 1; i < COL; i++) {
        dp[0][i] = dp[0][i - 1] + cost[0][i];
    }

    // Initialize first column of dp array
    for (i = 1; i < ROW; i++) {
        dp[i][0] = dp[i - 1][0] + cost[i][0];
    }

    // Build rest of the dp array
    for (i = 1; i < ROW; i++) {
        for (j = 1; j < COL; j++) {
            dp[i][j] = cost[i][j] + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }
    }

    // Return the minimum cost to reach the bottom-right corner
    return dp[ROW - 1][COL - 1];
}

int main() {
    int cost[ROW][COL] = {
        {1, 3, 5},
        {2, 1, 4},
        {3, 2, 0}
    };

    printf("Minimum cost to reach (2, 2) = %d\n", minCostPath(cost));

    return 0;
}

