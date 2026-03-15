/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000  // max size of queue

typedef struct 
{
    int arr[MAX];
    int size;
} PriorityQueue;


void initQueue(PriorityQueue* q) 
{
    q->size=0;
}

// Insert element (unsorted array, O(n) delete for priority)
void insert(PriorityQueue* q, int x) 
{
    if (q->size>= MAX) return;  // avoid overflow
    q->arr[q->size++]=x;
}

// Delete element with highest priority (smallest value)
int deleteMin(PriorityQueue* q)
{
    if (q->size==0) return -1;

    int minIndex = 0;
    for (int i = 1; i < q->size; i++) {
        if (q->arr[i] < q->arr[minIndex])
            minIndex = i;
    }

    int minValue = q->arr[minIndex];

    // shift remaining elements
    for (int i=minIndex;i<q->size-1;i++) 
    {
        q->arr[i]=q->arr[i+1];
    }
    q->size--;
    return minValue;
}

// Peek element with highest priority (smallest value)
int peek(PriorityQueue* q) {
    if (q->size==0) 
        return -1;

    int minIndex=0;
    for (int i=1;i<q->size;i++) {
        if (q->arr[i]<q->arr[minIndex])
            minIndex=i;
    }
    return q->arr[minIndex];
}

int main() {
    int N;
    scanf("%d", &N);
    PriorityQueue q;
    initQueue(&q);

    for (int i = 0; i < N; i++) {
        char op[10];
        int x;
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(&q, x);
        } 
        else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin(&q));
        } 
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek(&q));
        }
    }

    return 0;
}