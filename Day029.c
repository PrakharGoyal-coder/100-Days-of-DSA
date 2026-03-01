/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
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

}
//Rotate right by k places
struct Node *rotateRight(struct Node *head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    struct Node *last=head;
    int count=1;
    //counting numn=ber of nodes
    while(last->next!=NULL)
    {
        last=last->next;
        count++;
    }
    //mkaing it circular LL
    last->next=head;
    k=k%count;
    int move=count-k;
    struct Node* newTail=head;
    for(int i=0;i<move;i++)
    {
        newTail=newTail->next;
    }
    struct Node *newHead=newTail->next;
    //break circle
    newTail->next=NULL;
    return newHead;
}
int main()
{
    int n,value;
    struct Node *head=NULL;
    struct Node *temp=NULL;
    struct Node *newNode;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }
    int k;
    printf("Enter k:");
    scanf("%d",&k);
    head=rotateRight(head,k);
    printf("List after rotation:\n");
    linkedlistTraversal(head);
    return 0;
}
