#include <stdio.h>

void findMinMax(int arr[], int low, int high, int *min, int *max) {
    int mid, min1, min2, max1, max2;
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    mid = (low + high) / 2;
    findMinMax(arr, low, mid, &min1, &max1);
    findMinMax(arr, mid + 1, high, &min2, &max2);

    *min = (min1 < min2) ? min1 : min2;

    *max = (max1 > max2) ? max1 : max2;
}

int main() {
    int arr[10], n, i, min, max;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("The minimum element is: %d\n", min);
    printf("The maximum element is: %d\n", max);

    return 0;
}
