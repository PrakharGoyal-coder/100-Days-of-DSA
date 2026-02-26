/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct Node *insertAtEnd(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
    if(head==NULL)
    {
        return ptr;
    }
    struct Node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    return head;

}
struct Node *deleteByValue(struct Node *head,int key)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(head->data==key)
    {
        struct Node *ptr=head;
        head=head->next;
        free(ptr);
        return head;
    }

    struct Node *p=head;
    struct Node *q=head->next;
    while(q!=NULL && q->data!=key)
    {
        p=p->next;
        q=q->next;
    }
    if(q==NULL)
    {
        printf("Key not found");
        return head;
    }
    p->next=q->next;
    free(q);
    return head;
}
int main()
{
    struct Node *head=NULL;
    int n,value,key;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        head=insertAtEnd(head,value);

    }
    scanf("%d",&key);
    head=deleteByValue(head,key);
    linkedlistTraversal(head);
    return 0;
}
