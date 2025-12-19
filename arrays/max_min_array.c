// Time Complexity: O(n)
// Space Complexity: O(1)

#include <stdio.h>

int main() {
    int arr[] = {4, 7, 1, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0], min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    printf("Max: %d\nMin: %d", max, min);
    return 0;
}
