// Time Complexity: O(log n)
// Space Complexity: O(1)

#include <stdio.h>

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int key = 5, low = 0;
    int high = sizeof(arr) / sizeof(arr[0]) - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Found at index %d", mid);
            return 0;
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Not found");
    return 0;
}
