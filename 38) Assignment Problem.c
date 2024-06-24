#include <stdio.h>
#include <limits.h>

#define N 4  // Number of workers and tasks

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int assignment[N];  // To store the result

// Function to check if assigning a task to a worker is valid
int isValidAssignment(int worker, int task) {
    // Implement any constraints if needed
    // For the sake of simplicity, assuming all assignments are valid
    return 1;
}

// Backtracking function to find optimal assignment
void backtrack(int worker, int currentCost, int *bestCost) {
    if (worker == N) {
        if (currentCost < *bestCost) {
            *bestCost = currentCost;
            printf("Optimal Assignment: ");
			int i;
            for (i = 0; i < N; i++) {
                printf("(%d, %d) ", i, assignment[i]);
            }
            printf("\n");
        }
        return;
    }
	int task;
    for (task = 0; task < N; task++) {
        if (isValidAssignment(worker, task)) {
            assignment[worker] = task;
            currentCost += costMatrix[worker][task];
            
            if (currentCost < *bestCost) {
                backtrack(worker + 1, currentCost, bestCost);
            }
            
            currentCost -= costMatrix[worker][task];
            assignment[worker] = -1;  // Reset assignment
        }
    }
}

// Function to solve the Assignment Problem using Branch and Bound
void BranchAndBoundAssignmentProblem() {
    int bestCost = INT_MAX;
    backtrack(0, 0, &bestCost);
}

int main() {
    BranchAndBoundAssignmentProblem();
    return 0;
}

