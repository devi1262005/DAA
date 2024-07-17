#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for Item which stores weight and corresponding value
struct Item {
    float weight;
    int value;
};

// Node structure to store information of decision tree
struct Node {
    int level, profit, bound;
    float weight;
};

// Comparison function to sort Item according to val/weight ratio
int cmp(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    double r1 = (double)itemA->value / itemA->weight;
    double r2 = (double)itemB->value / itemB->weight;
    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

// Returns bound of profit in subtree rooted with u
int bound(struct Node u, int n, int W, struct Item arr[]) {
    if (u.weight >= W)
        return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    float totweight = u.weight;

    while ((j < n) && (totweight + arr[j].weight <= W)) {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n)
        profit_bound += (W - totweight) * arr[j].value / arr[j].weight;

    return profit_bound;
}

// Returns maximum profit we can get with capacity W
int knapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), cmp);
    struct Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    int maxProfit = 0;

    int Qsize = 10000;  // Adjust this according to your needs
    struct Node Q[Qsize];
    int front = -1, rear = 0;
    Q[rear] = u;

    while (front < rear) {
        u = Q[++front];

        if (u.level == -1)
            v.level = 0;
        else if (u.level == n - 1)
            continue;
        else
            v.level = u.level + 1;

        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit)
            Q[++rear] = v;

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit)
            Q[++rear] = v;
    }

    return maxProfit;
}

int main() {
    int W = 10; // Weight of knapsack
    struct Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100}, {5, 95}, {3, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum possible profit = %d\n", knapsack(W, arr, n));
    return 0;
}
