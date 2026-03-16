/*
Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4 2 5 1 6 3 7
1 2 4 5 3 6 7
4 5 2 6 7 3 1
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inorder(struct Node* root)
{
    if(root==NULL) return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct Node* root)
{
    if(root==NULL) 
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root)
{
    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){

    int n;
    scanf("%d",&n);

    int arr[n];
    struct Node* node[n];

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    // create nodes
    for(int i=0;i<n;i++){
        if(arr[i]==-1)
            node[i]=NULL;
        else
            node[i]=create(arr[i]);
    }

    // connect nodes
    for(int i=0;i<n;i++){
        if(node[i]!=NULL){

            if(2*i+1<n)
                node[i]->left=node[2*i+1];

            if(2*i+2<n)
                node[i]->right=node[2*i+2];
        }
    }
    struct Node* root=node[0];
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}