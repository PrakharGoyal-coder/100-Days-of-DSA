/*Tree
Question 1 - C Programming
Practice
Level Order Traversal
View Problem →
Question 2 - LeetCode
Medium
Binary Tree Level Order Traversal
Solve Problem →
Mark as Complete

🔒 Solutions unlock when Day 47 opens (Mar 19, 2026 at 07:00)
🔒 Day 47 Locked
Next challenge unlocks on
Thursday, March 19, 2026
at 07:00 Asia/Kolkata
21:27:49
Your Progress
44 / 46 Days
Day 45 - Question 1: Height of a Binary Tree
Close
Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3
*/
#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

// Function to calculate height
int height(struct Node* root) 
{
    if (root==NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = newNode(arr[0]);
    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        // left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        // right child
        if (i<n && arr[i]!=-1) 
        {
            curr->right=newNode(arr[i]);
            queue[rear++]=curr->right;
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
    for (int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    struct Node* root=buildTree(arr, n);

    printf("%d\n",height(root));

    return 0;
}