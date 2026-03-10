#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to count nodes in a list
int countNodes(struct node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {

    int n, m, value;

    struct node *head1 = NULL, *head2 = NULL;
    struct node *temp = NULL, *newNode;

    // ----- Create First Linked List -----
    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter %d numbers for first list:\n", n);

    for(int i = 0; i < n; i++) {

        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(head1 == NULL) {
            head1 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // ----- Create Second Linked List -----
    printf("\nEnter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter %d numbers for second list:\n", m);

    for(int i = 0; i < m; i++) {

        scanf("%d", &value);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(head2 == NULL) {
            head2 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // ----- Find lengths of both lists -----
    int len1 = countNodes(head1);
    int len2 = countNodes(head2);

    struct node *p1 = head1;
    struct node *p2 = head2;

    int diff = abs(len1 - len2);

    // Move pointer in longer list
    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            p1 = p1->next;
    } else {
        for(int i = 0; i < diff; i++)
            p2 = p2->next;
    }

    // Traverse both lists together
    while(p1 != NULL && p2 != NULL) {

        if(p1->data == p2->data) {
            printf("\nIntersection found at node value: %d\n", p1->data);
            return 0;
        }

        p1 = p1->next;
        p2 = p2->next;
    }

    printf("\nNo Intersection\n");

    return 0;
}