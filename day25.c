#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    int n, value, key, count = 0;

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode;

    // Step 1: Create Linked List
    printf("Enter number of nodes: ");
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
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Step 2: Input key to count
    printf("Enter the element to count: ");
    scanf("%d", &key);

    // Step 3: Traverse the list and count occurrences
    temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    // Step 4: Print result
    printf("\nThe element %d appears %d time(s) in the linked list.\n", key, count);

    return 0;
}