#include <stdio.h>

int main() {
    int p, q;

    scanf("%d", &p);
    int a[p];

    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);
    int b[q];

    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    // merge arrays
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // remaining elements of first array
    while(i < p) {
        printf("%d ", a[i]);
        i++;
    }

    // remaining elements of second array
    while(j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}