#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minSum = abs(arr[0] + arr[1]);
    int num1 = arr[0], num2 = arr[1];

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if(abs(sum) < minSum) {
                minSum = abs(sum);
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    printf("Pair with sum closest to zero:\n");
    printf("%d %d", num1, num2);

    return 0;
}