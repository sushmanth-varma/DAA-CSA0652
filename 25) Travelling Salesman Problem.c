#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices (cities)

int tsp(int graph[][V], int mask, int pos, int n) {
    if (mask == (1 << n) - 1) { // Base case: All cities visited
        return graph[pos][0];   // Return to the starting city
    }

    int minCost = INT_MAX;

    // Try all cities as the next city to visit
    int city;
    for (city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // If city 'city' is not visited
            int newCost = graph[pos][city] + tsp(graph, mask | (1 << city), city, n);
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    return minCost;
}

int main() {
    // Example graph of the TSP problem (complete graph)
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Start TSP from the first city (0th index), with no cities visited (mask = 1)
    int minCost = tsp(graph, 1, 0, V);

    // Output the minimum cost Hamiltonian cycle
    printf("Minimum cost of the TSP: %d\n", minCost);

    return 0;
}

