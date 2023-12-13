#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node with given data
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform depth-first search (DFS) on a binary tree (preorder traversal)
void dfsTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    dfsTraversal(root->left);
    dfsTraversal(root->right);
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // DFS traversal
    printf("DFS Traversal (Preorder): ");
    dfsTraversal(root);
    printf("\n");

    return 0;
}
