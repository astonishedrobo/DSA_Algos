#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

/*
    Algorithm:
        Initially the root is empty.
        If the root is empty, then we create a new node and assign the value of the array element to the data field of the node.
        If the root is not empty, then we compare the value of the array element with the data field of the root.
        If the array element is smaller than the data field of the root, then we recursively call the createBSTUtil function with the left subtree of the root.
        If the array element is greater than the data field of the root, then we recursively call the createBSTUtil function with the right subtree of the root.
        In the end we return the root.
*/
TreeNode* createBSTUtil(TreeNode* root, int* arr, int n, int counter) {
    if (counter >= n) return NULL;
    if (!root) {
        root = (TreeNode*) malloc(sizeof(TreeNode));
        root->data = arr[counter];
        root->left = NULL;
        root->right = NULL;
    }
    else {
        if (arr[counter] < root->data) {
            root->left = createBSTUtil(root->left, arr, n, counter);
        }
        else {
            root->right = createBSTUtil(root->right, arr, n, counter);
        }
    }
    return root;
}

TreeNode* createBST(int *arr, int n) {
    TreeNode* root = NULL;
    for(int i = 0; i < n; i++) {
        root = createBSTUtil(root, arr, n, i);
    }
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

//delete BST
void deleteBST(TreeNode* root) {
    if (!root) return;
    deleteBST(root->left);
    deleteBST(root->right);
    free(root);
}

int main(void) {
    
    int arr[] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 16, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    TreeNode* root = createBST(arr, n);

    //printing inorder traversal of BST
    printf("Inorder Travesal: ");
    inorder(root);
    printf("\n");

    //delete BST
    deleteBST(root);

    return 0;
}