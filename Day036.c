/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct CircularQueue 
{
    struct Node *front;
    struct Node *rear;
    int size;
};

void enqueue(struct CircularQueue *q, int val) 
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;

    if (q->front==NULL) 
    {
        // Queue empty
        q->front=q->rear=newNode;
        q->rear->next=q->front; 
    }
    else 
    {
        q->rear->next=newNode;
        q->rear=newNode;
        q->rear->next=q->front; 
    }
    q->size++;
}

void dequeue(struct CircularQueue *q) 
{
    if(q->front==NULL) 
    {
        printf("Queue is empty\n");
        return;
    }
    q->front=q->front->next;
}


void display(struct CircularQueue *q,int n)
{
    if (q->front==NULL) 
    {
        return;
    }
    struct Node *temp=q->front;
    for(int i=0;i<n;i++)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() 
{
    int n,m,x;
    scanf("%d",&n);
    struct CircularQueue *q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->front=q->rear=NULL;
    q->size=0;
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&x);
        enqueue(q,x);
    }

    scanf("%d",&m);
    for (int i=0;i<m;i++) 
    {
        dequeue(q);
    }
    display(q,n);
    // Free all nodes
    if(q->front!=NULL)
    {
        struct Node *start=q->front;
        struct Node *curr=start->next;
        while(curr!=start)
        {
            struct Node *tmp=curr;
            curr=curr->next;
            free(tmp);
        }
        free(start);
    }
    free(q);

    return 0;
}