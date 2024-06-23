#include <stdio.h>

#define INF 99999
#define V 4 // Number of vertices in the graph

// Function to print the solution matrix
void printSolution(int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    int i,j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Floyd's Algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V]; // Output matrix where dist[i][j] will be the shortest distance from i to j

    // Initialize the solution matrix with the given graph
    int i,j,k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update dist[] using all vertices as intermediate points
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distances matrix
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, INF, 3, INF},
        {2, 0, INF, INF},
        {INF, 7, 0, 1},
        {6, INF, INF, 0}
    };

    floydWarshall(graph);

    return 0;
}

