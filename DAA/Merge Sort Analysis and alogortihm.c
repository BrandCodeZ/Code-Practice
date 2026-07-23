/*
Implement a Merge Sort algorithm to sort a given set of elements and determine the time 
required to sort the elements. Repeat the experiment for different values of n, the number of 
elements in the list to be sorted .The elements can be read from a file or can be generated using 
the random number generator.

~sudhanshu sahu 
*/

#include <stdio.h>
#include <time.h>

#define MAX 100000

void merge(int a[], int low, int mid, int high) {
    int temp[MAX];
    int i = low;
    int j = mid + 1;
    int k = low;

    // Compare and merge elements
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // Copy remaining elements of left half
    while (i <= mid)
        temp[k++] = a[i++];

    // Copy remaining elements of right half
    while (j <= high)
        temp[k++] = a[j++];

    // Copy sorted elements back to original array
    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main() {
    int a[MAX];
    int n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Start measuring time
    start = clock();

    mergeSort(a, 0, n - 1);

    // Stop measuring time
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Elements:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nTime required to sort %d elements = %f seconds\n",
           n, time_taken);

    return 0;
}