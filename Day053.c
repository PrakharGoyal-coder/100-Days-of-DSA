/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int column[200][20];
int count[200];

void vertical(struct Node* root, int hd){

    if(root==NULL)
        return;

    column[hd+100][count[hd+100]++] = root->data;

    vertical(root->left, hd-1);
    vertical(root->right, hd+1);
}

int main(){

    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->right->left = create(6);
    root->right->right = create(7);

    vertical(root,0);

    for(int i=0;i<200;i++){
        if(count[i]!=0){
            for(int j=0;j<count[i];j++)
                printf("%d ",column[i][j]);
            printf("\n");
        }
    }

    return 0;
}