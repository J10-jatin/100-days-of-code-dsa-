#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, x;
    struct node *head = NULL, *temp = NULL, *newNode;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}