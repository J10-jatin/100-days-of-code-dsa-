#include <stdio.h>
#include <stdlib.h>

// Comparator to sort by start time
int compare(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    return x[0] - y[0];
}

int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int intervals[n][2];

    printf("Enter intervals (start end) each on new line:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    // Sort intervals by start time
    qsort(intervals, n, sizeof(intervals[0]), compare);

    printf("Merged intervals:\n");

    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= end) {
            // Overlapping → merge
            if (intervals[i][1] > end)
                end = intervals[i][1];
        } else {
            // No overlap → print previous
            printf("%d %d\n", start, end);
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // Print last interval
    printf("%d %d\n", start, end);

    return 0;
}