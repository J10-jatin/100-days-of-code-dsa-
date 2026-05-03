#include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heap structure
typedef struct {
    int *arr;
    int size;
} MinHeap;

// Heapify up
void heapifyUp(MinHeap *heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->arr[parent] > heap->arr[index]) {
            swap(&heap->arr[parent], &heap->arr[index]);
            index = parent;
        } else break;
    }
}

// Heapify down
void heapifyDown(MinHeap *heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert into heap
void push(MinHeap *heap, int value) {
    heap->arr[heap->size++] = value;
    heapifyUp(heap, heap->size - 1);
}

// Remove min (top)
int pop(MinHeap *heap) {
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

// Get top
int top(MinHeap *heap) {
    return heap->arr[0];
}

// Comparator for qsort (sort by start time)
int compare(const void *a, const void *b) {
    int *m1 = (int *)a;
    int *m2 = (int *)b;
    return m1[0] - m2[0];
}

int minRooms(int meetings[][2], int n) {
    qsort(meetings, n, sizeof(meetings[0]), compare);

    MinHeap heap;
    heap.arr = (int *)malloc(n * sizeof(int));
    heap.size = 0;

    push(&heap, meetings[0][1]);

    for (int i = 1; i < n; i++) {
        if (meetings[i][0] >= top(&heap)) {
            pop(&heap); // reuse room
        }
        push(&heap, meetings[i][1]);
    }

    return heap.size;
}

int main() {
    int n;
    scanf("%d", &n);

    int meetings[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i][0], &meetings[i][1]);
    }

    printf("%d\n", minRooms(meetings, n));

    return 0;
}