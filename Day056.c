/*Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left,*right;
};

struct Node* newNode(int val)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=val;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int isMirror(struct Node* t1, struct Node* t2)
{
    if(t1==NULL && t2==NULL)
        return 1;

    if(t1==NULL || t2==NULL)
        return 0;

    if(t1->data!=t2->data)
        return 0;

    return isMirror(t1->left,t2->right) &&
           isMirror(t1->right,t2->left);
}

int isSymmetric(struct Node* root)
{
    return isMirror(root,root);
}

struct Node* buildTree(int arr[],int n)
{
    if(arr[0]==-1)
        return NULL;

    struct Node* root=newNode(arr[0]);

    struct Node* queue[100];
    int front=0,rear=0;

    queue[rear++]=root;

    int i=1;

    while(front<rear && i<n)
    {
        struct Node* temp=queue[front++];

        if(arr[i]!=-1)
        {
            temp->left=newNode(arr[i]);
            queue[rear++]=temp->left;
        }
        i++;

        if(i<n && arr[i]!=-1)
        {
            temp->right=newNode(arr[i]);
            queue[rear++]=temp->right;
        }
        i++;
    }

    return root;
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr,n);

    if(isSymmetric(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}