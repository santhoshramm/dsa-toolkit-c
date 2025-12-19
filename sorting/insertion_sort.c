// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <stdio.h>

int main() {
    int arr[] = {8, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
