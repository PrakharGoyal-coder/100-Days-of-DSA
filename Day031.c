/*Problem: Implement a stack data structure using an array with the following operations: 
push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10
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
        printf("%d\n",val);
        
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
        printf("%d\n",ptr->arr[i]);
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
    {
        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            int value;
            scanf("%d",&value);
            push(sp,value);
        }
        else if(choice==2)
        {
            pop(sp);
        }
        else if(choice==3)
        {
            display(sp);
        }

    }
    free(sp->arr);
    free(sp);
    return 0;
}