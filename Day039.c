/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30
*/
#include <stdio.h>

#define MAX 1000

typedef struct 
{
    int arr[MAX];
    int size;
} MinHeap;


void swap(int *a, int *b) 
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

// Get parent,left child,right child indices
int parent(int i) { return (i - 1) / 2; }
int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }

// Insert a number into heap
void insert(MinHeap *heap, int key) 
{
    heap->arr[heap->size] = key;
    int i = heap->size;
    heap->size++;

    // Move the new element up until heap property is satisfied
    while (i != 0 && heap->arr[parent(i)] > heap->arr[i]) 
    {
        swap(&heap->arr[i], &heap->arr[parent(i)]);
        i = parent(i);
    }
}

// Heapify down to fix heap after removing min
void heapifyDown(MinHeap *heap, int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap->size && heap->arr[l] < heap->arr[smallest])
        smallest = l;
    if (r < heap->size && heap->arr[r] < heap->arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Remove and return minimum element
int extractMin(MinHeap *heap) 
{
    if (heap->size == 0) 
        return -1;  // Empty heap
    if (heap->size == 1) 
    {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);

    return root;
}

// Return minimum element without removing
int peek(MinHeap *heap) 
{
    if (heap->size == 0) return -1;
    return heap->arr[0];
}

int main() 
{
    int n;
    scanf("%d", &n);

    MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < n; i++) 
    {
        char op[20];
        scanf("%s", op);

        if (op[0] == 'i') 
        { // insert
            int val;
            scanf("%d", &val);
            insert(&heap, val);
        }
        else if (op[0] == 'e') 
        { // extractMin
            printf("%d\n", extractMin(&heap));
        } 
        else if (op[0] == 'p') 
        { // peek
            printf("%d\n", peek(&heap));
        }
    }

    return 0;
}