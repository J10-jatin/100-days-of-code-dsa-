#include <stdio.h>

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], result[n];

    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    k = k % n;   // Handles cases where k > n

    // Rotate the array
    for(int i = 0; i < n; i++) {
        result[(i + k) % n] = arr[i];
    }

    printf("Rotated array:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
