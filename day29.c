#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to count nodes
int countNodes(struct node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {

    int n, k, value;
    struct node *head = NULL, *temp = NULL, *newNode;

    // Step 1: Input linked list
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Step 2: Input rotation count
    printf("Enter k (number of places to rotate right): ");
    scanf("%d", &k);

    if(head == NULL || k == 0) {
        printf("\nLinked List after rotation:\n");
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        return 0;
    }

    int len = countNodes(head);
    k = k % len; // handle k > n

    if(k == 0) { // no rotation needed
        printf("\nLinked List after rotation:\n");
        temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        return 0;
    }

    // Step 3: Make list circular
    temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head; // connect last node to head

    // Step 4: Move to (n - k)th node
    int steps = len - k;
    temp = head;
    for(int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // Step 5: Update head and break circular link
    head = temp->next;
    temp->next = NULL;

    // Step 6: Print rotated list
    printf("\nLinked List after rotation:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}