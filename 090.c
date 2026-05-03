#include <stdio.h>

// Function to find maximum element
int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to find sum of array
int getSum(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

// Check if possible to paint with given maxTime
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;

    for(int i = 0; i < n; i++) {
        if(currSum + arr[i] <= maxTime) {
            currSum += arr[i];
        } else {
            painters++;
            currSum = arr[i];

            if(painters > k)
                return 0;
        }
    }
    return 1;
}

// Main function to find minimum time
int minTime(int arr[], int n, int k) {
    int low = getMax(arr, n);
    int high = getSum(arr, n);
    int result = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1;  // increase time
        }
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));

    return 0;
}