/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
void linkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}
struct Node *insertAtEnd(struct Node *head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
    if(head==NULL)
    {
        ptr->prev=NULL;
        return ptr;
    }
    struct Node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->prev=p;
    return head;

}
int main()
{
    struct Node *head=NULL;
    int n,value;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        head=insertAtEnd(head,value);

    }
    linkedListTraversal(head);
    return 0;

}