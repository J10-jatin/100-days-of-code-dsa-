#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue implementation
struct Node* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    // Reset queue
    front = rear = 0;

    enqueue(root);
    int leftToRight = 1;

    while (!isEmpty()) {
        int size = rear - front;
        int level[MAX];

        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue();

            int index;
            if (leftToRight)
                index = i;
            else
                index = size - 1 - i;

            level[index] = node->data;

            if (node->left) enqueue(node->left);
            if (node->right) enqueue(node->right);
        }

        // Print level
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight; // flip direction
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}