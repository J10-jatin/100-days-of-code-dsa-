#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];

// Min Heap Node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// Min Heap
typedef struct {
    int size;
    HeapNode heap[MAX];
} MinHeap;

// Swap function
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

// Extract min
HeapNode extractMin(MinHeap* h) {
    HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

// Insert into heap
void insertHeap(MinHeap* h, int vertex, int dist) {
    int i = h->size++;
    h->heap[i].vertex = vertex;
    h->heap[i].dist = dist;

    while (i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Dijkstra Algorithm
void dijkstra(int V, int src) {
    int dist[MAX];
    MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    insertHeap(&heap, src, 0);

    while (heap.size > 0) {
        HeapNode minNode = extractMin(&heap);
        int u = minNode.vertex;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main
int main() {
    int V = 5;

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(4, 1, 3);
    addEdge(4, 2, 9);
    addEdge(2, 3, 4);
    addEdge(3, 0, 7);
    addEdge(3, 2, 6);

    dijkstra(V, 0);

    return 0;
}