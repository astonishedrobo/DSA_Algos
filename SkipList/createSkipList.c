#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_LEVEL 6

// Node structure for a skip list node
typedef struct Node {
    int key;
    int value;
    struct Node *forward[MAX_LEVEL + 1];
} Node;

// Skip list structure
typedef struct SkipList {
    int level;
    int size;
    Node *head;
} SkipList;

// Create a new skip list node
Node *newNode(int level, int key, int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }
    node->key = key;
    node->value = value;
    for (int i = 0; i <= level; i++) {
        node->forward[i] = NULL;
    }
    return node;
}

// Create a new skip list
SkipList *newSkipList() {
    SkipList *list = malloc(sizeof(SkipList));
    if (list == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }
    list->level = 0;
    list->size = 0;
    list->head = newNode(MAX_LEVEL, INT_MIN, INT_MIN);
    return list;
}

// Generate a random level for a new node
int randomLevel() {
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

// Insert a new key-value pair into the skip list
void insert(SkipList *list, int key, int value) {
    Node *update[MAX_LEVEL + 1];
    Node *current = list->head;

    // find the position to insert the new node
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];

    // if the key already exists, just update the value
    if (current != NULL && current->key == key) {
        current->value = value;
        return;
    }

    // generate a random level for the new node
    int level = randomLevel();

    // if the new node's level is greater than the skip list's level,
    // update the list's level and the update array
    if (level > list->level) {
        for (int i = list->level + 1; i <= level; i++) {
            update[i] = list->head;
        }
        list->level = level;
    }

    // create the new node
    Node *node = newNode(level, key, value);

    // insert the new node into the skip list
    for (int i = 0; i <= level; i++) {
        node->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = node;
    }
    list->size++;
}

// Search for a key in the skip list and return its value
int search(SkipList *list, int key) {
    Node *current = list->head;
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    if (current != NULL && current->key == key) {
        return current->value;
    }
    return INT_MIN;
}

// Remove a key from the skip list
void removeKey(SkipList *list, int key) {
    Node *update[MAX_LEVEL + 1];
    Node *current = list->head;

    // find the position of the key to be removed
    for (int i = list->level; i >= 0; i--) {
        while (current->forward[i] != NULL && current->forward[i]->key < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];

    // if the key does not exist, do nothing
    if (current == NULL || current->key != key) {
        return;
    }

    // remove the key from the skip list
    for (int i = 0; i <= list->level; i++) {
        if (update[i]->forward[i] != current) {
            break;
        }
        update[i]->forward[i] = current->forward[i];
    }
    free(current);

    // decrease the level of the skip list if necessary
    while (list->level > 0 && list->head->forward[list->level] == NULL) {
        list->level--;
    }
    list->size--;
}

// Get the size of the skip list
int size(SkipList *list) {
    return list->size;
}

// Check whether the skip list is empty
int isEmpty(SkipList *list) {
    return size(list) == 0;
}

// deleteSkipL the skip list
void deleteSkipL(SkipList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->forward[0];
        free(current);
        current = next;
    }
    free(list);
}

// Driver program to test above functions
int main() {
    srand(time(NULL));

    SkipList *list = newSkipList();

    // insert some values into the skip list
    insert(list, 1, 10);
    insert(list, 2, 20);
    insert(list, 3, 30);
    insert(list, 4, 40);
    insert(list, 5, 50);
    insert(list, 6, 60);

    // search for a key and print its value
    int key = 5;
    int value = search(list, key);
    if (value != INT_MIN) {
        printf("Key %d has value %d\n", key, value);
    } else {
        printf("Key %d not found\n", key);
    }

    // remove a key
    printf("Removing key %d\n", key);
    removeKey(list, 5);

    // check if the key is still in the skip list
    value = search(list, key);
    if (value != INT_MIN) {
        printf("Key %d has value %d\n", key, value);
    } else {
        printf("Key %d not found\n", key);
    }

    deleteSkipL(list);

    return 0;
}

