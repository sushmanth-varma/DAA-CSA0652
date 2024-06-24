#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices in the graph

// Function to print the solution
void printSolution(int color[]) {
    printf("Solution Exists: Following are the assigned colors:\n");
    int i;
    for (i = 0; i < V; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);
}

// Utility function to check if the current color assignment is safe for vertex v
bool isSafe(int v, bool graph[V][V], int color[], int c) {
	int i;
    for (i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

// A recursive utility function to solve the graph coloring problem
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;
	int c;
    for (c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0; // Backtrack
        }
    }

    return false;
}

// Function to solve the graph coloring problem
void graphColoring(bool graph[V][V], int m) {
    int color[V] = {0};
    if (graphColoringUtil(graph, m, color, 0))
        printSolution(color);
    else
        printf("Solution does not exist\n");
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors

    graphColoring(graph, m);
    return 0;
}

