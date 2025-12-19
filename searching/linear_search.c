// Time Complexity: O(n)
// Space Complexity: O(1)

#include <stdio.h>

int main() {
    int arr[] = {4, 2, 7, 1, 9};
    int key = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d", i);
            return 0;
        }
    }

    printf("Element not found");
    return 0;
}
