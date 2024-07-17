#include <stdio.h>

int main() {
    int i, n, c, j;
    float p[20], w[20], t, max = 0, r[20];

    printf("Enter the maximum capacity: ");
    scanf("%d", &c);

    printf("\nEnter the number of items: ");
    scanf("%d", &n);

    printf("\nEnter profit and weight for each item:\n");
    for (i = 1; i <= n; i++) {
        scanf("%f%f", &p[i], &w[i]);
    }

    printf("\nProfit\tWeight\tRatio\n");
    for (i = 1; i <= n; i++) {
        r[i] = p[i] / w[i];
        printf("%.2f\t%.2f\t%.2f\n", p[i], w[i], r[i]);
    }

    printf("\nSorted list is:\n");
    printf("Profit\tWeight\tRatio\n");
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (r[j] > r[i]) {
                t = r[j];
                r[j] = r[i];
                r[i] = t;

                t = w[j];
                w[j] = w[i];
                w[i] = t;

                t = p[j];
                p[j] = p[i];
                p[i] = t;
            }
        }
        printf("%.2f\t%.2f\t%.2f\n", p[i], w[i], r[i]);
    }

    for (i = 1; i <= n; i++) {
        if (w[i] <= c) {
            max = p[i] + max;
        } else if (c >= 0) {
            p[i] = c / w[i] * p[i];
            max = max + p[i];
        } else {
            break;
            c = c - w[i];
        }
    }

    printf("\nMax profit is: %.2f\n", max);

    return 0;
}
