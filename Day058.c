/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int preIndex=0;


struct node* createNode(int value)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

// find position of element in inorder
int findIndex(int inorder[],int start,int end,int value)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==value)
            return i;
    }
    return -1;
}

// build tree
struct node* buildTree(int preorder[],int inorder[],int start,int end)
{
    if(start>end)
        return NULL;

    int value=preorder[preIndex];
    preIndex++;

    struct node* root=createNode(value);

    int index = findIndex(inorder, start, end, value);

    root->left=buildTree(preorder,inorder,start,index-1);
    root->right=buildTree(preorder,inorder,index+1,end);

    return root;
}

// postorder traversal
void postorder(struct node* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n],inorder[n];

    printf("Enter preorder traversal:\n");
    for(int i=0; i<n;i++)
        scanf("%d",&preorder[i]);

    printf("Enter inorder traversal:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&inorder[i]);

    struct node* root = buildTree(preorder,inorder,0,n-1);

    printf("Postorder traversal:\n");
    postorder(root);

    return 0;
}