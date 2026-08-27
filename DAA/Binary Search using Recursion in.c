#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    // Base condition: element not found
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    // Element found
    if (arr[mid] == key)
        return mid;

    // Search in the right half
    if (arr[mid] < key)
        return binarySearch(arr, mid + 1, high, key);

    // Search in the left half
    return binarySearch(arr, low, mid - 1, key);
}

int main()
{
    int arr[100], n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Element not found.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}
// Recursion logic

// The important part is:

// if (arr[mid] < key)
//     return binarySearch(arr, mid + 1, high, key);
// else
//     return binarySearch(arr, low, mid - 1, key);

// Each recursive call reduces the search space to half, so:

// Time Complexity: O(log n)
// Space Complexity: O(log n) because of the recursive call stack.
// Condition: Array must be sorted.
