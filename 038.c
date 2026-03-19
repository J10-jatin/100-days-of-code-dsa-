#include <stdio.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return front == -1;
}

int size()
{
    if(isEmpty()) return 0;
    return rear - front + 1;
}

void push_back(int x)
{
    if(isEmpty())
        front = rear = 0;
    else
        rear++;

    dq[rear] = x;
}

void push_front(int x)
{
    if(isEmpty())
        front = rear = 0;
    else
    {
        for(int i = rear; i >= front; i--)
            dq[i+1] = dq[i];
        rear++;
    }
    dq[front] = x;
}

void pop_front()
{
    if(isEmpty()) return;

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(isEmpty()) return;

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

int getFront()
{
    if(isEmpty()) return -1;
    return dq[front];
}

int getBack()
{
    if(isEmpty()) return -1;
    return dq[rear];
}

void clear()
{
    front = rear = -1;
}

void reverse()
{
    int i = front, j = rear;
    while(i < j)
    {
        int t = dq[i];
        dq[i] = dq[j];
        dq[j] = t;
        i++; j--;
    }
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    pop_back();
    reverse();

    for(int i = front; i <= rear; i++)
        printf("%d ", dq[i]);

    return 0;
}