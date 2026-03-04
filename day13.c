#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int a[r][c];

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while(top <= bottom && left <= right) {

        // top row
        for(int j = left; j <= right; j++)
            printf("%d ", a[top][j]);
        top++;

        // right column
        for(int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;

        // bottom row
        if(top <= bottom){
            for(int j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);
            bottom--;
        }

        // left column
        if(left <= right){
            for(int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }

    return 0;
}