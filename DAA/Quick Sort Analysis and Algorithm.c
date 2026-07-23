/*
Sort a given set of elements using the Quick sort method and determine the time required to sort 
the elements. Repeat the experiment for different values of n, the number of elements in the list 
to be sorted. The elements can be read from a file or can be generated using the random number 
generator
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

int main() {
    int *a, n, i;
    clock_t start, end;
    double cpu_time;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    // Generate random numbers
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100000;
    }

    start = clock();

    quickSort(a, 0, n - 1);

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to sort %d elements = %f seconds\n", n, cpu_time);

    // Uncomment to display sorted elements
    /*
    printf("\nSorted Elements:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    */

    free(a);
    return 0;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1, j, temp;

    for (j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}
