#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct Node* LCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    // Read elements and build BST
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* ans = LCA(root, p, q);

    if (ans != NULL)
        printf("%d\n", ans->val);

    return 0;
}