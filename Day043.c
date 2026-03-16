/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)

Output Format:
- Print inorder traversal of the constructed tree

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
4 2 5 1 3 6
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inorder(struct Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    struct Node* node[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    // create nodes
    for(int i=0;i<n;i++)
    {
        if(arr[i]==-1)
            node[i]=NULL;
        else
            node[i]=newNode(arr[i]);
    }

    // connect nodes
    for(int i=0;i<n;i++)
    {
        if(node[i]!=NULL)
        {

            if(2*i+1<n)
                node[i]->left=node[2*i+1];

            if(2*i+2<n)
                node[i]->right=node[2*i+2];
        }
    }

    inorder(node[0]);

    return 0;
}