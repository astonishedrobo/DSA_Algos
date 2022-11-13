#include <stdio.h>
#include <stdlib.h>

// Node of an AVL tree
typedef struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

// Helper function to get the height of a node
int height(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Helper function to calculate the balance factor of a node
int balanceFactor(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Helper function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node with the given key value
Node *newNode(int data) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }
    
    node->data = data;
    node->height = 1;  
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Function to perform a right rotation on a subtree rooted at node y
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // perform rotation
    x->right = y;
    y->left = T2;

    // update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // return new root
    return x;
}

//Function to perform a left rotation on a subtree rooted at node x
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // perform rotation
    y->left = x;
    x->right = T2;

    //  update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // return new root
    return y;
}

//Function to insert a new key value into the AVL tree
Node *insert(Node *node, int key) {
    // Perform the normal BST insertion
    if (node == NULL) {
        return newNode(key);
    }
    if (key < node->data) {
        node->left = insert(node->left, key);
    } 
    else if (key > node->data) {
        node->right = insert(node->right, key);
    } 
    else {
    // Equal keys are not allowed in an AVL tree
        printf("Error: duplicate keys are not allowed\n");
        exit(1);
    }

    // Update the height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node to check whether
    // this node became unbalanced
    int balance = balanceFactor(node);

    // If the node is unbalanced, there are four cases:

    // Left Left Case
    if (balance > 1 && key < node->left->data) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->data) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}

//Function to search for a given key value in the AVL tree
Node *search(Node *node, int key) {
    if (node == NULL) {
        return NULL;
    }
    if (key == node->data) {
        return node;
    }
    if (key < node->data) {
        return search(node->left, key);
    }
    return search(node->right, key);
}

//Function to traverse the AVL tree in in-order and print the key values
void inOrder(Node *node) {
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

//Driver program to test above functions
int main() {
    Node *root = NULL;

    // insert some keys into the AVL tree from user input
    while (1) {
        int key;
        printf("Enter a key value to insert into the AVL tree (-1 to Stop): ");
        scanf("%d", &key);
        if (key == -1) {
            break;
        }
        root = insert(root, key);
    }

    //keys to insert: 10 20 30 40 50 25 15 5 35 45 55 60 65 70 75 80 85 90 95 100 -1

    // traverse the tree in-order and print the key values
    printf("\n\nIn-order traversal of the AVL tree: ");
    inOrder(root);
    printf("\n");


    // search for a key value in the tree
    int key;
    printf("\nEnter a key value to search for: ");
    scanf("%d", &key);

    Node *result = search(root, key);
    if (result != NULL) {
        printf("Found key value: %d\n", result->data);
    } 
    else {
        printf("Key value not found\n");
    }

    return 0;
}