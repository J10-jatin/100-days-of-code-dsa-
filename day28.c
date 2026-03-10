#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    int n, value;
    struct node *head = NULL, *temp = NULL, *newNode;

    // Step 1: Input number of nodes
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);

    // Step 2: Create circular linked list
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

    // Make it circular by pointing last node to head
    temp->next = head;

    // Step 3: Traverse circular linked list
    printf("\nCircular Linked List elements:\n");

    temp = head;
    if(temp != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);  // Stop when we reach head again
    }

    printf("\n");

    return 0;
}