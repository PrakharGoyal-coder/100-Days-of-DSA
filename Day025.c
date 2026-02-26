/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
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
int countOccurences(struct Node *head,int key)
{
    int count=0;
    struct Node *p=head;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            count++;
        }
        p=p->next;
    }
    return count;
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
    int result=countOccurences(head,key);
    printf("%d",result);
    return 0;
}