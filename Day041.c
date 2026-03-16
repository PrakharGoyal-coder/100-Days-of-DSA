/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Queue 
{
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() 
{
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

void enqueue(struct Queue* q,int value) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;

    if (q->rear==NULL) 
    {   // if Queue is empty
        q->front=newNode;
        q->rear=newNode;
    } 
    else 
    {
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

int dequeue(struct Queue* q) 
{
    if (q->front==NULL) 
    { // Queue is empty
        return -1;
    }

    struct Node* temp=q->front;
    int value=temp->data;
    q->front=q->front->next;

    if (q->front==NULL) 
    { // Queue became empty
        q->rear=NULL;
    }
    free(temp);
    return value;
}

int main() 
{
    int N;
    scanf("%d",&N);
    struct Queue* q = createQueue();
    for (int i = 0; i < N; i++) 
    {
        char operation[10];
        scanf("%s",operation);

        if (strcmp(operation,"enqueue")==0) 
        {
            int value;
            scanf("%d", &value);
            enqueue(q, value);
        } 
        else if(strcmp(operation, "dequeue")==0) 
        {
            int result=dequeue(q);
            printf("%d\n", result);
        }
    }
    return 0;
}