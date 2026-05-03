#include <stdio.h>
#include <stdlib.h>

// Function to find maximum element
int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n) {
    int max = getMax(arr, n);

    int count[max + 1];
    int output[n];

    // Initialize count array
    for(int i = 0; i <= max; i++)
        count[i] = 0;

    // Frequency count
    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    // Prefix sum (cumulative count)
    for(int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build output array (RIGHT to LEFT for stability)
    for(int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back to original array
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    // Print sorted array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}