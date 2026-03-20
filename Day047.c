/*Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create new node
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find height
int height(struct Node* root) 
{
    // Base case
    if (root == NULL)
        return 0;

    // Find height of left and right subtree
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return max + 1
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// Main function
int main() 
{
    /*
        Example Tree:
              1
             / \
            2   3
           /
          4
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Height of Binary Tree = %d", height(root));

    return 0;
}