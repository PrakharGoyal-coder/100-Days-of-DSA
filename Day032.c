/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10
*/

#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr,int val)
{
    if(isFull(ptr))
    {
       return;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
void pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow!Cannot pop from the stack");
        return ;
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        //printf("%d\n",val);
        
    }
}
void display(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("\n");
        return;
    }
    for(int i=ptr->top;i>=0;i--)
    {
        printf("%d ",ptr->arr[i]);
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=n;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    for(int i=0;i<n;i++)
    {   int val;
        scanf("%d",&val);
        push(sp,val);
    }
    int count=0;
    scanf("%d",&count);
    for(int i=1;i<=count;i++)
    {pop(sp);
    }
    display(sp);
    free(sp->arr);
    free(sp);
    return 0;
}