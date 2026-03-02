/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int expo;
    struct node *next;
};
struct node* insertTerm(struct node *head,int coef,int expo)
{
    struct node* ptr=(struct node *)malloc(sizeof(struct node));
    ptr->coef=coef;
    ptr->expo=expo;
    ptr->next=NULL;
    if(head==NULL)
    {
        return ptr;
    }
    struct node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    return head;
}
void displayPolynomial(struct node *head)
{
    if(head==NULL)
    {
        printf("No term in polynomial");
        return;
    }
    struct node *temp=head;
    int first=1;
    while(temp!=NULL)
    {   if(first)
        {
            printf("%d",temp->coef);
            first=0;
        }
        else
        {
            if(temp->coef>=0)
            {
             printf("+%d",temp->coef);
            }
            else
            {
                printf("%d",temp->coef);
            }
        }
       if(temp->expo!=0)
        {
            if(temp->expo==1)
                printf("x");
            else
                printf("x^%d",temp->expo);
        }
        temp=temp->next;
    }

}
int main()
{
    int n;
    //printf("Enter the number of terms:");
    scanf("%d",&n);
    struct node* head=NULL;
    for(int i=0;i<n;i++)
    {
        int coef,expo;
        scanf("%d %d",&coef,&expo);
        head=insertTerm(head,coef,expo);
    }
    //printf("Displaying the polynomial:");
    displayPolynomial(head);
    return 0;
}