#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    int n, m, value;

    struct node *head1 = NULL, *head2 = NULL;
    struct node *temp1 = NULL, *temp2 = NULL;
    struct node *newNode;

    // -------- FIRST LINKED LIST --------
    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter %d sorted numbers:\n", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(head1 == NULL) {
            head1 = newNode;
            temp1 = newNode;
        } else {
            temp1->next = newNode;
            temp1 = newNode;
        }
    }

    // -------- SECOND LINKED LIST --------
    printf("Enter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter %d sorted numbers:\n", m);

    for(int i = 0; i < m; i++) {
        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(head2 == NULL) {
            head2 = newNode;
            temp2 = newNode;
        } else {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    // -------- MERGING THE TWO LISTS --------
    struct node *mergedHead = NULL, *mergedTemp = NULL;

    while(head1 != NULL && head2 != NULL) {

        if(head1->data <= head2->data) {
            newNode = head1;
            head1 = head1->next;
        } else {
            newNode = head2;
            head2 = head2->next;
        }

        if(mergedHead == NULL) {
            mergedHead = newNode;
            mergedTemp = newNode;
        } else {
            mergedTemp->next = newNode;
            mergedTemp = newNode;
        }
    }

    // Add remaining nodes
    if(head1 != NULL)
        mergedTemp->next = head1;

    if(head2 != NULL)
        mergedTemp->next = head2;

    // -------- PRINT RESULT --------
    printf("\nMerged Linked List:\n");

    struct node *temp = mergedHead;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return 0;
}