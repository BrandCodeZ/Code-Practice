#include <stdio.h>
// How Binary Search works

// For [10, 20, 30, 40, 50] searching for 40:

// mid = 30 → 40 is greater → search right half.
// mid = 40 → element found.

// Time Complexity: O(log n)
// Space Complexity: O(1) for this iterative implementation.
int main() {
    int arr[100], n, key;
    int low, high, mid;
    int found = 0;

    // Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input sorted array
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Binary Search
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            printf("Element %d found at index %d.\n", key, mid);
            found = 1;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}

