#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

int path[V];        // To store the Hamiltonian Circuit
bool visited[V];    // To track visited vertices

// Function to check if the current vertex can be added to the Hamiltonian Circuit
bool isSafe(int v, int pos, int graph[V][V]) {
    if (!visited[v] && graph[path[pos - 1]][v]) {
        return true;
    }
    return false;
}

// Function to recursively find a Hamiltonian Circuit
bool hamiltonianCycleUtil(int graph[V][V], int pos) {
    if (pos == V) {
        // Check if there is an edge from the last included vertex to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }
	int v;
    for (v = 1; v < V; v++) {
        if (isSafe(v, pos, graph)) {
            path[pos] = v;
            visited[v] = true;

            if (hamiltonianCycleUtil(graph, pos + 1)) {
                return true;
            }

            // Backtrack
            visited[v] = false;
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find a Hamiltonian Circuit in the given graph
void hamiltonianCycle(int graph[V][V]) {
	int i;
    for (i = 0; i < V; i++) {
        visited[i] = false;
        path[i] = -1;
    }

    // Start from vertex 0 (assuming 0-based indexing)
    path[0] = 0;
    visited[0] = true;

    if (!hamiltonianCycleUtil(graph, 1)) {
        printf("Hamiltonian Circuit does not exist\n");
        return;
    }

    printf("Hamiltonian Circuit found: ");
    for (i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);  // Print the first vertex again to complete the cycle
}

int main() {
    // Example adjacency matrix of a graph (0-based indexing)
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}

