/*Problem: Find Intersection Point of Two Linked Lists -
 Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertAtEnd(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=NULL;
    if(head==NULL)
        return ptr;
    struct Node *p=head;
    while(p->next!=NULL)
        p=p->next;
    p->next=ptr;
    return head;
}
int getLength(struct Node *head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    return len;
}
struct Node* getIntersection(struct Node *head1,struct Node *head2)
{
    int len1=getLength(head1);
    int len2=getLength(head2);

    //Advance the longer list by difference in lengths
    int diff=abs(len1-len2);
    if(len1>len2)
    {
        for(int i=0;i<diff;i++)
        {
            head1=head1->next;

        }
    }
    else{
        for(int i=0;i<diff;i++)
            head2=head2->next;
    }
    while(head1 != NULL && head2 != NULL) {
        if(head1 == head2) 
            return head1;  // Compare node addresses
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}
int main()
{
    int n,m,data;
    struct Node *head1=NULL,*head2=NULL;
    //input first list 
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&data);
        head1=insertAtEnd(head1,data);
    }
    //inputting the second list
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&data);
        head2=insertAtEnd(head2,data);
    }
    //Making the second list intersect with the first
    //if there are common values
    
    struct Node *temp1=head1;
    struct Node *temp2=head2;
    struct Node *intersectionNode=NULL;
    //find first node in list1 that is also in list 2(by value)
    while(temp1!=NULL)
    {
        temp2=head2;
        while(temp2!=NULL)
        {
            if(temp1->data==temp2->data)
            {
                intersectionNode=temp1;
                break;
            }
            temp2=temp2->next;
        }
        if(intersectionNode!=NULL)
            break;
        temp1=temp1->next;
    }
    if(intersectionNode!=NULL)
        printf("%d\n",intersectionNode->data);
    else
        printf("No Intersection");
    return 0;
}