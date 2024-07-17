#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100
#define MAX_MACHINES 2

// Structure to represent a job with ID, profit, and machine number
struct Job {
    int id;
    int profit;
    int machine;
};

// Function to compare two jobs based on their profit
int compareJobs(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

void scheduleJobs(struct Job jobs[], int n, int m) {
    // Sort jobs based on profit (in descending order)
    qsort(jobs, n, sizeof(struct Job), compareJobs);

    // Array to keep track of scheduled jobs for each machine
    int slots[MAX_MACHINES][MAX_JOBS];  // Maximum possible slots based on MAX_JOBS
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            slots[i][j] = -1;  // Initialize all slots as empty (-1 indicates empty)
        }
    }

    // Fill slots with jobs
    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        int machineIndex = jobs[i].machine - 1;  // Machine index starts from 0
        for (int j = 0; j < n; j++) {
            if (slots[machineIndex][j] == -1) {
                slots[machineIndex][j] = i;  // Assign job i to slot j
                if (jobs[i].profit > maxProfit) {
                    maxProfit = jobs[i].profit;
                }
                break;
            }
        }
    }

    // Display the optimal job sequence with maximum profit at each time
    printf(".no       job sequence    Max Profit\n");
    int printedPairs = 0; // Keep track of printed pairs
    for (int i = 0; i < n; i++) {
        int maxP = 0;
        int filledCount = 0;
        printf("%2d       ", printedPairs + 1);
        for (int j = 0; j < m; j++) {
            if (slots[j][i] != -1) {
                int jobIndex = slots[j][i];
                printf("j%d ", jobs[jobIndex].id);
                if (jobs[jobIndex].profit > maxP) {
                    maxP = jobs[jobIndex].profit;
                }
                filledCount++;
            }
        }
        if (filledCount == 2) { // Only print pairs with 2 jobs
            printf("                %d\n", maxP);
            printedPairs++;
        } else {
            break; // Skip incomplete pairs
        }

    }

    printf("\nMaximum Profit: %d\n", maxProfit);
}


int main() {
    struct Job jobs[MAX_JOBS] = {
        {1, 70, 1}, {2, 60, 2}, {3, 50, 1}, {4, 40, 1}, {5, 30, 2}, {6, 20, 2},{7,2,2}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Call the function to schedule jobs
    scheduleJobs(jobs, n, MAX_MACHINES);

    return 0;
}
