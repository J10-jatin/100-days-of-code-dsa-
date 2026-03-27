#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Queue node (for BFS)
struct QNode {
    struct Node* node;
    int hd;
};

// Create new tree node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    free(queue);
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct QNode queue[1000];
    int front = 0, rear = 0;

    // Store values for each HD
    int map[2000][100];   // map[hd][list]
    int count[2000] = {0};

    int offset = 1000; // to handle negative HD

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd + offset;

        map[hd][count[hd]++] = curr->val;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, temp.hd - 1};

        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, temp.hd + 1};
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}