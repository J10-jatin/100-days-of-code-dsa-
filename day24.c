#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    int n, key, value;

    struct node *head = NULL, *temp = NULL, *newNode;

    // Create Linked List
    scanf("%d", &n);

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

    // Input key to delete
    scanf("%d", &key);

    struct node *current = head;
    struct node *previous = NULL;

    // Find and delete first occurrence
    while(current != NULL) {

        if(current->data == key) {

            if(previous == NULL) { // deleting first node
                head = current->next;
            } 
            else {
                previous->next = current->next;
            }

            free(current);
            break;
        }

        previous = current;
        current = current->next;
    }

    // Print updated list
    temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}