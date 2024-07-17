#include <stdio.h>
#include <stdlib.h>

#define MAX 10005

int id[MAX], nodes, edges;

struct Edge {
    long long weight;
    int src, dest;
};

struct Edge edgesArr[MAX];

void initialize() {
    for (int i = 0; i < MAX; ++i) {
        id[i] = i;
    }
}

int root(int x) {
    while (id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y) {
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(struct Edge edgesArr[]) {
    int x, y;
    long long cost, minimumCost = 0;
    for (int i = 0; i < edges; ++i) {
        x = edgesArr[i].src;
        y = edgesArr[i].dest;
        cost = edgesArr[i].weight;
        if (root(x) != root(y)) {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main() {
    long long weight, minimumCost;

    initialize();

    scanf("%d %d", &nodes, &edges);

    for (int i = 0; i < edges; ++i) {
        scanf("%d %d %lld", &edgesArr[i].src, &edgesArr[i].dest, &edgesArr[i].weight);
    }

    // Sort the edges in ascending order based on weight
    for (int i = 0; i < edges - 1; ++i) {
        for (int j = 0; j < edges - i - 1; ++j) {
            if (edgesArr[j].weight > edgesArr[j + 1].weight) {
                struct Edge temp = edgesArr[j];
                edgesArr[j] = edgesArr[j + 1];
                edgesArr[j + 1] = temp;
            }
        }
    }

    minimumCost = kruskal(edgesArr);

    printf("%lld\n", minimumCost);

    return 0;
}
