/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *left, *right;
};

// create node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// build tree from level order
struct Node* buildTree(int arr[], int n) 
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    int j = 1;
    for (int i = 0; i < n && j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n)
                nodes[i]->left = nodes[j++];
            if (j < n)
                nodes[i]->right = nodes[j++];
        }
    }

    return nodes[0];
}

// LCA function
struct Node* findLCA(struct Node* root, int n1, int n2) 
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node* root = buildTree(arr, n);

    struct Node* lca = findLCA(root, a, b);

    if (lca)
        printf("%d\n", lca->data);

    return 0;
}