#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x){
    struct Node* temp = malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if(rear == NULL){
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

int dequeue(){
    if(front == NULL) return -1;

    struct Node* temp = front;
    int val = temp->data;

    front = front->next;
    if(front == NULL) rear = NULL;

    free(temp);
    return val;
}

int main(){
    int N;
    scanf("%d",&N);

    int *stack = malloc(N * sizeof(int));
    int top = -1;

    for(int i=0;i<N;i++){
        int x;
        scanf("%d",&x);
        enqueue(x);
    }

    // queue → stack
    while(front != NULL)
        stack[++top] = dequeue();

    // stack → queue
    while(top != -1)
        enqueue(stack[top--]);

    // print reversed queue
    while(front != NULL)
        printf("%d ", dequeue());

    free(stack);
    return 0;
}