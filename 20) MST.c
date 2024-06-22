#include <stdio.h>

#define MAX 100 // Maximum number of edges in the graph
#define INF 9999999

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int n, int edges[MAX][3], int E) {
    int mst[MAX][3]; // To store the resulting MST
    int i, j, u, v, w, count = 0;

    // Initialize parent array
    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Sort edges by weight using Bubble Sort
    for (i = 0; i < E - 1; i++) {
        for (j = 0; j < E - i - 1; j++) {
            if (edges[j][2] > edges[j + 1][2]) {
                int temp1 = edges[j][0];
                int temp2 = edges[j][1];
                int temp3 = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp1;
                edges[j + 1][1] = temp2;
                edges[j + 1][2] = temp3;
            }
        }
    }

    for (i = 0; i < E && count < n - 1; i++) {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            mst[count][0] = u;
            mst[count][1] = v;
            mst[count][2] = w;
            count++;
            unionSets(set_u, set_v);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < count; i++) {
        printf("Edge: (%d, %d) Weight: %d\n", mst[i][0], mst[i][1], mst[i][2]);
    }
}

int main() {
    int n, E, i;
    int edges[MAX][3];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (u v w) format:\n");
    for (i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
    }

    kruskal(n, edges, E);

    return 0;
}
