#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

int main() {

    int n, value;

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode;

    // Step 1: Ask user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);

    // Step 2: Create doubly linked list
    for(int i = 0; i < n; i++) {

        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Step 3: Traverse and print list
    printf("\nDoubly Linked List (Forward Traversal):\n");

    temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return 0;
}