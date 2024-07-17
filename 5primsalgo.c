#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 10005

bool marked[MAX];
int vertices, edges;
bool adj[MAX][MAX];
int weight[MAX][MAX];

long long prim(int start) {
    long long minimumCost = 0;

    // Initialize all edges to not connected
    for (int i = 1; i <= vertices; ++i) {
        for (int j = 1; j <= vertices; ++j) {
            adj[i][j] = false;
            weight[i][j] = INT_MAX;
        }
    }

    // Read edge information and update adjacency matrix
    for (int i = 0; i < edges; ++i) {
        int x, y;
        long long w;
        scanf("%d %d %lld", &x, &y, &w);
        adj[x][y] = adj[y][x] = true; // Mark the edge as connected
        weight[x][y] = weight[y][x] = w;
    }

    // Priority queue to store edges based on weight
    int parent[MAX];
    long long minWeight[MAX];

    for (int i = 1; i <= vertices; ++i) {
        minWeight[i] = INT_MAX;
        marked[i] = false;
    }

    minWeight[start] = 0; // Start with the given vertex
    parent[start] = -1;

    for (int i = 1; i <= vertices; ++i) {
        int u = -1;
        for (int v = 1; v <= vertices; ++v) {
            if (!marked[v] && (u == -1 || minWeight[v] < minWeight[u])) {
                u = v;
            }
        }

        marked[u] = true;
        minimumCost += minWeight[u];

        for (int v = 1; v <= vertices; ++v) {
            if (adj[u][v] && !marked[v] && weight[u][v] < minWeight[v]) {
                parent[v] = u;
                minWeight[v] = weight[u][v];
            }
        }
    }

    return minimumCost;
}

int main() {
    long long minimumCost;

    scanf("%d %d", &vertices, &edges);

    minimumCost = prim(1);

    printf("%lld\n", minimumCost);

    return 0;
}
