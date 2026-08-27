#include<stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int i, int j) {
    struct MinMax result, left, right;

    // Base case: Only one element
    if (i == j) {
        result.min = arr[i];
        result.max = arr[i];
        return result;
    }

    // Base case: Two elements
    if (j == i + 1) {
        if (arr[i] < arr[j]) {
            result.min = arr[i];
            result.max = arr[j];
        } else {
            result.min = arr[j];
            result.max = arr[i];
        }

        return result;
    }

    // Divide the array into two halves
    int mid = (i + j) / 2;

    // Conquer: Find min and max in both halves
    left = findMinMax(arr, i, mid);
    right = findMinMax(arr, mid + 1, j);

    // Combine the results
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n, a;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);

    for (a = 0; a < n; a++) {
        scanf("%d", &arr[a]);
    }

    struct MinMax answer = findMinMax(arr, 0, n - 1);

    printf("\nMinimum element = %d\n", answer.min);
    printf("Maximum element = %d\n", answer.max);

    return 0;
}