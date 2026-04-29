#include <stdio.h>
#include <stdlib.h>

// comparator for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// check if we can place k cows with at least 'dist' distance
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;          // first cow placed
    int lastPos = stalls[0];

    for(int i = 1; i < n; i++) {
        if(stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if(count == k) return 1;
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int stalls[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 0;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    // binary search on answer
    while(low <= high) {
        int mid = (low + high) / 2;

        if(canPlace(stalls, n, k, mid)) {
            ans = mid;      // valid, try bigger distance
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}