/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.
*/
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if(q->rear==q->front)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *q)
{
    if(q->rear==q->size-1)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int val)
{
    if(isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear]=val;
    }
}
int main()
{
    int n,x;
    scanf("%d",&n);
    struct queue q;
    q.size=n;
    q.front=q.rear=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(&q,x);
    }
        while(!isEmpty(&q))
        {
            q.front++;
            printf("%d ",q.arr[q.front]);

        }
        return 0;
    
}
