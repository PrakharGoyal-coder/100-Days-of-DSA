/*\Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specification
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createTree() {
    int val;
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;

    newNode->left = createTree();
    newNode->right = createTree();

    return newNode;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct Node* root;

    printf("Enter nodes (-1 for NULL): ");
    root = createTree();

    printf("Leaf Nodes = %d", countLeafNodes(root));

    return 0;
}